/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:32:16 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 14:32:17 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

void	*dupz(void *ptr, uint64_t byte_size)
{
	void	*result;

	if (!ptr || !byte_size)
		return (NULL);
	result = alloc(byte_size + 1);
	memcopy(result, ptr, byte_size);
	((uint8_t *)result)[byte_size] = 0x00;
	return (result);
}
