/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_peek_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uintptr_t	list_peek_back(t_list *self)
{
	if (list_is_empty(self))
		return (0);
	return (self->tail->data);
}
