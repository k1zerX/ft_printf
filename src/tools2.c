/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:15:28 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/04 18:04:07 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ultra_itoa(long long int n, int base, char is_signed, \
		const char *digits)
{
	char					*str;
	int						len;
	char					sign;
	unsigned long long int	nbr;

	if (base < 2)
		return (NULL);
	if (is_signed && (sign = n < 0))
		nbr = ~(unsigned long long int)n + 1;
	else
		nbr = n;
	len = itoa_len(nbr, base) + 1;
	if ((str = malloc((len + 1) * sizeof(*str))))
	{
		str[len] = 0;
		str[0] = (sign) ? ('-') : ('+');
		str[--len] = digits[nbr % base];
		while ((nbr /= base) > 0)
			str[--len] = digits[nbr % base];
	}
	return (str);
}

void		ft_intfill(char *str, char *nbr, t_format f, int len)
{
	int		i;
	int		j;

	str[f.width + f.precision + len] = 0;
	j = 0;
	i = -1;
	if (!f.minus && !f.zero)
		while (++i < f.width)
			str[j++] = ' ';
	if (f.plus)
		str[j++] = *nbr;
	i = -1;
	if (!f.minus && f.zero)
		while (++i < f.width)
			str[j++] = '0';
	i = -1;
	while (++i < f.precision)
		str[j++] = '0';
	i = -1;
	while (++i < len)
		str[j++] = *(++nbr);
	i = -1;
	if (f.minus)
		while (++i < f.width)
			str[j++] = ' ';
}

void		ft_strfill(char *str, char *s, t_format f, int len)
{
	int		i;
	int		j;
	char	c;

	str[f.width + len] = 0;
	c = (f.zero) ? ('0') : (' ');
	j = 0;
	i = -1;
	if (!f.minus)
		while (++i < f.width)
			str[j++] = c;
	i = -1;
	while (++i < len)
		str[j++] = *(s++);
	i = -1;
	if (f.minus)
		while (++i < f.width)
			str[j++] = c;
}

void		reformat(t_format *f, const char *restrict format)
{
	if (*format == '-')
		f->minus = 1;
	else if (*format == '+')
		f->plus = 1;
	else if (*format == ' ')
		f->space = 1;
	else if (*format == 'l')
		++(f->type);
	else if (*format == 'h')
		--(f->type);
}

t_format	format(const char *restrict format, int len)
{
	t_format	f;

	ft_bzero(&f, sizeof(f));
	f.precision = -1;
	while (--len >= 0)
	{
		if (*format == '#')
			f.sharp = 1;
		else if (*format == '.')
		{
			++format;
			--len;
			f.precision = mini_atoi(&format, &len);
		}
		else if (*format == '0')
			f.zero = 1;
		else if (ft_isdigit(*format))
			f.width = mini_atoi(&format, &len);
		else if (*format == '-' || *format == '+' || *format == ' ' || \
				*format == 'l' || *format == 'h')
			reformat(&f, format);
		++format;
	}
	return (f);
}
