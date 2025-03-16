/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_instance_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:35:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 12:35:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

bool	smlx_frame_buffer_init(t_smlx_instance *self, int32_t width,
		int32_t height)
{
	t_smlx_frame_buffer	*ptr;
	int32_t				i;

	ptr = &self->frame_buffer;
	i = 0;
	while (i < 3)
	{
		ptr->img[i] = mlx_new_image(self->mlx, width, height);
		if (!ptr->img[i])
			return (false);
		ptr->data[i] = (uint8_t *)mlx_get_data_addr(ptr->img[i], &ptr->bpp[i],
				&ptr->size[i], &ptr->endian[i]);
		if (!ptr->data[i])
			return (false);
		ptr->fid[i] = i;
		++i;
	}
	self->frame_rendered = 0;
	self->frame_buffer_lvl = 3;
	self->bpp = ptr->bpp[0];
	self->size = ptr->size[0];
	self->endian = ptr->endian[0];
	self->data = ptr->data[0];
	self->img = ptr->img[0];
	return (true);
}

t_smlx_instance	*smlx_instance_create(int32_t width, int32_t height,
		char *title)
{
	t_smlx_instance	*self;

	self = alloc(sizeof(*self));
	if (!self)
		return (NULL);
	self->title = title;
	self->height = height;
	self->width = width;
	self->render_ready = false;
	self->frame_counter = 0;
	self->time_last_ms = smlx_timestamp();
	self->mlx = mlx_init();
	if (!self->mlx)
		return (smlx_instance_destroy(self));
	self->win = mlx_new_window(self->mlx, width, height, title);
	if (!self->win)
		return (smlx_instance_destroy(self));
	smlx_frame_buffer_init(self, width, height);
	smlx_set_target_fps(self, 60);
	smlx_fetch_new_image(self);
	return (self);
}
