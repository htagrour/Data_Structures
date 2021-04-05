/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:28:41 by htagrour          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:59 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last_one;

	if (*list)
	{
		last_one = ft_lstlast(*list);
		new->prev = last_one;
		last_one->next = new;
		new->next = NULL;
	}
	else
		*list = new;
}
