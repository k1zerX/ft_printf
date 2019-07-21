/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:20:44 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/22 00:22:20 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void    print_bits(void *a, unsigned long size);

t_conv			g_conv[] =
{
	{'c', &f_c},
	{'s', &f_s},
	{'p', &f_p},
	{'d', &f_d},
	{'i', &f_i},
	{'o', &f_o},
	{'u', &f_u},
	{'x', &f_x},
	{'X', &f_big_x},
	{'%', &f_percent},
	{0, NULL}
};

int		ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			len;
	int			res;
	char		*start;

	va_start(ap, str);
	len = 0;
	start = (char *)str;
	res = 0;
	while (*str)
	{
		if (*str++ == '%')
		{
			write(1, start, len);
			res += len;
			len = -1;
			while (str[++len])
			{
				i = -1;
				while (g_conv[++i].conv)
				{
					if (g_conv[i].conv == str[len])
					{
						res += (*g_conv[i].f)(ap, format(str, len));
						break ;
					}
				}
				if (g_conv[i].conv)
					break ;
			}
			str += len + 1;
			start = (char *)str;
		}
		else
			++len;
	}
	write(1, start, len);
	res += len;
	va_end(ap);
	return (res);
}
