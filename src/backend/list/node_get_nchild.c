/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_get_nchild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_node	*node_get_nchild(t_node *self, uint64_t n)
{
	t_node		*node;
	uint64_t	i;

	if (n == 0)
		return (self);
	i = n;
	node = self;
	while (i-- && node->next)
		node = node->next;
	return (node);
}
