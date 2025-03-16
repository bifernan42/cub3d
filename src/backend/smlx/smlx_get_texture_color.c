/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_get_texture_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:53:17 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:53:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

uint32_t	smlx_get_texture_color_at(t_smlx_texture *self, float_t u,
		float_t v)
{
	uint32_t	*ptr;
	int32_t		x;
	int32_t		y;

	if (!self)
		return (SMLX_SOLID_WHITE);
	x = (int32_t)floorf((u * (float)self->width));
	y = (int32_t)floorf((v * (float)self->height));
	if (x >= 0 && x < self->width && y >= 0 && y < self->height)
	{
		ptr = (uint32_t *)self->data + (y * self->width + x);
		return (*ptr);
	}
	return (SMLX_SOLID_WHITE);
}

uint32_t	smlx_get_texture_color(t_smlx_texture *self, t_vec2 start,
		t_vec2 curr, t_vec2 end)
{
	float_t	u;
	float_t	v;

	if (!self)
		return (SMLX_SOLID_WHITE);
	u = (float_t)(curr.x - start.x) / (end.x - start.x);
	if (u < 0)
		u = 0;
	if (u > 1)
		u = 1;
	v = (float_t)(curr.y - start.y) / (end.y - start.y);
	if (v < 0)
		v = 0;
	if (v > 1)
		v = 1;
	return (smlx_get_texture_color_at(self, u, v));
}
