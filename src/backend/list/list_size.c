/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:00:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	list_size(t_list *self)
{
	return (self->size);
}
