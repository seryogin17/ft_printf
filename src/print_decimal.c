/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:23 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:23 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(long long int n, t_token *tok)
{
	char	*str;
	int		d;

	if ((tok->flags & F_HH) == F_HH)
		str = ft_ltoa_base((char)n, 10);
	else if ((tok->flags & F_H) == F_H)
		str = ft_ltoa_base((short)n, 10);
	else if ((tok->flags & F_L) == F_L)
		str = ft_ltoa_base((long)n, 10);
	else if ((tok->flags & F_LL) == F_LL)
		str = ft_ltoa_base((long long)n, 10);
	else if ((tok->flags & F_J) == F_J)
		str = ft_ltoa_base((intmax_t)n, 10);
	else if ((tok->flags & F_Z) == F_Z)
		str = ft_ltoa_base((size_t)n, 10);
	else
		str = ft_ltoa_base((int)n, 10);
	d = print_number(str, tok, str[0] != '-');
	free(str);
	return (d);
}
