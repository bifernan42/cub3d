/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:13 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:13 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*dupe(void *ptr, uint64_t byte_size)
{
	void	*result;

	if (!ptr || !byte_size)
		return (NULL);
	result = alloc(byte_size);
	memcopy(result, ptr, byte_size);
	return (result);
}
