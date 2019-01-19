/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:20:44 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/19 19:04:13 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_conv			g_conv[] =
{
	{'c', &f_char},
	/*{'s', &f},
	{'p', &f},
	{'d', &f},
	{'i', &f},
	{'o', &f},
	{'u', &f},
	{'x', &f},
	{'X', &f},
	{'f', &f},
	{'%', &f},
	{'e', &f},
	{'g', &f},
	{'b', &f},
	{'r', &f},
	{'k', &f},*/
	{'\0', NULL}
};

int		ft_printf(const char *restrict str, ...)
{
	va_list		ap;
	int			i;
	int			len;
	int			res;

	va_start(ap, str);
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
						res += g_conv[i].f(ap, str, len);
					//printf("%c", str[len]);
				}
				if (!g_conv[i].conv)
					break ;
			}
			str += len;
		}
		else
			write(1, str - 1, 1);
	}
	va_end(ap);
	return (res);
}

int		main(void)
{
	char	c;

	c = 'Z';
	ft_printf("blabla %c sdf f", c);
	return (0);
}
