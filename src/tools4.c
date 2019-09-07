/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:44:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/09/07 18:56:53 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len(unsigned long a)
{
	int		i;

	i = -1;
	while (++i < M_LEN)
		if (a & (1 << i))
			break ;
	return (M_LEN - i);
}

#include <stdio.h>

void	apa_mul(int power, char *str, int len, int *l)
{
	int		i;
	int		buf;

//	printf("%d\n", len);
	buf = 0;
	i = len;
	while (--i >= 0 /*&& len - i <= *l*/)
	{
		str[i] *= power;
		str[i] += buf;
		buf = str[i] / 10;
		str[i] -= buf * 10;
		if ((len - i == *l) && buf)
			++*l;
//		if (power == 2)
//		printf("%d", str[i]);
	}
//		if (power == 2)
//	printf("\n");
}
