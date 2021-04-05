/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:17:57 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:41 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = malloc(sizeof(t_list));
	if (!tab)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	tab->prev = NULL;
	return (tab);
}
