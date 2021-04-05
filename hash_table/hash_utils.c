/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htagrour <htagrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:33:00 by fsarbout          #+#    #+#             */
/*   Updated: 2021/04/05 16:47:40 by htagrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"
/*
char	**hash_to_arr(t_hash_map *hm, int flag)
{
	char	**tab;
	t_list	*temp;
	int		i;
	int		size;

	i = 0;
	size = hm->size;
	tab = malloc(sizeof(char*) * (hm->elem_total + 1));
	while (--size >= 0)
	{
		temp = hm->item[size];
		while (temp)
		{
			if (temp->key && strcmp(temp->key, "?"))
			{
				if (flag)
					tab[i++] = strdup(temp->key);
				else
					key_value(temp->key, temp->value, &tab[i], &i);
			}
			temp = temp->next;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**sorted_key(t_hash_map *hm)
{
	char	**tab;

	tab = hash_to_arr(hm, 1);
	if (!tab)
		return (NULL);
	bubblesort(tab, hm->elem_total - 1);
	return (tab);
}*/

int	free_hash_map(t_hash_map *hm)
{
	t_list	*temp;
	t_list	*temp1;

	while (--hm->size >= 0)
	{
		temp = hm->item[hm->size];
		while (temp)
		{
			temp1 = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = temp1;
		}
		hm->item[hm->size] = NULL;
	}
	free(hm->item);
	free(hm);
	return (1);
}

unsigned int	hash(const char *str, int size)
{
	unsigned int	hash;

	hash = 0;
	while (str && *str)
	{
		hash = (hash + *str) % size;
		str++;
	}
	return (hash);
}

t_hash_map	*init_hash_map(int size)
{
	t_hash_map	*hm;

	hm = malloc(sizeof(t_hash_map));
	if (!hm)
		return (NULL);
	hm->item = malloc(sizeof(t_list*) * size);
	if (hm->item == NULL)
		return (NULL);
	bzero(hm->item, sizeof(t_list*) * size);
	hm->size = size;
	hm->elem_total = 0;
	return (hm);
}
