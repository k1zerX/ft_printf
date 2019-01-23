/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_big_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:30:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/23 20:26:02 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_big_x(va_list ap, t_format format)
{
	unsigned long long int	integer;
	char			*int_num;


	if(format.type == 0)
		return (ft_itoa_base(va_arg(ap, int), 8));
	else if(format.type == 1)
		return (ft_itoa_base(va_arg(ap, long int), 8));
	else if(format.type == 2)
		return (ft_itoa_base(va_arg(ap, long long int), 8));
	else if(format.type == -1)//h
		return (ft_itoa_base(va_arg(ap, int), 8));
	else if(format.type == -2)//hh
		return (ft_itoa_base(va_arg(ap, int), 8));
}

