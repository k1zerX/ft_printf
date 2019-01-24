/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_u.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:21:46 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/24 15:06:55 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_u(va_list ap, t_format format)
{
	if(format.type == 0)
		return (ft_itoa_base(va_arg(ap, int), 10));
	else if(format.type == 1)
		return (ft_itoa_base(va_arg(ap, long int), 10));
	else if(format.type == 2)
		return (ft_itoa_base(va_arg(ap, long long int), 10));
	else if(format.type == -1)//h
		return (ft_itoa_base(va_arg(ap, unsigned short int), 10));
	else if(format.type == -2)//hh
		return (ft_itoa_base(va_arg(ap, unsigned char), 10));
}
