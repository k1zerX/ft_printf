/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_di.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:27:07 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/21 21:29:41 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_di(va_list ap)
{
	long long int	integer;
	char		*int_num;

	integer = va_arg(ap, long long int);
	int_num = ft_itoa((int)integer);

	return (int_num);
}

