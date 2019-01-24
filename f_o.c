/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:30:06 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/24 16:40:49 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_o(va_list ap, t_format f)
{
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
