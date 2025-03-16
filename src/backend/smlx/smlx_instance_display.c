/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_instance_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:49:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:49:58 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"
#include <stdio.h>

bool	smlx_instance_display(t_smlx_instance *self)
{
	if (!self || !self->mlx || !self->win || !self->img)
		return (false);
	while (!self->render_ready)
		smlx_tick_rate(self);
	mlx_put_image_to_window(self->mlx, self->win, self->img, 0, 0);
	self->time_last_ms = smlx_timestamp();
	self->render_ready = false;
	self->frame_counter += 1;
	smlx_fetch_new_image(self);
	mlx_do_sync(self->mlx);
	return (true);
}
