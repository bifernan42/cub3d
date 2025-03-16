/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:00:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 15:00:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_draw_clear(t_smlx_instance *self, uint32_t color)
{
	int32_t	y;
	int32_t	x;

	y = 0;
	while (y < self->height)
	{
		x = 0;
		while (x < self->width)
		{
			smlx_draw_pixel(self, (t_vec2i){.x = x, .y = y}, color);
			++x;
		}
		++y;
	}
}
