/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:54:56 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/04 20:27:59 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			float_strlen(char *nbr)
{
	int		i;

	i = 0;
	while (nbr[i] != '.')
		++i;
	return (i);
}

void		ft_floatfill(char *str, char *nbr, t_format f, int len)
{
	int		i;

	i = -1;
	if (!f.zero && !f.minus)
		while (++i < f.width)
			*str++ = ' ';
	if (f.plus)
		*str++ = *nbr;
	i = -1;
	if (f.zero)
		while (++i < f.width)
			*str++ = '0';
	i = -1;
	while (++i < len)
		*str++ = *++nbr;
	i = -1;
	while (*++nbr && ++i < f.precision)
		*str++ = *nbr;
	while (++i < f.precision)
		*str++ = '0';
	i = -1;
	if (!f.zero && f.minus)
		while (++i < f.width)
			*str++ = ' ';
}

static int	f_counter(char *nbr, int len, t_format f)
{
	char	*str;

	f.width -= len + f.plus + f.precision;
	if (f.width < 0)
		f.width = 0;
	str = malloc((f.plus + f.width + len + f.precision) * sizeof(*str));
	if (!str)
		exit(1);
	ft_floatfill(str, nbr, f, len);
	write(1, str, f.plus + f.width + len + f.precision);
	free(str);
	free(nbr);
	return (f.plus + f.width + len + f.precision);
}

int			f_f(va_list ap, t_format f)
{
	double	n;
	char	*nbr;
	int		len;

	n = va_arg(ap, double);
	nbr = apa_float(n);
	if (f.minus)
		f.zero = 0;
	if (f.precision == -1)
		f.precision = 6;
	if (f.precision)
		++f.precision;
	if (n < 0)
		f.plus = 1;
	if (!f.plus && f.space)
	{
		f.plus = 1;
		*nbr = ' ';
	}
	if (f.zero)
		f.space = 0;
	len = float_strlen(nbr) - 1;
	return (f_counter(nbr, len, f));
}
