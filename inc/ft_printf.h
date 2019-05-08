/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:48:46 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:48:46 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/inc/libft.h"

# define S_CHAR 'c'
# define S_STRING 's'
# define S_POINTER 'p'
# define S_PERCENT '%'
# define S_DECIMAL 'd'
# define S_INTEGER 'i'
# define S_OCTAL 'o'
# define S_UNSIGNED 'u'
# define S_HEX 'x'
# define S_BHEX 'X'
# define S_FLOAT 'f'

# define F_MINUS (1 << 0)
# define F_ZERO (1 << 1)
# define F_PLUS (1 << 2)
# define F_SHARP (1 << 3)
# define F_SPACE (1 << 4)

# define F_HH (1 << 5)
# define F_H (1 << 6)
# define F_L (1 << 7)
# define F_LL (1 << 8)
# define F_J (1 << 9)
# define F_Z (1 << 10)
# define F_BL (1 << 11)

typedef	struct	s_token
{
	char		spec;
	char		width;
	char		precision;
	int			flags;
}				t_token;

typedef	struct	s_double
{
	char		sign;
	int			exponent;
	char		*mantissa;
}				t_double;

typedef	struct	s_ldouble
{
	char		sign;
	int			exponent;
	char		*mantissa;
}				t_ldouble;

int				ft_printf(const char *f, ...);

int				process_token(const char *f, int *i, va_list ap);

int				print_char(char c, t_token *tok);
int				print_string(char *s, t_token *tok);
int				print_no_flag(char *str, int w, int p, char c);
int				print_with_flag(char *str, int w, int p, char c);
int				print_pointer(unsigned long long int n, t_token *tok);
int				print_decimal(long long int n, t_token *tok);
int				print_number(char *str, t_token *tok, int sign);
int				print_octal(size_t n, t_token *tok);
int				print_hex(size_t n, t_token *tok);
int				print_bhex(size_t n, t_token *tok);
int				print_unsigned(unsigned long long int n, t_token *tok);
int				print_double(double n, t_token *tok);
int				print_ldouble(long double n, t_token *tok);
char			*str_div2(char **str);
char			*str_add_fraction(char **s1, char *s2);
char			*str_add_int(char **s1, char *s2, int flag);
char			*get_frac_from_bin(char *s);
char			*get_int_from_bin(char *s);
char			*dbl_to_str(double d);
char			*ldbl_to_str(long double d);
char			*round_dbl(char **s, int p);

#endif
