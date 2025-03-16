/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_clear_retain_capacity(t_list *self,
		uintptr_t (*dtor)(uintptr_t data))
{
	t_node		*current;
	uintptr_t	data;

	current = self->head;
	while (current != NULL)
	{
		data = current->data;
		if (data != 0)
			current->data = dtor(data);
		current = current->next;
	}
}

void	list_clear(t_list *self, uintptr_t (*dtor)(uintptr_t data))
{
	t_node		*current;
	t_node		*temp;
	uintptr_t	data;

	current = self->head;
	while (current != NULL)
	{
		data = current->data;
		if (data != 0)
			current->data = dtor(data);
		temp = current;
		current = current->next;
		temp->data = 0;
		temp->next = NULL;
		temp->prev = NULL;
		node_destroy(temp);
		self->size -= 1;
	}
	self->head = NULL;
	self->tail = NULL;
	self->size = 0;
}
