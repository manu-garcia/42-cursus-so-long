/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:37:47 by manu              #+#    #+#             */
/*   Updated: 2022/04/13 19:29:41 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	next = *lst;
	while (next)
	{
		tmp = next->next;
		ft_lstdelone(next, del);
		next = tmp;
	}
	*lst = NULL;
}
