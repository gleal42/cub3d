/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:34:20 by gleal             #+#    #+#             */
/*   Updated: 2021/02/10 23:25:35 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*deleter;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		deleter = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(deleter, del);
	}
	*lst = 0;
}
