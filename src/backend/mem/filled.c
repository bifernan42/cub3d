/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:25 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*filled(void *ptr, uint8_t byte, uint64_t byte_size)
{
	uint8_t		*byte_ptr;
	uint64_t	i;

	if (!ptr)
		return (NULL);
	if (!byte_size)
		return (ptr);
	i = 0;
	byte_ptr = (uint8_t *)ptr;
	while (i < byte_size)
		*(byte_ptr + i++) = byte;
	return (byte_ptr);
}
