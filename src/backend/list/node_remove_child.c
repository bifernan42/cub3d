/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_remove_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_node	*node_remove_child(t_node *self)
{
	t_node	*child;

	if (!self || !self->next)
		return (NULL);
	child = self->next;
	self->next = child->next;
	if (child->next)
		child->next->prev = self;
	child->next = NULL;
	child->prev = NULL;
	return (child);
}
