/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:58 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:58 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_with_flag(char *str, int w, int p, char c)
{
	int	i;

	i = 0;
	if (p == -1)
	{
		i += ft_putstr(str);
		while (i < w)
			i += ft_putchar(c);
	}
	else
	{
		while (i < p && str[i])
			ft_putchar(str[i++]);
		while (i < w)
			i += ft_putchar(c);
	}
	return (i);
}

int		print_no_flag(char *str, int w, int p, char c)
{
	int	i;
	int	j;
	int	l;
	int	len;

	len = ft_strlen(str);
	l = (p == -1) ? len : p;
	if (p != -1)
		l = (len > p) ? p : len;
	i = 0;
	while (w - i > l)
		i += ft_putchar(c);
	j = -1;
	while (str[++j] && j < l)
		i += ft_putchar(str[j]);
	return (i);
}

int		print_string(char *s, t_token *tok)
{
	int	w;
	int	p;
	int	i;

	w = tok->width;
	p = tok->precision;
	if (!s)
	{
		return (((tok->flags & F_MINUS) != F_MINUS) ?
			print_no_flag("(null)", w, p, ' ') :
			print_with_flag("(null)", w, p, ' '));
	}
	i = 0;
	if ((tok->flags & F_MINUS) != F_MINUS)
		return (print_no_flag(s, w, p, ' '));
	else
		return (print_with_flag(s, w, p, ' '));
}
