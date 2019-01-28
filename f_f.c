/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:33:54 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/28 21:14:24 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_flen(unsigned long long int a, int p)
{
	size_t	i;

	p = p > 0 ? p : 0;
	i = -1;
	while (++i < 53 - p)
	{
		if (a & (1 << i))
			break;
	}
	return (53 - p - i);
}

char	*get_str(unsigned long long int a, int p, size_t n, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_memalloc(p);
	i = -1;
	while (++i < n)
	{
		j = len + 1;
		while (--j > 0)
		{
			buf = (str[j] - '0') / 10;
			str[j] -= buf * 10;
			str[j - 1] += buf;
		}
		j = len + 1;
		while (--j > 0)
			str[j] *= p;
		str[0] *= p
	}
	return (str);
}

char	*f_f(va_list ap)
{
	double					a;
	char					*str;
	char					*str_d;
	char					*str_f;
	int						p;
	unsigned long long int	d;
	unsigned long long int	f;
	char					sign;
	size_t					len_d;
	size_t					len_f;
	size_t					len;

	len = 0;
	a = va_arg(ap, double);
	//printf("%.0f =\t", a);
	//print_bits(&a, 8);
	d = *(long long int *)&a;
	p = (d & 0x7ff0000000000000) - 1023;
	sign = d & 0x8000000000000000;
	d &= 0x000fffffffffffff;
	d |= 0x0010000000000000;
	if (sign)
		d = (~d) + 1;
	if (p < 0)
	{
		f = d;
		d = 0;
	}
	else if (p < 52)
	{
		f = d & (0x001fffffffffffff >> p);
		d >>= (52 - p);
	}
	else
		f = 0;
	len = count_flen(f, p);
	len_f = len - (p < 0 ? p : 0);
	p = p > 0 ? p : 0;
	len_d = (p + len) * 0.30103;
	len = len_f + len_d + 1 + sign;
	str_d = get_str(d, 2, p, len_d);
	str_f = get_str(f, 5, len_f, len_f);
	return (0);
}
