/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:06:24 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:06:24 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[--end]) && end >= start)
		;
	res = ft_strnew(end - start + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (start <= end)
		res[++i] = s[start++];
	return (res);
}
