/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:05:58 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:05:58 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		;
	if (c == '\0')
		return ((char *)(s + i));
	while (--i >= 0)
		if (s[i] == c)
			return ((char *)(s + i));
	return (NULL);
}
