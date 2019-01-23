/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:30:06 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/23 19:56:36 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_o(va_list ap)
{
	long long int	integer;
	char			*int_num;

	integer = va_arg(ap, long long int);
	int_num = ft_itoa_base(integer, 8);
	return (int_num);
}
