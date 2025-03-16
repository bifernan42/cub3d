/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:57:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 14:57:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_draw_pixel(t_smlx_instance *self, t_vec2i pos, uint32_t color)
{
	uint32_t	*ptr;

	if (pos.x >= 0 && pos.x < self->width && pos.y >= 0 && pos.y < self->height)
	{
		ptr = (uint32_t *)(self->data + (pos.y * self->size) + (pos.x
					* (self->bpp / 8)));
		*ptr = color;
	}
}
