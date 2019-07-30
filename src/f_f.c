#include "ft_printf.h"

typedef struct		s_parsed_float
{
  unsigned			m	: 52;
  unsigned			e	: 11;
  unsigned			s	: 1;
}					t_parsed_float;

typedef union		u_float
{
  t_parsed_float	parse;
  float				val;
}					t_float;

typedef struct		s_float_ip;
{
	unsigned int	i;
	int				i_len;
	unsigned int	f;
	int				f_len;
}					t_float_ip;

int		count_len(unsigned int a)
{
	int		i;

	i = -1;
	while (++i < 52)
		if (a & (1 << i))
			break ;
	return (52 - i);
}

void	apa_fill_i(char *str, unsigned int m, int len, int k)
{
	
}

void	apa_fill_f(char *str, unsigned int m, int len, int k)
{
	
}

char	*apa_float(t_float_parse f)
{
	t_float_ip	parts;
	int			k;
	char		*str;
	int			il;
	double		buf;

	if (!(~pf.e))
	{
		if (pf.m)
			return ("NaN");
		if (pf.s)
			return ("-inf");
		else
			return ("inf");
	}
	k = f.parse.e - 1023;
	if (k > 52)
	{
		parts.i = pf.m | (1 << 52);
		parts.i_len = 53;
		parts.f = 0;
		parts.f_len = 0;
		k -= 52;
	}
	else if (k < 0)
	{
		parts.i = 0;
		parts.i_len = 0;
		parts.f_len = count_len(pf.m);
		parts.f = (pf.m >> (52 - parts.i_len)) | (1 << parts.i_len);
		k += ++parts.f_len;
	}
	else // 0 <= k <= 52
	{
		parts.i = (pf.m >> (52 - k)) | (1 << (k));
		parts.i_len = k + 1;
		parts.f_len = count_len(pf.m) - k;
		parts.f = (pf.m << k) >> (52 - parts.i_len);
		k = 0;
	}
	buf = parts.i_len * 0.30103;
	il = (int)buf + !!(buf - (int)buf);
	if (!(str = malloc((il + 1 + parts.f_len + 1) * sizeof(char))))
		return (NULL);
	apa_fill_i(str, parts.i, parts.i_len, k);
	str[il] = '.';
	apa_fill_f(str + il + 1, parts.f, parts.f_len, k);
	str[il + 1 + parts.f_len] = 0;
	return (str);
}

int		f_f(va_list ap, t_format f)
{
	double	n;
	char	*nbr;
	char	*str;
	int		len;

	n = va_arg(ap, double);
	nbr = apa_float((t_float_parse)n);
	len = ft_strlen(nbr) - 1;
}
