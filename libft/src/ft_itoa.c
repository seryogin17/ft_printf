/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:56:15 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:56:15 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	int		sign;

	sign = (n >= 0) ? 1 : -1;
	i = ft_nbrlen(n) + ((sign > 0) ? 0 : 1);
	if (!(res = ft_strnew(i)))
		return (NULL);
	sign < 0 ? res[0] = '-' : 0;
	n == 0 ? res[0] = '0' : 0;
	while (n)
	{
		i--;
		res[i] = ((long)n * sign) % 10 + 48;
		n /= 10;
	}
	return (res);
}
