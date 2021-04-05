/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:31:21 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:47 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstiter(t_list *list, void (*f)(void*), int dir)
{
	t_list	*tem;

	if (f && list)
	{
		if (dir)
			tem = list;
		else
			tem = ft_lstlast(list);
		while (tem)
		{
			(*f)(tem->content);
			if (dir)
				tem = tem->next;
			else
				tem = tem->prev;
		}
	}
}
