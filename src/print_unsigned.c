/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:47:04 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:47:04 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ltoa_sizet(size_t n)
{
	int		i;
	int		l;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	l = ft_nbrlen_base(n, 10);
	res = ft_strnew(l);
	while (n)
	{
		res[--l] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

int			print_unsigned(unsigned long long int n, t_token *tok)
{
	char	*str;
	int		res;

	tok->flags = tok->flags & (~F_SPACE);
	tok->flags = tok->flags & (~F_PLUS);
	if ((tok->flags & F_HH) == F_HH)
		str = ft_ltoa_sizet((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		str = ft_ltoa_sizet((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		str = ft_ltoa_sizet((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		str = ft_ltoa_sizet((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		str = ft_ltoa_sizet((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		str = ft_ltoa_sizet((size_t)n);
	else
		str = ft_ltoa_sizet((unsigned int)n);
	if (!str)
		return (0);
	res = print_number(str, tok, 1);
	free(str);
	return (res);
}
