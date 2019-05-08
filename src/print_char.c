/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:18 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:18 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(char c, t_token *tok)
{
	int		i;
	int		w;

	w = tok->width;
	i = 1;
	if (w < 2)
		return (ft_putchar(c));
	if ((tok->flags & F_MINUS) == F_MINUS)
	{
		ft_putchar(c);
		while (i < w)
			i += ft_putchar((tok->flags & F_ZERO) == F_ZERO &&
				(tok->flags & F_MINUS) != F_MINUS ? '0' : ' ');
	}
	else
	{
		while (i < w)
			i += ft_putchar((tok->flags & F_ZERO) == F_ZERO &&
				(tok->flags & F_MINUS) != F_MINUS ? '0' : ' ');
		ft_putchar(c);
	}
	return (i);
}
