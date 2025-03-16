/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:58:48 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:58:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_list	*list_destroy(t_list *self)
{
	if (!self)
		return (NULL);
	while (!list_is_empty(self))
		node_destroy(list_remove_front(self));
	dealloc(self);
	return (NULL);
}
