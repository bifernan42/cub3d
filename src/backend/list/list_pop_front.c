/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:02:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:02:11 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_pop_front(t_list *self)
{
	uintptr_t	data;
	t_node		*node;

	if (list_is_empty(self))
		return (0);
	node = list_remove_front(self);
	data = node->data;
	node_destroy(node);
	return (data);
}
