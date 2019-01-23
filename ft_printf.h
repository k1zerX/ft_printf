/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:39:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/23 20:23:44 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libc.h>
# include "libft.h"

typedef struct	s_conv
{
	char		conv;
	char		*(*f)(va_list ap);
}				t_conv;

typedef struct	s_format
{
	char		flags;
	int			width;
	int			precision;
}				t_format;

int			ft_printf(const char *restrict str, ...);
t_format	format(va_list ap, const char *restrict format, int len);
int			ft_print(t_format f, char *str);

char		*f_c(va_list ap, t_format format);
char		*f_s(va_list ap, t_format format);
char		*f_p(va_list ap, t_format format);
char		*f_di(va_list ap, t_format format);
char		*f_o(va_list ap, t_format format);
char		*f_u(va_list ap, t_format format);
char		*f_x(va_list ap, t_format format);
char		*f_big_x(va_list ap, t_format format);/*
char		*f_f(va_list ap, const char *restrict str, int len);
char		*f_e(va_list ap, const char *restrict str, int len);
char		*f_g(va_list ap, const char *restrict str, int len);
char		*f_b(va_list ap, const char *restrict str, int len);
char		*f_r(va_list ap, const char *restrict str, int len);
char		*f_k	(va_list ap, const char *restrict str, int len);*/
char		*f(va_list ap);

#endif
