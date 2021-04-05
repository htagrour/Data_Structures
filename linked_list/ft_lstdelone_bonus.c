/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:40:20 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:50 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{	
	t_list	*temp;

	if (*lst && del)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
		if (*lst)
			(*lst)->prev = NULL;
	}
}
