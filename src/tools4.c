/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:44:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/08/04 19:46:24 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len(unsigned long a)
{
	int		i;

	i = -1;
	while (++i < 52)
		if (a & (1 << i))
			break ;
	return (52 - i);
}

void	apa_mul(int power, char *str, int len, int *l)
{
	int		i;
	int		buf;

	buf = 0;
	i = len;
	while (--i >= 0 && len - i <= *l)
	{
		str[i] *= power;
		str[i] += buf;
		buf = str[i] / 10;
		str[i] -= buf * 10;
		if ((len - i == *l) && buf)
			++*l;
	}
}
