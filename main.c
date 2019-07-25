/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/25 18:27:28 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "ft_printf.h"

#define TEST1 "%%heo %s %d sgdds", "world", 77

char    *ft_itoa_base(int nbr, int base, const char *digits);

int		main(int ac, char  *av[])
{
	int		a;
	int		b;
	void	*ptr;

	(void)ac;
	(void)av;
	ptr = malloc(0);
	printf("-\n");
	a = ft_printf("%", ptr);
	printf("+\n");
	b = printf("%", ptr);
	if (a == b)
		printf("true\n");
	else
		printf("false: %d vs %d\n", a, b);
	return (0);
}
