/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:11:11 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:45 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*current_ele;

	current_ele = list;
	if (!current_ele)
		return (current_ele);
	while (current_ele->next)
		current_ele = current_ele->next;
	return (current_ele);
}
