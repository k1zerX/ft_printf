#include "ft_printf.h"

typedef struct		s_parsed_float
{
  unsigned long		m	: 52;
  unsigned long		e	: 11;
  unsigned long		s	: 1;
}					t_parsed_float;

typedef union		u_float
{
  t_parsed_float	parse;
  double			val;
}					t_float;

typedef struct		s_float_ip
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

char	*pow5(int i, int len, int k)
{
	static char		**arr = NULL;
	int				j;

	k = (k < 0) ? (-k) : (0);
	if (!arr)
	{
		if (!(arr = malloc(len * sizeof(char *))))
			exit(1);
		j = -1;
		while (++j < len)
			if (!(arr[j] = malloc((k + len) * sizeof(char))))
				exit(1);
	}
}

char	*pow2(int i, int len, int k)
{
	static char		**arr = NULL;
	int				j;

	k = (k > 0) ? (k) : (0);
	if (!arr)
	{
		if (!(arr = malloc(len * sizeof(char *))))
			exit(1);
		j = -1;
		while (++j < len)
			if (!(arr[j] = malloc((k + len) * sizeof(char))))
				exit(1);
	}
	arr[0] = 0;
}

void	apa_fill_i(char *str, unsigned int m, int len, int k)
{
	return ;
}

void	apa_fill_f(char *str, unsigned int m, int len, int k)
{
	return ;
}

char	*apa_float(double n)
{
	t_float		f;
	t_float_ip	parts;
	int			k;
	char		*str;
	int			il;
	double		buf;

	f.val = n;
	if (!(~f.parse.e))
	{
		if (f.parse.m)
			return ("NaN");
		if (f.parse.s)
			return ("-inf");
		else
			return ("inf");
	}
	k = f.parse.e - 1023;
	if (k > 52)
	{
		parts.i = f.parse.m | ((unsigned long)1 << 52);
		parts.i_len = 53;
		parts.f = 0;
		parts.f_len = 0;
		k -= 52;
	}
	else if (k < 0)
	{
		parts.i = 0;
		parts.i_len = 0;
		parts.f_len = count_len(f.parse.m);
		parts.f = (f.parse.m >> (52 - parts.i_len)) | ((unsigned long)1 << parts.i_len);
		k += ++parts.f_len;
	}
	else // 0 <= k <= 52
	{
		parts.i = (f.parse.m >> (52 - k)) | ((unsigned long)1 << (k));
		parts.i_len = k + 1;
		parts.f_len = count_len(f.parse.m) - k;
		parts.f = (f.parse.m << k) >> (52 - parts.i_len);
		k = 0;
	}
	il = (int)((parts.i_len + ((k < 0) ? (0) : (k))) * 0.30103) + 1;
	printf("len: %d | %ld %ld %ld |\n", il, f.parse.s, f.parse.e, f.parse.m);
	if (!(str = malloc((1 + il + 1 + parts.f_len + 1) * sizeof(char))))
		exit(1);
	str[0] = (f.parse.s) ? '-' : '+';
	apa_fill_i(str + 1, parts.i, parts.i_len, k);
	str[1 + il] = '.';
	apa_fill_f(str + 1 + il + 1, parts.f, parts.f_len, k);
	str[1 + il + 1 + parts.f_len] = 0;
	return (str);
}

int		f_f(va_list ap, t_format f)
{
	double	n;
	char	*nbr;
	char	*str;
	int		len;

	n = va_arg(ap, double);
	nbr = apa_float(n);
	len = ft_strlen(nbr);
//	write(1, nbr, len);
	return (len);
}
