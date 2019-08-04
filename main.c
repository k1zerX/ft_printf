/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/31 00:15:04 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <libc.h>
#include <unistd.h>
#include "ft_printf.h"

#define TEST1 "%f\n", (long double)(-10.0 / 3.0)

char    *ft_itoa_base(int nbr, int base, const char *digits);

int		main(int ac, char  *av[])
{
//	int		a;
//	int		b;
//	void	*ptr;
	double	f;
	int		b;
	int		a;

	(void)ac;
	(void)av;
/*	printf("-\n");
	a = ft_printf(TEST1);
	printf("+\n");
	b = printf(TEST1);
	if (a == b)
		printf("true\n");
	else
		printf("false: %d vs %d\n", a, b);
	printf("|%lu %lu %lu|\n", sizeof(float), sizeof(double), sizeof (long double));*/
	if (ac > 2)
	{
		f = (double)atoi(av[1]) / (double)atoi(av[2]);
//		*(unsigned long *)&f = 0xffefffffffffffff;
		a = printf("+ | %f\n", f);
		b = ft_printf("- | %f\n", f);
		printf("%d vs %d\n", a, b);
//		ft_printf("%f\n", f);
	}
	return (0);
}
