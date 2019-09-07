/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:47:51 by kbatz             #+#    #+#             */
/*   Updated: 2019/09/07 16:37:53 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	i_counter(long long int n, char *nbr, t_format f)
{
	char	*str;
	int		len;

	if (f.zero)
		f.space = 0;
	f.zero = (f.precision != -1) ? (0) : (f.zero);
	len = ft_strlen(nbr) - 1;
	if (n == 0 && f.precision == 0)
		len = f.precision;
	f.precision -= len;
	if (f.precision < 0)
		f.precision = 0;
	f.width -= f.precision + len + f.plus;
	if (f.width < 0)
		f.width = 0;
	str = malloc((f.width + f.precision + len + f.plus) * sizeof(*str));
	if (!str)
		exit(1);
	ft_intfill(str, nbr, f, len);
	write(1, str, f.width + f.precision + len + f.plus);
	free(str);
	free(nbr);
	return (f.width + f.precision + len + f.plus);
}

int			f_i(va_list ap, t_format f)
{
	long long int	n;
	char			*nbr;

	if (f.type == FT_HH)
		n = va_arg(ap, char);
	else if (f.type == FT_H)
		n = va_arg(ap, short int);
	else if (f.type == FT_L)
		n = va_arg(ap, long int);
	else if (f.type == FT_LL)
		n = va_arg(ap, long long int);
	else
		n = va_arg(ap, int);
	if (f.minus)
		f.zero = 0;
	if (n < 0)
		f.plus = 1;
	nbr = ft_ultra_itoa(n, 10, 1, "0123456789");
	if (!f.plus && f.space)
	{
		f.plus = 1;
		*nbr = ' ';
	}
	return (i_counter(n, nbr, f));
}
