/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_node	*list_remove_at(t_list *list, uint64_t index)
{
	t_node	*parent;
	t_node	*child;

	if (list_is_empty(list))
		return (NULL);
	if (index == 0)
		return (list_remove_front(list));
	if (index >= list->size)
		return (list_remove_back(list));
	parent = node_get_nchild(list->head, index - 1);
	child = node_remove_child(parent);
	list->size -= 1;
	return (child);
}
