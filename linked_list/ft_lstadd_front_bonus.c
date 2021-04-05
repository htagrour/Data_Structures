/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:08:02 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:56 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*copy_list(t_list *lst)
{
	t_list	*copy;

	while (lst && lst->prev)
		lst = lst->prev;
	copy = NULL;
	while (lst)
	{
		ft_lstadd_back(&copy, ft_lstnew(ft_strdup(lst->content)));
		lst = lst->next;
	}
	return (copy);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
	{
		(*alst)->prev = new;
		new->next = *alst;
	}
	*alst = new;
}
