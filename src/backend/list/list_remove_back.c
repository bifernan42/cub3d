/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:59:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:59:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_node	*list_remove_back(t_list *list)
{
	t_node	*node;

	if (list_is_empty(list))
		return (NULL);
	node = list->tail;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail = node->prev;
		list->tail->next = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	list->size -= 1;
	return (node);
}
