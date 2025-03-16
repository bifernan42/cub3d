/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_insert_at(t_list *self, t_node *node, uint64_t index)
{
	t_node	*temp;

	if (index == 0 || list_is_empty(self))
		list_insert_front(self, node);
	else if (index >= self->size)
		list_insert_back(self, node);
	else
	{
		temp = node_get_nchild(self->head, index - 1);
		node_insert_child(temp, node);
		self->size += 1;
	}
}
