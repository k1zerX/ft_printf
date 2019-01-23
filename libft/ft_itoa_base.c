/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:06:27 by krakharo          #+#    #+#             */
/*   Updated: 2019/01/23 19:16:31 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long int n, int base)
{
	char			*res;
	char			*b;
	long long int	i;
	long long int	tmp;
	int				sign;

	b = "0123456789ABCDEF";
	tmp = n;
	i = 1;
	sign = 1;
	while (tmp != 0)
		tmp = tmp / base + (i++) * 0;
	if ((n < 0 && base == 10) || (n == 0))
		i++;
	if (!(res = (char*)malloc(sizeof(char) * i)))
		return (0);
	if (n < 0 && (sign = -1) && base == 10)
		res[0] = '-' + (tmp++) * 0;
	res[--i] = '\0';
	while (i > tmp)
	{
		res[--i] = b[n % base * sign];
		n = n / base;
	}
	return (res);
}
