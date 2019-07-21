/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/22 00:20:36 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "ft_printf.h"

#define TEST1 "%%heo %s %d sgdds\n", "world", 77

char    *ft_itoa_base(int nbr, int base, const char *digits);

int		main()
{
	int		a;
	int		b;

	printf("-\n");
	a = ft_printf(TEST1);
	printf("+\n");
	b = printf(TEST1);
	if (a == b)
		printf("true\n");
	else
		printf("false: %d vs %d\n", a, b);
	return (0);
}
