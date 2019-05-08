/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:50 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:50 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long int n, t_token *tok)
{
	char	*temp1;
	char	*temp2;
	int		l;

	tok->flags = tok->flags | F_SHARP;
	if (tok->precision == -1)
		l = 1;
	else if (tok->precision == 0)
		l = 0;
	else
		l = tok->precision;
	if (n == 0)
	{
		tok->flags = tok->flags & (~F_PLUS);
		tok->flags = tok->flags & (~F_SPACE);
		tok->precision = -1;
		temp1 = ft_nchjoinstr("", '0', l);
		temp2 = ft_strjoin("0x", temp1);
		free(temp1);
		l = print_number(temp2, tok, 1);
		free(temp2);
		return (l);
	}
	tok->flags = tok->flags | F_LL;
	return (print_hex(n, tok));
}
