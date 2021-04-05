/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 08:54:59 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:34 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lstsize(t_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
