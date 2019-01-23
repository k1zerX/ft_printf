/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:57:06 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/23 16:20:45 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	print_bits(void *a, unsigned long size)
{
	char	j;

	while(size-- > 0)
	{
		j = 8;
		while (--j >= 0)
		{
			printf("%d", ((((unsigned char *)a)[size] >> j) & 1));
			//if ((7 - size) * 8 + (8 - j) == 1 || (7 - size) * 8 + (8 - j) == 12)
			//	printf(" ");
		}
		printf("|");
	}
	printf("\n");
}

int		main(void)
{
	ft_printf("hello % .100d\n\n\n world %-10d\n\n |gg = %s\n", 3, -7, "kakak");/*
	ft_printf("%+d\n\n\n", -3);
	ft_printf("%-d\n\n\n", -15);
	ft_printf("%0d\n\n\n", 29);
	ft_printf("% d\n\n\n", -163);*/
	return (0);
}

/*
int		main(void)
{
	double f;
	long long int b;

	f = 1.0 / 8.0 + 15.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -1.0 / 8.0 - 15.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 1.0 / 3.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = (-1.0 / 3.0);
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 0.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -0.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 1.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -1.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 2.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -2.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 4.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -4.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 15.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -15.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 128.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -128.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 255.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -255.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = 99999.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	f = -9999.0;
	printf("%10.5f -> ", f);
	print_bits(&f, sizeof(f));
	printf("%f", +0.0);
	printf("%100f", -0.0);
	return (0);
}*/
