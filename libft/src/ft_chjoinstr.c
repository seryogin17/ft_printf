/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chjoinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:55:29 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:55:29 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chjoinstr(char c, char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	if (c == '\0')
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	res[0] = c;
	while (str[i])
	{
		res[i + 1] = str[i];
		i++;
	}
	return (res);
}
