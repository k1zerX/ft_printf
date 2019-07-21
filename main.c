/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:21:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/21 20:40:55 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "ft_printf.h"

char    *ft_itoa_base(int nbr, int base, const char *digits);

int		main(int ac, char *av[])
{
	if (ac == 3)
	{
		write(1, "- |", 3);
		ft_printf(av[1], atoi(av[2]));
		printf("|\n+ |");
		printf(av[1], atoi(av[2]));
		printf("|\n");
	}
	return (0);
}
