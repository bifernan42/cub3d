/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:32 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:32 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*resize(void *ptr, uint64_t old_size, uint64_t new_size)
{
	void	*new_ptr;

	if (!new_size)
		return (ptr);
	new_ptr = alloc(new_size);
	if (old_size > new_size)
		memcopy(new_ptr, ptr, new_size);
	else
		memcopy(new_ptr, ptr, old_size);
	dealloc(ptr);
	return (new_ptr);
}
