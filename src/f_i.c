/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:47:51 by kbatz             #+#    #+#             */
/*   Updated: 2019/08/04 17:06:39 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	i_counter(unsigned long long int n, char *nbr, int len, t_format f)
{
	char	*str;

	if (n == 0 && f.precision == 0)
		len = f.precision;
	f.precision -= len;
	if (f.precision < 0)
		f.precision = 0;
	f.width -= f.precision + len + f.plus;
	if (f.width < 0)
		f.width = 0;
	if (f.space && !f.plus && f.width < 1)
		f.width = 1;
	str = malloc((f.width + f.precision + len + f.plus + 1) * sizeof(*str));
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
	int				len;

	n = va_arg(ap, long long int);
	if (f.type == FT_HH)
		n = (char)n;
	else if (f.type == FT_H)
		n = (short int)n;
	else if (f.type == FT_L)
		n = (long int)n;
	else if (f.type == FT_LL)
		n = (long long int)n;
	else
		n = (int)n;
	if (f.minus)
		f.zero = 0;
	if (f.zero)
		f.space = 0;
	if (n < 0)
		f.plus = 1;
	f.zero = (f.precision != -1) ? (0) : (f.zero);
	nbr = ft_ultra_itoa(n, 10, 1, "0123456789");
	len = ft_strlen(nbr) - 1;
	return (i_counter(n, nbr, len, f));
}
