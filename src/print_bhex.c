/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:37:55 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:37:55 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ltoa_sizet_hex(size_t n)
{
	char	*hex;
	int		i;
	int		l;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	hex = "0123456789ABCDEF";
	l = ft_nbrlen_base(n, 16);
	res = ft_strnew(l);
	while (n)
	{
		res[--l] = hex[n % 16];
		n /= 16;
	}
	return (res);
}

static size_t	cast_to_flag(size_t n, t_token *tok)
{
	if ((tok->flags & F_HH) == F_HH)
		return ((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		return ((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		return ((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		return ((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		return ((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		return ((size_t)n);
	return ((unsigned int)n);
}

static void		parse_if(size_t n, t_token *tok, char **str, int l)
{
	char	*temp;

	if (tok->precision > l)
	{
		temp = ft_nchjoinstr(*str, '0', tok->precision - l);
		free(*str);
		*str = temp;
		tok->flags = tok->flags & (~F_ZERO);
	}
	if ((tok->flags & F_ZERO) == F_ZERO && tok->precision == -1 && n != 0 &&
		(tok->flags & F_MINUS) != F_MINUS)
	{
		temp = ft_nchjoinstr(*str, '0', tok->width - l -
			((tok->flags & F_SHARP) == F_SHARP) * 2);
		free(*str);
		*str = temp;
	}
	if ((tok->flags & F_SHARP) == F_SHARP && n != 0)
	{
		temp = ft_strjoin("0X", *str);
		free(*str);
		*str = temp;
		tok->flags = tok->flags & (~F_ZERO);
	}
}

int				print_bhex(size_t n, t_token *tok)
{
	char	*str;
	int		res;

	tok->flags = tok->flags & (~F_PLUS);
	tok->flags = tok->flags & (~F_SPACE);
	if (n == 0 && tok->precision == 0)
		return (print_number("", tok, 1));
	if (!(str = ft_ltoa_sizet_hex(cast_to_flag(n, tok))))
		return (0);
	parse_if(n, tok, &str, ft_strlen(str));
	tok->precision = -1;
	res = print_number(str, tok, 1);
	free(str);
	return (res);
}
