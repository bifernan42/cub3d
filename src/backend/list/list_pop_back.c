/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:02:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:02:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_pop_back(t_list *self)
{
	uintptr_t	data;
	t_node		*node;

	if (list_is_empty(self))
		return (0);
	node = list_remove_back(self);
	data = node->data;
	node_destroy(node);
	return (data);
}
