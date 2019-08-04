/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:39:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/08/04 18:04:54 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
//# include <libc.h>
# include <unistd.h>
# include <stdlib.h>

#define FT_HH	-2
#define FT_H	-1
#define FT_L	1
#define FT_LL	2

typedef struct		s_format
{
	unsigned char	sharp : 1;
	unsigned char	zero : 1;
	unsigned char	minus : 1;
	unsigned char	plus : 1;
	unsigned char	space : 1;
	int				width;
	int				precision;
	char			type;
}					t_format;

typedef struct		s_conv
{
	char			conv;
	int				(*f)(va_list ap, t_format f);
}					t_conv;

char		*ft_ultra_itoa(long long int n, int base, char is_signed, const char *digits);
t_format	format(const char *restrict format, int len);
void		reformat(t_format *f, const char *restrict format);
void		ft_intfill(char *str, char *nbr, t_format f, int len);
void		ft_strfill(char *str, char *s, t_format f, int len);
int			ft_strlen(char *str);
int			ft_ascii(char *s, t_format f);
int			f_percent(va_list ap, t_format f);
int			f_s(va_list ap, t_format f);
int			f_c(va_list ap, t_format f);
int			f_p(va_list ap, t_format f);
int			f_d(va_list ap, t_format f);
int			f_i(va_list ap, t_format f);
int			f_o(va_list ap, t_format f);
int			f_u(va_list ap, t_format f);
int			f_x(va_list ap, t_format f);
int			f_big_x(va_list ap, t_format f);
int			f_f(va_list ap, t_format f);
int			ft_printf(const char *restrict str, ...);
void		ft_bzero(void *ptr, size_t size);
int			mini_atoi(const char *restrict *format, int *len);
char		ft_isdigit(char c);
int		itoa_len(unsigned long long int nbr, int base);
#endif
