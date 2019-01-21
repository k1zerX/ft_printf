/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:02:41 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/21 21:36:02 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// "#0-+ '"
	// "76543210"

int		mini_atoi(va_list ap, const char *restrict *format, int *len)
{
	int		res;

	res = 0;
	if (**format == '*')
		res = va_arg(ap, int);
	else
		while (ft_isdigit(**format) && (*len)--)
			res = res * 10 + *(*format)++ - 48;
	return (res);
}

t_format	format(va_list ap, const char *restrict format, int len)
{
	t_format	f;

	f.flags = 0;
	while (len-- > 0)
	{
		if (*format == '.')
		{
			f.precision = mini_atoi(ap, &format, &len);
			format++;
			len--;
		}
		if (*format == '0')
			f.flags |= 1 << 6;
		f.width = mini_atoi(ap, &format, &len);
		if (*format == '-')
			f.flags |= 1 << 5;
		else if (*format == '+')
			f.flags |= 1 << 4;
		else if (*format == ' ')
			f.flags |= 1 << 3;
		else if (*format == '\'')
			f.flags |= 1 << 2;
		format++;
	}
	if (f.flags & 32)
		f.flags &= ~(1 << 6);
	if (f.flags & 16 || f.flags & 64)
		f.flags &= ~(1 << 3);
	return (f);
}

void		ft_write(char *str, int len, int *res)
{
	write(1, str, len);
	*res += len;
}

int			ft_print(t_format f, char *str)
{
	int		res;
	int		len;
	char	c;

	len = ft_strlen(str);
	c = f.flags & 64 ? '0' : ' ';
	f.precision += f.width;
	f.width -= len;
	if ((f.flags & 16) && ft_isdigit(*str) && !(res = 0))
		f.width--;
	if (f.flags & 8)
		f.width--;
	f.precision -= f.width;
	f.width -= f.precision;
	if (f.flags & 32)
		while (f.width-- > 0)
			ft_write(&c, 1, &res);
	if ((f.flags & 16) && ft_isdigit(*str))
		ft_write("+", 1, &res);
	if (f.flags & 8)
		ft_write(" ", 1, &res);
	while (f.precision-- > 0)
		ft_write("0", 1, &res);
	ft_write(str, len, &res);
	while (f.width-- > 0)
		ft_write(&c, 1, &res);
	return (res);
}
