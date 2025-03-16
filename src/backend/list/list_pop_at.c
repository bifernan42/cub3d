/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:02:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:02:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_pop_at(t_list *self, uint64_t index)
{
	uintptr_t	data;
	t_node		*node;

	if (list_is_empty(self) || index >= self->size)
		return (0);
	node = list_remove_at(self, index);
	data = node->data;
	node_destroy(node);
	return (data);
}
