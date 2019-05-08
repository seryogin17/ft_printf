/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:47:15 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:47:15 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			begin_flag(char c)
{
	if (c == '-')
		return (F_MINUS);
	if (c == '0')
		return (F_ZERO);
	if (c == '+')
		return (F_PLUS);
	if (c == '#')
		return (F_SHARP);
	if (c == ' ')
		return (F_SPACE);
	return (0);
}

int			length_flag(const char *f, int *i)
{
	if ((f[*i] == 'h' && f[*i + 1] == 'h') ||
		(f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		*i += 2;
		return (f[*i - 1] == 'h' ? F_HH : F_LL);
	}
	else if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z' ||
		f[*i] == 'L')
	{
		*i += 1;
		if (f[*i - 1] == 'h')
			return (F_H);
		if (f[*i - 1] == 'l')
			return (F_L);
		if (f[*i - 1] == 'j')
			return (F_J);
		if (f[*i - 1] == 'z')
			return (F_Z);
		if (f[*i - 1] == 'L')
			return (F_BL);
	}
	return (0);
}

int			parse_token(const char *f, t_token *tok)
{
	int	i;
	int	flag;

	i = 0;
	while (f[i] && (flag = begin_flag(f[i])))
	{
		tok->flags = tok->flags | flag;
		i++;
	}
	while (f[i] && ft_isdigit(f[i]))
	{
		tok->width = tok->width * 10 + f[i] - '0';
		i++;
	}
	if (f[i] == '.')
		while (f[++i] && ft_isdigit(f[i]))
			tok->precision == -1 ? (tok->precision = f[i] - '0') :
				(tok->precision = tok->precision * 10 + f[i] - '0');
	if (f[i - 1] == '.' && tok->precision == -1)
		tok->precision = 0;
	if ((flag = length_flag(f, &i)))
		tok->flags = tok->flags | flag;
	tok->spec = f[i];
	return (i);
}

static int	process_token2(va_list ap, t_token *tok)
{
	if (tok->spec == S_BHEX)
		return (print_bhex(va_arg(ap, size_t), tok));
	else if (tok->spec == S_UNSIGNED)
		return (print_unsigned(va_arg(ap, unsigned long long int), tok));
	else if (tok->spec == S_FLOAT && (tok->flags & F_BL) != F_BL)
		return (print_double(va_arg(ap, double), tok));
	else if (tok->spec == S_FLOAT && (tok->flags & F_BL) == F_BL)
		return (print_ldouble(va_arg(ap, long double), tok));
	return (0);
}

int			process_token(const char *f, int *i, va_list ap)
{
	t_token	tok;

	tok.width = 0;
	tok.precision = -1;
	tok.flags = 0;
	*i += parse_token(f, &tok) + 1;
	if (tok.spec == S_CHAR)
		return (print_char(va_arg(ap, int), &tok));
	else if (tok.spec == S_STRING)
		return (print_string(va_arg(ap, char *), &tok));
	else if (tok.spec == S_POINTER)
		return (print_pointer(va_arg(ap, unsigned long long int), &tok));
	else if (tok.spec == S_PERCENT)
		return (print_char('%', &tok));
	else if (tok.spec == S_DECIMAL || tok.spec == S_INTEGER)
		return (print_decimal(va_arg(ap, long long int), &tok));
	else if (tok.spec == S_OCTAL)
		return (print_octal(va_arg(ap, unsigned long), &tok));
	else if (tok.spec == S_HEX)
		return (print_hex(va_arg(ap, size_t), &tok));
	return (process_token2(ap, &tok));
}
