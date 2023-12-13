/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:32:55 by mohtakra          #+#    #+#             */
/*   Updated: 2022/10/31 03:16:57 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*templst;

	if (lst && del)
	{
		templst = *lst;
		while (templst)
		{
			temp = templst->next;
			ft_lstdelone(templst, del);
			templst = NULL;
			templst = temp;
		}
		*lst = NULL;
	}
}
