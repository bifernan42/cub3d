/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:53 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_insert_front(t_list *self, t_node *new_head)
{
	if (list_is_empty(self))
	{
		self->head = new_head;
		self->tail = new_head;
	}
	else
	{
		new_head->prev = NULL;
		new_head->next = self->head;
		self->head->prev = new_head;
		self->head = new_head;
	}
	self->size += 1;
}
