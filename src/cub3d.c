/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:55:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 19:55:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_start(t_container *const self)
{
	smlx_set_target_fps(self->smlx, 0);
	on_program_start(self, self->smlx);
}

void	draw_floor_and_ceiling(t_container *self, int32_t width)
{
	int32_t	i;

	i = 0;
	self->ceil.x = self->smlx->height / 2;
	self->ceil.y = self->smlx->height;
	self->floor.x = 0;
	self->floor.y = self->smlx->height / 2;
	while (i < width)
	{
		smlx_draw_vertical(self->smlx, i, self->ceil, self->cfg->floor_color);
		smlx_draw_vertical(self->smlx, i, self->floor, self->cfg->ceil_color);
		++i;
	}
}

int32_t	cub3d_render(void *param)
{
	t_container	*self;

	self = (t_container *)param;
	camera_update(self->cam);
	smlx_draw_clear(self->smlx, SMLX_SOLID_BLACK);
	draw_floor_and_ceiling(self, self->smlx->width);
	raycaster_draw(self->ray, self->cam, self->map);
	smlx_instance_display(self->smlx);
	return (0);
}
