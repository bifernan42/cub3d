/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_instance_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:36:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 12:36:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

bool	smlx_frame_buffer_deinit(t_smlx_instance *self)
{
	t_smlx_frame_buffer	*ptr;
	int32_t				i;

	ptr = &self->frame_buffer;
	i = 0;
	while (i < 3)
	{
		if (ptr->img[i] != NULL)
			mlx_destroy_image(self->mlx, ptr->img[i]);
		++i;
	}
	return (true);
}

t_smlx_instance	*smlx_instance_destroy(t_smlx_instance *self)
{
	if (!self)
		return (NULL);
	if (self->mlx)
	{
		smlx_frame_buffer_deinit(self);
		if (self->win)
			mlx_destroy_window(self->mlx, self->win);
		mlx_destroy_display(self->mlx);
		dealloc(self->mlx);
	}
	dealloc(self);
	return (NULL);
}
