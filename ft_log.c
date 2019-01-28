/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:48:48 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/26 19:49:40 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double		ft_log(double n)
{
	int		i;
	double	res;
	double	x;
	char	sign;

	sign = 1;
	if (n > 1)
	{
		n = 1 / n;
		sign = -1;
	}
	n--;
	x = n;
	res = x;
	i = 0;
	while (++i < LOG_PR && (x > 0 ? x : -x) >= LOG_ADD_PR)
	{
		x *= -n;
		res += x / i;
	}
	return (res * sign);
}

int		main(void)
{
	printf("%f", 100 * ft_log(2) / ft_log(10));
	return (0);
}
