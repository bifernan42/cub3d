/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:59:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:59:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_node	*list_remove_front(t_list *list)
{
	t_node	*node;

	if (list_is_empty(list))
		return (NULL);
	node = list->head;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head = node->next;
		list->head->prev = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	list->size -= 1;
	return (node);
}
