/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:59:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:59:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_insert_back(t_list *self, t_node *new_tail)
{
	if (list_is_empty(self))
	{
		self->head = new_tail;
		self->tail = new_tail;
	}
	else
	{
		self->tail->next = new_tail;
		new_tail->prev = self->tail;
		self->tail = new_tail;
	}
	self->size += 1;
}
