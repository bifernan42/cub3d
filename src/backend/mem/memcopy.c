/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcopy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:29 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*memcopy(void *dest, void *source, uint64_t byte_size)
{
	uint8_t		*d;
	uint8_t		*s;
	uint64_t	i;

	if ((!dest && !source) || !byte_size)
		return (NULL);
	d = (uint8_t *)dest;
	s = (uint8_t *)source;
	i = 0;
	while (i < byte_size)
	{
		*(d + i) = *(s + i);
		++i;
	}
	return (dest);
}
