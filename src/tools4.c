/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:44:42 by kbatz             #+#    #+#             */
/*   Updated: 2019/09/07 22:56:15 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_len(unsigned long a)
{
	int		i;

	i = -1;
	while (++i < M_LEN)
		if (a & (1 << i))
			break ;
	return (M_LEN - i);
}

#include <stdio.h>

void	apa_mul(int power, unsigned char *str, int len, int *l)
{
	int		i;
	int		buf;

//	printf("%d\n", len);
	buf = 0;
	i = len;
	while (--i >= 0 && len - i <= *l)
	{
		str[i] *= power;
		str[i] += buf;
		buf = str[i] / 10;
		str[i] -= buf * 10;
		if ((len - i == *l) && buf)
			++*l;
//		if (power == 2)
//		printf("%d", str[i]);
	}
//		if (power == 2)
//	printf("\n");
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (tmp);
}

int		ft_find_dot(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == '.')
			return (tmp - str);
		++tmp;
	}
	return (-1);
}

void	ft_treatment(char *nbr)
{
	int		i;
	int		j;

	i = 0;
	while (nbr[i] && nbr[i] != '0')
		++i;
	j = i;
	while (nbr[j] == '0' && (nbr[j + 1] != '.' && nbr[j + 1]))
		++j;
//	printf("%s vs ", nbr);
	ft_strcpy(nbr + i, nbr + j);
//	printf("%s\n", nbr);
}
