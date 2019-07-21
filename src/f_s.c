/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:02:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/21 23:00:39 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int ft_ascii(char *s, t_format f)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s);
	if (f.width < len)
		f.width = len;
	if (!(str = malloc((f.width + 1) * sizeof(char))))
		exit(1);
	if (f.minus)
		f.zero = 0;
	if (f.precision != -1 && f.precision < len)
	{
		len = f.precision;
		f.width = len;
	}
	i = -1;
	if (f.minus)
	{
		while (++i < len)
			str[i] = s[i];
		--i;
	}
	j = -1;
	while (++j < (f.width - len))
		str[++i] = f.zero ? '0' : ' ';
	j = -1;
	if (!f.minus)
		while (++j < len)
			str[++i] = s[j];

	write(1, str, f.width);
	free(str);
	return (f.width);
}

int f_s(va_list ap, t_format f)
{
	char	*s;

	s = va_arg(ap, char *);
	return (ft_ascii(s, f));
}

int f_c(va_list ap, t_format f)
{
	char	c;
	int		res;
	char	*str;

	c = va_arg(ap, int);
	str = malloc(2 * sizeof (*str));
	str[0] = c;
	str[1] = 0;
	res = ft_ascii(str, f);
	free(str);
	return (res);
}

int f_percent(va_list ap, t_format f)
{
	(void)ap;
	return (ft_ascii("%", f));
}
