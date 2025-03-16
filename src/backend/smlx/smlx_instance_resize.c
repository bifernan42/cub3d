/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_instance_resize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:22:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:22:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

bool	smlx_instance_resize(t_smlx_instance *self, int32_t width,
		int32_t height, char *title)
{
	if (!self || !title)
		return (false);
	if (self->height == height && self->width == width)
		return (true);
	if (self->win)
	{
		self->title = title;
		if (self->img)
			mlx_destroy_image(self->mlx, self->img);
		mlx_destroy_window(self->mlx, self->win);
		self->win = mlx_new_window(self->mlx, width, height, self->title);
		if (!self->win)
			return (false);
		self->img = mlx_new_image(self->mlx, width, height);
		if (!self->img)
			return (false);
		self->data = (uint8_t *)mlx_get_data_addr(self->img, &self->bpp,
				&self->size, &self->endian);
		if (!self->data)
			return (false);
		self->height = height;
		self->width = width;
	}
	return (true);
}
