/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:58:44 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:58:44 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*now;
	int		i;

	if (len == 0)
		return (b);
	now = (char *)b;
	i = -1;
	while (++i < (int)len)
		now[i] = c;
	return (b);
}
