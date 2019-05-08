/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:59:30 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:59:30 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int n, int fd)
{
	int	t;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		return (ft_putnbr_fd(-n, fd) + 1);
	}
	else if (n > 9)
	{
		t = ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
		return (t + 1);
	}
	ft_putchar_fd(n + 48, fd);
	return (1);
}
