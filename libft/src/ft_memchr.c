/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:57:53 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:57:53 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ns;
	size_t			i;

	i = -1;
	ns = (unsigned char *)s;
	while (++i < n)
		if (ns[i] == (unsigned char)c)
			return (ns + i);
	return (NULL);
}
