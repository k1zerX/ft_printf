/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_di.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:25:18 by kbatz             #+#    #+#             */
/*   Updated: 2019/07/16 21:32:51 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_strlen(char *str)
{
	char	*start;
	
	start = str;
	while (*str)
		++str;
	return (str - start);
}

void	ft_strfill(char *str, char *nbr, t_format f, int len)
{
	int		i;
	int		j;
	char	c;

	c = (f.zero) ? ('0') : (' ');
	i = 0;
	if (!f.minus)
		while (i < f.width - f.precision)
			str[i++] = c;
	j = i;
	if (*nbr == '-')
	{
		str[j++] = *(nbr++);
		--len;
	}
	else if (f.plus)
		str[j++] = '+';
	while (j < f.precision - len + i)
		str[j++] = '0';
	while (--len >= 0)
		str[j++] = *(nbr++);
	if (f.minus)
		while (j < f.width)
			str[j++] = c;
}

int		f_di(va_list ap, t_format f)
{
	long long int	n;
	char			*nbr;
	char			*str;
	int				len;

	n = va_arg(ap, long long int);
	if (f.type == FT_HH)
		n = (char)n;
	else if (f.type == FT_H)
		n = (short int)n;
	else if (f.type == FT_L)
		n = (long int)n;
	else if (f.type == FT_LL)
		n = (long long int)n;
	else
		n = (int)n;
	f.zero = (f.precision) ? (0) : (f.zero);
	nbr = ft_itoa_base(n, 10, "0123456789");
	len = ft_strlen(nbr);
	f.precision = (len > f.precision) ? (len) : (f.precision);
	f.precision += f.plus || (n < 0);
	f.width = (f.width > f.precision) ? (f.width) : (f.precision);
	if (!(str = malloc((f.width + 1) * sizeof(*str))))
		exit(1);
	ft_strfill(str, nbr, f, len);
	write(1, str, f.width);
	return (f.width);
}
