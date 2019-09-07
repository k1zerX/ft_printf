/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:23:48 by kbatz             #+#    #+#             */
/*   Updated: 2019/09/07 23:32:06 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	ft_len(unsigned char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_to_char(unsigned char *str, size_t len)
{
	char	*res;
	char	*buf;

	if (!(res = malloc(len * sizeof(char))))
		exit(1);
	buf = res;
	while (len--)
	{
		*buf = *str;
		if (*buf >= 0 && *buf <= 9)
			*buf += 48;
//		printf("%c %d\n", *res, *str);
		++buf;
		++str;
	}
	return (res);
}

void	print_byte(unsigned char byte)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (byte & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		--i;
	}
}

void	print_bits(void *ptr, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr + size;
	print_byte(*--tmp);
	while (--size)
	{
		write(1, " ", 1);
		print_byte(*--tmp);
	}
	write(1, "\n", 1);
}
#include <stdio.h>

void	apa_fill_i(unsigned char *str, unsigned long m, int len, int k)
{
	int		i;
	int		l;

//	print_bits(&m, sizeof(m));
	i = -1;
	while (++i < len)
		str[i] = 0;
	l = 1;
	i = M_LEN;
	while (--i >= 0)
	{
		apa_mul(2, str, len, &l);
		if (m & ((unsigned long)1 << i))
			str[len - 1] += 1;
	}
	i = -1;
	while (++i < (k >> 2))
		apa_mul(16, str, len, &l);
	i = -1;
	while (++i < (k & 3))
		apa_mul(2, str, len, &l);
}

void	apa_fill_f(unsigned char *str, unsigned long m, int len, int k)
{
	int		i;
	int		l;

//	printf("%d %d\n", len, k);
	i = -1;
	while (++i < len + k)
		str[i] = 0;
	l = 1;
	i = -1;
	while (++i < len)
	{
//		print_bits(&m, sizeof(m));
		if (m & 1)
			str[len + k - 1 - i] += 1;
		++l;
		m >>= 1;
		apa_mul(5, str, len + k, &l);
/*		int j = -1;
		while (++j < len)
			str[j] += '0';
		write(1, str, len);
		write(1, "\n", 1);
		j = -1;
		while (++j < len)
			str[j] -= '0';*/
	}
	i = -1;
	while (++i < (k >> 1))
		apa_mul(25, str, len + k, &l);
	if (k & 1)
		apa_mul(5, str, len + k, &l);
//		print_bits(&m, sizeof(m));
}

void	apa_if(int *k, t_float f, t_float_ip *parts)
{
	if (*k > M_LEN)
	{
		*k += 1;
		parts->i = f.parse.m;
		parts->i_len = M_LEN;
		parts->f = 0;
		parts->f_len = 0;
		*k -= M_LEN;
	}
	else if (*k < 0)
	{
		parts->i = 0;
		parts->i_len = 0;
		parts->f_len = count_len(f.parse.m);
		parts->f = f.parse.m >> (M_LEN - parts->f_len);
	}
	else
	{
		*k += 1;
		parts->i = f.parse.m >> (M_LEN - *k);
		parts->i_len = *k;
		parts->f_len = count_len(f.parse.m);
		parts->f = f.parse.m >> (M_LEN - parts->f_len);
		parts->f_len -= *k;
		parts->f &= ~(~((unsigned long)0) << parts->f_len);
//		print_bits(&parts->f, 8);
//		printf("%d\n", parts->f_len);
//		printf("%lu\n", parts->f);
		*k = -1;
	}
}

char	*apa_get(t_float f, t_float_ip parts, int il, int k)
{
	unsigned char	*str;

	if (!(str = malloc((1 + il + 1 + parts.f_len + ((k > 0) ? (0) : (-++k)) + 1) * sizeof(unsigned char))))
		exit(1);
//	printf("1 + %d + 1 + %d + 1\n", il, parts.f_len + ((k > 0) ? (0) : (-k)));
	str[0] = (f.parse.s) ? '-' : '+';
	apa_fill_i(str + 1, parts.i, il, k);
	str[1 + il] = '.';
	apa_fill_f(str + 1 + il + 1, parts.f, parts.f_len, -k);
	str[1 + il + 1 + parts.f_len + ((k > 0) ? (0) : (-k))] = 0;
	return (ft_to_char(str, 1 + il + 1 + parts.f_len + ((k > 0) ? (0) : (-k)) + 1));
}

char	*apa_float(long double n)
{
	t_float		f;
	t_float_ip	parts;
	int			k;
	int			il;

	f.val = n;
	if (!(~f.parse.e))
	{
		if (f.parse.m)
			return ("NaN");
		else if (f.parse.s)
			return ("-inf");
		else
			return ("inf");
	}
//	printf("%hu %hu %lu\n", f.parse.s, f.parse.e, f.parse.m);
	k = f.parse.e - ~(~((unsigned)0) << (E_LEN - 1));
//	printf("%d\n", k);
//	print_bits(&n, 10);
	apa_if(&k, f, &parts);
	il = (int)((((parts.i_len) ? (parts.i_len) : (1)) + ((k < 0) ? (0) : (k))) * 0.30103) + 1 + 1;
//	printf("%d %d\n", il, parts.i_len);
	//printf("(%d - 1 + %d) * 0.30103 + 1 = %d\n", parts.i_len, k, il);
	return (apa_get(f, parts, il, k));
}
