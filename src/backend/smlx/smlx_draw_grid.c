/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:24:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 15:24:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_draw_grid(t_smlx_instance *self, int32_t w_lines, int32_t h_lines,
		uint32_t color)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	smlx_fetch_new_image(self);
	while (x <= self->width)
	{
		smlx_draw_line(self, (t_vec2i){.x = x, .y = 0}, (t_vec2i){.x = x,
			.y = self->height}, color);
		x += w_lines;
	}
	y = 0;
	while (y <= self->height)
	{
		smlx_draw_line(self, (t_vec2i){.x = 0, .y = y},
			(t_vec2i){.x = self->width, .y = y}, color);
		y += h_lines;
	}
}

void	smlx_draw_grid_propo(t_smlx_instance *self, int32_t w_lines,
		int32_t h_lines, uint32_t color)
{
	int32_t	num_w_lines;
	int32_t	num_h_lines;
	int32_t	i;
	int32_t	j;

	num_w_lines = (self->width - 1) / w_lines;
	num_h_lines = (self->height - 1) / h_lines;
	smlx_fetch_new_image(self);
	i = 0;
	while (i < self->width)
	{
		smlx_draw_line(self, (t_vec2i){.x = i, .y = 0}, (t_vec2i){.x = i,
			.y = self->height}, color);
		i += num_w_lines;
	}
	j = 0;
	while (j < self->height)
	{
		smlx_draw_line(self, (t_vec2i){.x = 0, .y = j},
			(t_vec2i){.x = self->width, .y = j}, color);
		j += num_h_lines;
	}
}
