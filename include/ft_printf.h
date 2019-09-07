/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:39:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/09/07 23:03:28 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FT_HH	-2
# define FT_H	-1
# define FT_L	1
# define FT_LL	2
# define M_LEN	64
# define E_LEN	15

typedef struct		s_format
{
	unsigned char	sharp	: 1;
	unsigned char	zero	: 1;
	unsigned char	minus	: 1;
	unsigned char	plus	: 1;
	unsigned char	space	: 1;
	unsigned char	l_big	: 1;
	int				width;
	int				precision;
	char			type;
}					t_format;

typedef struct		s_conv
{
	char			conv;
	int				(*f)(va_list ap, t_format f);
}					t_conv;

typedef struct		s_parsed_float
{
	unsigned long	m	: M_LEN;
	unsigned short	e	: E_LEN;
	unsigned short	s	: 1;
}					t_parsed_float;

typedef union		u_float
{
	t_parsed_float	parse;
	long double		val;
}					t_float;

typedef struct		s_float_ip
{
	unsigned long	i;
	int				i_len;
	unsigned long	f;
	int				f_len;
}					t_float_ip;

char				*ft_ultra_itoa(long long int n, int base, \
		char is_signed, const char *digits);
t_format			format(const char *restrict format, int len);
void				reformat(t_format *f, const char *restrict format);
int					count_len(unsigned long a);
void				apa_mul(int power, unsigned char *str, int len, int *l);
char				*apa_float(long double n);
void				ft_intfill(char *str, char *nbr, t_format f, int len);
void				ft_strfill(char *str, char *s, t_format f, int len);
int					ft_strlen(char *str);
int					ft_ascii(char *s, t_format f);
int					f_percent(va_list ap, t_format f);
int					f_s(va_list ap, t_format f);
int					f_c(va_list ap, t_format f);
int					f_p(va_list ap, t_format f);
int					f_d(va_list ap, t_format f);
int					f_i(va_list ap, t_format f);
int					f_o(va_list ap, t_format f);
int					f_u(va_list ap, t_format f);
int					f_x(va_list ap, t_format f);
int					f_big_x(va_list ap, t_format f);
int					f_f(va_list ap, t_format f);
int					ft_printf(const char *restrict str, ...);
void				ft_bzero(void *ptr, size_t size);
int					mini_atoi(const char *restrict *format, int *len);
char				ft_isdigit(char c);
int					itoa_len(unsigned long long int nbr, int base);
char				*ft_strcpy(char *dst, const char *src);
int					ft_find_dot(char *str);
void				ft_treatment(char *nbr);

#endif
