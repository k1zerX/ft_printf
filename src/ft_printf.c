/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:20:44 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/21 22:27:50 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void    print_bits(void *a, unsigned long size);

t_conv			g_conv[] =
{/*
	{'c', &f_c},
	{'s', &f_s},*/
	{'p', &f_p},
	{'d', &f_d},
	{'i', &f_i},
	{'o', &f_o},
	{'u', &f_u},
	{'x', &f_x},
	{'X', &f_big_x},/*
	{'%', &f},*/
	{0, NULL}
};

int		ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			len;
	int			res;

	va_start(ap, str);
	res = 0;
	while (*str)
	{
		if (*str++ == '%')
		{
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
		}
		else
		{
			res++;
			write(1, str - 1, 1);
		}
	}
	va_end(ap);
	return (res);
}
