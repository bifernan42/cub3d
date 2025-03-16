/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:14:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 15:14:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

static void	smlx_draw_line_setup(t_mlx_bresenham *param, t_vec2i start,
		t_vec2i end)
{
	param->dx = abs(end.x - start.x);
	param->dy = abs(end.y - start.y);
	if (start.x < end.x)
		param->sx = 1;
	else
		param->sx = -1;
	if (start.y < end.y)
		param->sy = 1;
	else
		param->sy = -1;
	if (param->dx > param->dy)
		param->err = (param->dx / 2);
	else
		param->err = ((-param->dy) / 2);
}

void	smlx_draw_line(t_smlx_instance *self, t_vec2i start, t_vec2i end,
		uint32_t color)
{
	t_mlx_bresenham	p;

	smlx_draw_line_setup(&p, start, end);
	while (true)
	{
		smlx_draw_pixel(self, start, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		p.e2 = p.err;
		if (p.e2 > -p.dx)
		{
			p.err -= p.dy;
			start.x += p.sx;
		}
		if (p.e2 < p.dy)
		{
			p.err += p.dx;
			start.y += p.sy;
		}
	}
}
