/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:06:17 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:06:17 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = ft_strnew(len);
	if (!s || !res || len > (size_t)ft_strlen(s))
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start + i];
	return (res);
}
