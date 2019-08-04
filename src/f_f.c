/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:54:56 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/04 18:11:31 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct		s_parsed_float
{
  unsigned long		m	: 52;
  unsigned long		e	: 11;
  unsigned long		s	: 1;
}					t_parsed_float;

typedef union		u_float
{
  t_parsed_float	parse;
  double			val;
}					t_float;

typedef struct		s_float_ip
{
	unsigned long	i;
	int				i_len;
	unsigned long	f;
	int				f_len;
}					t_float_ip;

int		count_len(unsigned long a)
{
	int		i;

	i = -1;
	while (++i < 52)
		if (a & (1 << i))
			break ;
	return (52 - i);
}

void	apa_mul(int power, char *str, int len, int *l)
{
	int		i;
	int		buf;

	buf = 0;
	i = len;
	while (--i >= 0 && len - i >= *l)
	{
		str[i] *= power;
		str[i] += buf;
		buf = str[i] / 10;
		str[i] -= buf * 10;
		if (len - i == l && buf)
			++*l;
	}
}

void	print_byte(unsigned char byte)
{
	int		i;

	i = 8;
	while (--i >= 0)
		if (byte & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
}

void	print_bits(void *ptr, int size)
{
	ptr += size;
	print_byte(*(unsigned char *)--ptr);
	while (--size > 0)
	{
		write(1, " ", 1);
		print_byte(*(unsigned char *)--ptr);
	}
	write(1, "\n", 1);
}

void	test_putstr(char *str, int len)
{
	char c;
	write(1, "|", 1);
	while (--len >= 0)
	{
		c = 48 + *str++;
		write(1, &c, 1);
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}

void	apa_fill_i(char *str, unsigned long m, int len, int k)
{
	int		i;
	int		j;
	int		l;

//	print_bits(&m, sizeof(m));
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
//		test_putstr(str, len);
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

//	print_bits(&m, sizeof(m));
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
//		test_putstr(str, len);
	}
	i = -1;
	while (++i < k)
		apa_mul(5, str, len, &l);
	i = -1;
	while (++i < len)
		str[i] += '0';
}

char	*apa_float(double n)
{
	t_float		f;
	t_float_ip	parts;
	int			k;
	char		*str;
	int			il;
	double		buf;

	f.val = n;
	if (!(~f.parse.e))
	{
		if (f.parse.m)
			return ("NaN");
		if (f.parse.s)
			return ("-inf");
		else
			return ("inf");
	}
	k = f.parse.e - 1023;
	if (k > 52)
	{
		parts.i = f.parse.m | ((unsigned long)1 << 52);
		parts.i_len = 53;
		parts.f = 0;
		parts.f_len = 0;
		k -= 52;
	}
	else if (k < 0)
	{
		parts.i = 0;
		parts.i_len = 0;
		parts.f_len = count_len(f.parse.m);
		parts.f = (f.parse.m >> (52 - parts.i_len)) | ((unsigned long)1 << parts.i_len);
		k += ++parts.f_len;
	}
	else // 0 <= k <= 52
	{
		parts.i = (f.parse.m >> (52 - k)) | ((unsigned long)1 << (k));
		parts.i_len = k + 1;
		parts.f_len = count_len(f.parse.m) - k;
//		if (parts.f_len < 0)
//			parts.f_len = 0;	// ????????????????
		parts.f = (f.parse.m << k) >> (52 - parts.f_len);
//		printf("%d %d\n", k, parts.i_len);
		k = 0;
	}
	il = (int)((parts.i_len /*-1 */ + ((k < 0) ? (0) : (k))) * 0.30103) + 1; // new -1
//	printf("len: %d | %ld %ld %ld |\n", il, f.parse.s, f.parse.e, f.parse.m);
	if (!(str = malloc((1 + il + 1 + parts.f_len + 1) * sizeof(char))))
		exit(1);
//	printf("%lu, %d, %d\n", parts.i, il, k);
	str[0] = (f.parse.s) ? '-' : '+';
	apa_fill_i(str + 1, parts.i, il, k);
	str[1 + il] = '.';
	apa_fill_f(str + 1 + il + 1, parts.f, parts.f_len, k);
	str[1 + il + 1 + parts.f_len] = 0;
	write(1, str, 1 + il + 1 + parts.f_len);
	return (str);
}

int		f_f(va_list ap, t_format f)
{
	double	n;
	char	*nbr;
	char	*str;
	int		len;

	n = va_arg(ap, double);
	nbr = apa_float(n);
	len = ft_strlen(nbr);
//	write(1, nbr, len);
	return (len);
}
