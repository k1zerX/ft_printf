/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:23:48 by kbatz             #+#    #+#             */
/*   Updated: 2019/08/04 20:02:49 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apa_fill_i(char *str, unsigned long m, int len, int k)
{
	int		i;
	int		j;
	int		l;

	i = -1;
	while (++i < len)
		str[i] = 0;
	l = 1;
	i = 53;
	while (--i >= 0)
	{
		apa_mul(2, str, len, &l);
		if (m & ((unsigned long)1 << i))
			str[len - 1] += 1;
	}
	i = -1;
	while (++i < k)
		apa_mul(2, str, len, &l);
	i = -1;
	while (++i < len)
		str[i] += '0';
}

void	apa_fill_f(char *str, unsigned long m, int len, int k)
{
	int		i;
	int		j;
	int		l;

	i = -1;
	while (++i < len)
		str[i] = 0;
	l = 1;
	i = -1;
	while (++i < len)
	{
		if (m & ((unsigned long)1 << i))
			str[len - 1 - i] += 1;
		apa_mul(5, str, len, &l);
	}
	i = -1;
	while (++i < k)
		apa_mul(5, str, len, &l);
	i = -1;
	while (++i < len)
		str[i] += '0';
}

void	apa_if(int *k, t_float f, t_float_ip *parts)
{
	if (*k > 52)
	{
		parts->i = f.parse.m | ((unsigned long)1 << 52);
		parts->i_len = 53;
		parts->f = 0;
		parts->f_len = 0;
		*k -= 52;
	}
	else if (k < 0)
	{
		parts->i = 0;
		parts->i_len = 0;
		parts->f_len = count_len(f.parse.m);
		parts->f = (f.parse.m >> (52 - parts->i_len)) | \
				((unsigned long)1 << parts->i_len);
		*k += ++parts->f_len;
	}
	else
	{
		parts->i = (f.parse.m >> (52 - *k)) | ((unsigned long)1 << (*k));
		parts->i_len = *k + 1;
		parts->f_len = count_len(f.parse.m) - *k;
		parts->f = (f.parse.m << *k) >> (52 - parts->f_len);
		*k = 0;
	}
}

char	*apa_get(t_float f, t_float_ip parts, int il, int k)
{
	char	*str;

	if (!(str = malloc((1 + il + 1 + parts.f_len + 1) * sizeof(char))))
		exit(1);
	str[0] = (f.parse.s) ? '-' : '+';
	apa_fill_i(str + 1, parts.i, il, k);
	str[1 + il] = '.';
	apa_fill_f(str + 1 + il + 1, parts.f, parts.f_len, k);
	str[1 + il + 1 + parts.f_len] = 0;
	return (str);
}

char	*apa_float(double n)
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
	k = f.parse.e - 1023;
	apa_if(&k, f, &parts);
	il = (int)((parts.i_len + ((k < 0) ? (0) : (k))) * 0.30103) + 1;
	return (apa_get(f, parts, il, k));
}
