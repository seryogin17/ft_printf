/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:37:45 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:37:45 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <inttypes.h>

int		ft_printf(const char *f, ...)
{
	int		i;
	int		k;
	int		res;
	va_list	ap;

	i = -1;
	res = 0;
	k = 0;
	va_start(ap, f);
	while (f[++i])
	{
		if (f[i] == '%')
			res += process_token(f + i + 1, &i, ap);
		else
		{
			k = ft_putstr_until((char *)f + i, '%');
			res += k;
			i += k - 1;
		}
	}
	va_end(ap);
	return (res);
}
