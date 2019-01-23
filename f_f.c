/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:33:54 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/23 16:17:39 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void    print_bits(void *a, unsigned long size);
#include <stdio.h>
char	*f_f(va_list ap)
{
	(void)ap;
	return (NULL);
}
/*
char	*f_f(va_list ap)
{
	double			a;
	unsigned char	*buf;
	char			*str;
	int				p;
	long long int	d;
	int				j;

	str = NULL;
	a = va_arg(ap, double);
	//printf("%.0f =\t", a);
	//print_bits(&a, 8);
	buf = (unsigned char *)&a;
	p = (((buf[7] & 127) << 4) | (buf[6] >> 4)) - 1023;
	d = ((buf[6] & 15) >> (4 - (p > 4 ? 4 : p)));
	//printf("||| %d |||\n", p);
	//printf("\t\t");
	//print_bits(&d, 4);
	j = 1;
	while (++j < ((12 + p) >> 3))
	{
		d <<= 8;
		d |= buf[7 - j];
	//	printf("\t\t");
		//print_bits(&d, 4);
	}
	d <<= ((12 + (p > 4 ? p : 4)) & 7);
	d |= (buf[7 - j] >> (8 - ((12 + p) & 7)));
	if (p + 1023)
		d |= 1 << p;
	//printf("\t\t");
	//print_bits(&d, 4);
	if (buf[7] & 128)
		d = ~d + 1;
	//printf("res =\t%d\n", d);
	//printf("%f\t", a);
	//print_bits(&b, 4);
	j = 11 + p;
	while (++j <= 64)
	{

	}
	return (0);
}*/
