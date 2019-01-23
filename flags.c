/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:02:41 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/23 18:12:25 by kbatz            ###   ########.fr       */
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
		while (ft_isdigit(**format) && (*len)-- + 1)
			res = res * 10 + *(*format)++ - 48;
	return (res);
}

t_format	format(va_list ap, const char *restrict format, int len)
{
	t_format	f;

	ft_bzero(&f, sizeof(f));
	while (len-- > 0)
	{
		if (*format == '.')
		{
			format++;
			len--;
			f.precision = mini_atoi(ap, &format, &len);
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

	c = f.flags & 64 ? '0' : ' ';
	//printf("%d\n", f.flags);
	//printf("111111width = %d, precision = %d\n", f.width, f.precision);
	res = 0;
	//f.precision -= f.width;
	len = ft_strlen(str);
	f.width -= len;
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	if ((f.flags & 16) && ft_isdigit(*str))
		f.width--;
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	if ((f.flags & 8) && ft_isdigit(*str))
		f.width--;
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	f.precision += f.width;
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	if (!(f.flags & 32) && !(f.flags & 64))
		while (f.width-- > 0)
			ft_write(" ", 1, &res);
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	if ((f.flags & 16) && ft_isdigit(*str))
		ft_write("+", 1, &res);
	if ((f.flags & 8) && ft_isdigit(*str))
		ft_write(" ", 1, &res);
	if (!(f.flags & 32) && (f.flags & 64))
		while (f.width-- > 0)
			ft_write("0", 1, &res);
	//while (f.precision-- > 0)
	//	ft_write("0", 1, &res);
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	ft_write(str, len, &res);
	while (f.width-- > 0)
		ft_write(" ", 1, &res);
	//printf("width = %d, precision = %d\n", f.width, f.precision);
	return (res);
}
