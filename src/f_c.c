/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:09:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/22 00:13:19 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int f_c(va_list ap, t_format f)
{
	char	c;
	char	*str;

	c = va_arg(ap, int);
	if (f.minus)
		f.zero = 0;
	if (--f.width < 0)
		f.width = 0;
	if (!(str = malloc((f.width + 2) * sizeof(*str))))
		exit(1);
	ft_strfill(str, &c, f, 1);
	write(1, str, f.width + 1);
	free(str);
	return (f.width + 1);
}
