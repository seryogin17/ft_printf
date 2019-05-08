/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:06:05 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 13:06:05 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char **str, size_t n)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strsub(*str, n, ft_strlen(*str) - n);
	if (!res)
		return (NULL);
	free(*str);
	*str = NULL;
	return (res);
}
