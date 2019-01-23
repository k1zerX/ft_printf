/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_x.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:33:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/23 19:13:40 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base_x(long long int n, int base)
{
	char	*res;
	char	*b;
	long long int		i;
	long long int		tmp;
	int		sign;

	b = "0123456789abcdef";
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

char	*f_x(va_list ap)
{
	long long int	integer;
	char			*int_num;

	integer = va_arg(ap, long long int);
	//if (integer < 0)
	//	integer += 2147483647;
	int_num = ft_itoa_base_x(integer, 16);
	return (int_num);
}
