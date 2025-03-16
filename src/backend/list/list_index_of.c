/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_index_of.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

int64_t	list_index_of(t_list *self, uintptr_t data,
		int64_t (*compare)(uintptr_t d1, uintptr_t d2))
{
	t_node	*current;
	int64_t	index;

	index = 0;
	current = self->head;
	while (current != NULL)
	{
		if (compare(current->data, data) == 1)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}
