/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_x.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:33:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/01/24 15:51:57 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base_x(unsigned long long int n, int base)
{
	char			*res;
	char			*b;
	long long int	i;
	long long int	tmp;
	int				sign;

	b = "0123456789abcdef";
	tmp = n;
	i = 1;
	sign = 1;
	while (tmp != 0)
		tmp = tmp / base + (i++) * 0;
	if (base == 10 || (n == 0))
		i++;
	if (!(res = (char*)malloc(sizeof(char) * i)))
		return (0);
	if (sign == -1 && base == 10)
		res[0] = '-' + (tmp++) * 0;
	res[--i] = '\0';
	while (i > tmp)
	{
		res[--i] = b[n % base * sign];
		n = n / base;
	}
	return (res);
}

char	*f_x(va_list ap, t_format f, int len)
{
	unsigned long long int	integer;
	char					*str;


	if ((f.flags & 128))
	//0000
	{
		if(f.width > len && (f.flags & 64) && f.width > len + 2 * ((f.flags & 128) > 0))

		else if (f.precision > len + 2 * ((f.flags & 128) > 0))
	}
	if(f.type == 0)
		return (ft_itoa_base(va_arg(ap, int), 8));
	else if(f.type == 1)
		return (ft_itoa_base(va_arg(ap, long int), 8));
	else if(f.type == 2)
		return (ft_itoa_base(va_arg(ap, long long int), 8));
	else if(f.type == -1)//h
		return (ft_itoa_base(va_arg(ap, int), 8));
	else if(f.type == -2)//hh
		return (ft_itoa_base(va_arg(ap, int), 8));

}
