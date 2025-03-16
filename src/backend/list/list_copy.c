/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:40:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 19:40:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_copy(t_list *dest, t_list *src, uintptr_t (*ctor)(uintptr_t data))
{
	t_node	*copied;
	t_node	*head;

	if (!dest || !src || list_is_empty(src))
		return ;
	head = src->head;
	while (head)
	{
		copied = node_create(ctor(head->data));
		list_insert_back(dest, copied);
		head = head->next;
	}
}
