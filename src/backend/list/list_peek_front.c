/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:59:19 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 10:59:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_peek_front(t_list *self)
{
	if (list_is_empty(self))
		return (0);
	return (self->head->data);
}
