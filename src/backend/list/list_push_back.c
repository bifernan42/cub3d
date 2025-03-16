/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:01:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/06 09:01:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	list_push_back(t_list *self, uintptr_t data)
{
	t_node	*node;

	if (!self)
		return ;
	node = node_create(data);
	list_insert_back(self, node);
}
