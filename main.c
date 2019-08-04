/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/08/04 20:20:45 by kbatz            ###   ########.fr       */
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
	int		i;

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
	if (ac > 3)
	{
		f = (double)atoi(av[2]) / (double)atoi(av[3]);
		i = atoi(av[2]);
//		*(unsigned long *)&f = 0xffefffffffffffff;
		printf("|");
		a = printf(av[1], f, f, f);
		printf("|\n");
		write(1, "|", 1);
		b = ft_printf(av[1], f, f, f);
		printf("|\n");
		printf("%d vs %d\n", a, b);
//		ft_printf("%f\n", f);
	}
	return (0);
}
