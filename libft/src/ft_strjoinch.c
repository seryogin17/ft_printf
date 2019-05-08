/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:04:04 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:04:04 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char **str, char c)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strnew(ft_strlen(*str) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, *str);
	res = ft_strncat(res, &c, 1);
	free(*str);
	*str = NULL;
	return (res);
}
