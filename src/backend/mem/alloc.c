/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*alloc(uint64_t byte_size)
{
	void	*ptr;

	ptr = malloc(byte_size);
	if (!ptr)
		return (NULL);
	zeroed(ptr, byte_size);
	return (ptr);
}
