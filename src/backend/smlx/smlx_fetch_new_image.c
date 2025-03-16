/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_fetch_new_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 15:50:39 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_fetch_new_image(t_smlx_instance *self)
{
	int32_t	index;

	index = 0;
	index = (self->frame_rendered++) % 3;
	self->fid = self->frame_buffer.fid[index];
	self->img = self->frame_buffer.img[index];
	self->endian = self->frame_buffer.endian[index];
	self->bpp = self->frame_buffer.bpp[index];
	self->size = self->frame_buffer.size[index];
	self->data = self->frame_buffer.data[index];
}
