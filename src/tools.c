/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:06:08 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/16 22:12:53 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		itoa_len(long int nbr, int base)
{
	int		len;

	len = 1;
	while ((nbr /= base) != 0)
		++len;
	return (len);
}

char	*ft_itoa_base(int n, int base, const char *digits)
{
	char		*str;
	int			len;
	char		sign;
	long int	nbr;

	if (base < 2)
		return (NULL);
	if ((sign = ((base == 10) && (n < 0))))
		nbr = n;
	else
		nbr = (unsigned int)n;
	len = itoa_len(nbr, base);
	if ((str = malloc(((len += sign) + 1) * sizeof(*str))))
	{
		str[len] = 0;
		if (sign)
			str[0] = '-';
		str[--len] = digits[sign ? -(nbr % base) : nbr % base];
		if (sign)
			nbr *= -1;
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
