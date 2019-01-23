/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_di.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:27:07 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/23 20:24:51 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_di(va_list ap, t_format format)
{
	long long int	integer;
	char			*int_num;

	if(format.type == 0)
		return (ft_itoa(va_arg(ap, int)));
	else if(format.type == 1)
		return (ft_itoa(va_arg(ap, long int)));
	else if(format.type == 2)
		return (ft_itoa(va_arg(ap, long long int)));
	else if(format.type == -1)//h
		return (ft_itoa(va_arg(ap, int)));
	else if(format.type == -2)//hh
		return (ft_itoa_base(va_arg(ap, int), 10));
}
