/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:19:26 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/19 19:05:11 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_char(va_list ap, const char * restrict str, int len)
{
	int		c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (len);
}