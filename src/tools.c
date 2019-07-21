/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:06:08 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/21 22:05:15 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		itoa_len(unsigned long long int nbr, int base)
{
	int		len;

	len = 1;
	while ((nbr /= base) != 0)
		++len;
	return (len);
}

char	*ft_ultra_itoa(long long int n, int base, char is_signed, const char *digits)
{
	char					*str;
	int						len;
	char					sign;
	unsigned long long int	nbr;

	if (base < 2)
		return (NULL);
	if (is_signed && (sign = n < 0))
		nbr = ~(unsigned long long int)n + 1;
	else
		nbr = n;
//	printf("%llu %lld", nbr, n);
	len = itoa_len(nbr, base) + 1;
	if ((str = malloc((len + 1) * sizeof(*str))))
	{
		str[len] = 0;
		str[0] = (sign) ? ('-') : ('+');
		str[--len] = digits[nbr % base];
		while ((nbr /= base) > 0)
			str[--len] = digits[nbr % base];
	}
	return (str);
}

int		mini_atoi(const char *restrict *format, int *len)
{
	int		res;

	res = 0;
	while (ft_isdigit(**format) && (*len)-- + 1)
		res = res * 10 + *(*format)++ - 48;
	--(*format);
	++(*len);
	return (res);
}

void		ft_bzero(void *ptr, size_t size)
{
	while (size--)
		*(unsigned char *)(ptr++) = 0;
}

int     ft_strlen(char *str)
{
	char	*start;
	
	start = str;
	while (*str)
		++str;
	return (str - start);
}

void	ft_intfill(char *str, char *nbr, t_format f, int len)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!f.minus && !f.zero)
		while (++i < f.width)
			str[j++] = ' ';
	if (f.plus)
		str[j++] = *nbr;
	i = -1;
	if (!f.minus && f.zero)
		while (++i < f.width)
			str[j++] = '0';
	i = -1;
	while (++i < f.precision)
		str[j++] = '0';
	i = -1;
	while (++i < len)
		str[j++] = *(++nbr);
	i = -1;
	if (f.minus)
		while (++i < f.width)
			str[j++] = ' ';
}

t_format	format(const char *restrict format, int len)
{
	t_format	f;

	ft_bzero(&f, sizeof(f));
	f.precision = -1;
	while (--len >= 0)
	{
		if (*format == '#')
			f.sharp = 1;
		else if (*format == '.')
		{
			++format;
			--len;
			f.precision = mini_atoi(&format, &len);
		}
		else if (*format == '0')
			f.zero = 1;
		else if (ft_isdigit(*format))
			f.width = mini_atoi(&format, &len);
		else if (*format == '-')
			f.minus = 1;
		else if (*format == '+')
			f.plus = 1;
		else if (*format == ' ')
			f.space = 1;
		else if (*format == 'l')
			++f.type;
		else if (*format == 'h')
			--f.type;
		++format;
	}
	return (f);
}
