/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:59:20 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:59:20 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
	write(fd, "\n", 1);
	return (i + 1);
}
