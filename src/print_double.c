/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:30 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:30 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*round_dbl(char **s, int p)
{
	int		i;
	int		prev;
	char	*tmp;

	i = ft_strchr(*s, '.') - *s + p + 1;
	prev = (*s)[i] >= '5' ? 1 : 0;
	(*s)[i] = '\0';
	while (--i >= 0)
	{
		if ((*s)[i] == '.')
			continue ;
		(*s)[i] += (*s)[i + 1] >= '5' ? 1 : 0 + prev;
		if ((prev = (*s)[i] > '9'))
			(*s)[i] -= 10;
		if (!prev)
			break ;
	}
	if (prev)
	{
		tmp = ft_chjoinstr('1', *s);
		free(*s);
		*s = tmp;
	}
	return (*s);
}

static void	str_replace(char **s, char *tmp)
{
	free(*s);
	*s = tmp;
}

int			print_double(double n, t_token *tok)
{
	char	*s;
	char	*tmp;
	int		l;

	tok->precision == -1 ? tok->precision = 6 : (0);
	s = dbl_to_str(n);
	l = ft_strlen(ft_strchr(s, '.')) - 1;
	if (tok->precision == 0 && (tok->flags & F_SHARP) != F_SHARP)
		ft_strchr(s, '.')[0] = '\0';
	if (l < tok->precision)
	{
		tmp = ft_strjoinnch(s, '0', tok->precision - l);
		str_replace(&s, tmp);
	}
	else
		s = round_dbl(&s, tok->precision);
	if (n < 0)
	{
		tmp = ft_chjoinstr('-', s);
		str_replace(&s, tmp);
	}
	tok->precision = -1;
	l = print_number(s, tok, n > 0);
	free(s);
	return (l);
}

int			print_ldouble(long double n, t_token *tok)
{
	char	*s;
	char	*tmp;
	int		l;

	tok->precision == -1 ? tok->precision = 6 : (0);
	s = ldbl_to_str(n);
	l = ft_strlen(ft_strchr(s, '.')) - 1;
	if (tok->precision == 0 && (tok->flags & F_SHARP) != F_SHARP)
		ft_strchr(s, '.')[0] = '\0';
	if (l < tok->precision)
	{
		tmp = ft_strjoinnch(s, '0', tok->precision - l);
		str_replace(&s, tmp);
	}
	else
		s = round_dbl(&s, tok->precision);
	if (n < 0)
	{
		tmp = ft_chjoinstr('-', s);
		str_replace(&s, tmp);
	}
	tok->precision = -1;
	l = print_number(s, tok, n > 0);
	free(s);
	return (0);
}
