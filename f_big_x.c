/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_big_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:30:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/26 18:22:35 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_big_x(va_list ap, t_format f, int len)
{
	if(f.width > len && (f.flags & 64) && f.width > len + 2 * ((f.flags & 128) > 0))
	{
		f.width -= 2;
		len += 2;
	}
	else if (f.precision > len + 2 * ((f.flags & 128) > 0))
	{
		len += 2;
	}
	if(f.type == 0)
		return (ft_itoa_base(va_arg(ap, int), 8));
	else if(f.type == 1)
		return (ft_itoa_base(va_arg(ap, long int), 8));
	else if(f.type == 2)
		return (ft_itoa_base(va_arg(ap, long long int), 8));
	else if(f.type == -1)
		return (ft_itoa_base(va_arg(ap, short int), 8));
	else if(f.type == -2)
		return (ft_itoa_base(va_arg(ap, char), 8));
}

