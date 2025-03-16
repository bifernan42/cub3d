/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_vertical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:47:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 16:47:29 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_draw_vertical(t_smlx_instance *self, int32_t x, t_vec2i start_end,
		uint32_t color)
{
	int32_t	y;

	y = start_end.x;
	while (y <= start_end.y)
	{
		smlx_draw_pixel(self, (t_vec2i){.x = x, .y = y}, color);
		++y;
	}
}
