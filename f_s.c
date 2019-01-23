/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:30:25 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/23 18:00:47 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_s(va_list ap)
{
	char *string;

	string = va_arg(ap, char *);
	if (string)
		return (string);
	else
		return ("(null)");
}
