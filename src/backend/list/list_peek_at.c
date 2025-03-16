/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_peek_at(t_list *self, uint64_t index)
{
	t_node	*node;

	if (list_is_empty(self) || index >= self->size)
		return (0);
	node = node_get_nchild(self->head, index);
	if (!node)
		return (0);
	return (node->data);
}
