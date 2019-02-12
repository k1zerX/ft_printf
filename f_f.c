/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:33:54 by kbatz             #+#    #+#             */
/*   Updated: 2019/02/12 21:10:18 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len(unsigned long long int a)
{
	int		i;

	i = -1;
	while (1)
		if (a & (1 << ++i))
			return (53 - i);
	return (0);
}

void	ft_mul(char *str, size_t len, int a)
{
	int		prev;
	int		buf;
	size_t	j;

	buf = 0;
	j = len;
	while (--j > 0)
	{
		str[j] = str[j] * a + buf;
		buf = (str[j] - '0') / 10;
		str[j] -= buf * 10;
	}
}

/* ispravit' dliny i zaranee perevesti mantisu v strokovoe chislo */

void	get_f(unsigned long long int a, char *str, size_t len, int p)
{
	while (p++ < 0)
		ft_mul(str, len, 5);
}

void	get_i(unsigned long long int a, char *str, size_t len, int p)
{
	while (p-- > 0)
		ft_mul(str, len, 2);
}

char	*f_f(va_list ap)
{
	double					a;
	char					*str;
	int						p;
	unsigned long long int	i;
	unsigned long long int	f;
	char					sign;
	size_t					len_f;
	double					len_i;
	size_t					len;

	a = va_arg(ap, double);
	i = *(unsigned long long int *)&a;
	p = (i & 0x7ff0000000000000) - 1023;
	sign = i & 0x8000000000000000;
	i &= 0x000fffffffffffff;
	i |= 0x0010000000000000;
	if (sign)
		i = (~i) + 1;
	if (p < 0)
	{
		f = i;
		i = 0;
		len_f = count_len(f) - p;
		len_i = 0;
	}
	else if (p < 52)
	{
		f = (i << (p + 1)) & 0x001fffffffffffff;
		i &= (0xffffffffffffffff << (52 - p));
		len_f = count_len(f);
		len_i = (count_len(i) + p) * 0.30103;
	}
	else
	{
		f = 0;
		len_f = 0;
		len_i = (count_len(i) + p) * 0.30103;
	}
	i >>= 53 - len_i;
	++len_i;
	if (f)
		++len_f;
	len = len_f + (size_t)len_i + (len_i - (size_t)len_i > 0);
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = 0;
	if (f)
		str[len_i] = '.';
	get_i(i, str, len_i, p);
	get_f(i, str + len_i + 1, p);
	return (0);
}
