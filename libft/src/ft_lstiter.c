/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:57:08 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 12:57:08 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*now;
	t_list	*temp;

	if (!lst || !f)
		return ;
	now = lst;
	while (now)
	{
		temp = now->next;
		(*f)(now);
		now = temp;
	}
}
