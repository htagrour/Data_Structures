/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:01:07 by fsarbout          #+#    #+#             */
/*   Updated: 2021/04/05 16:56:25 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *list);
t_list			*ft_lstlast(t_list *list);
void			ft_lstadd_back(t_list **list, t_list *new);
void			ft_lstdelone(t_list **list, void (*del)(void*));
void			ft_lstiter(t_list *list, void (*f)(void*), int dir);
t_list			*ft_lstmap(t_list *list, void *(*f)(void*), void (*del)(void*));
int				ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*copy_list(t_list *lst);

#endif
