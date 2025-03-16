/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:25:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:25:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_map(t_list *self, void (fn)(uintptr_t data))
{
	t_node	*head;

	if (!self)
		return ;
	head = self->head;
	while (head)
	{
		fn(head->data);
		head = head->next;
	}
}
