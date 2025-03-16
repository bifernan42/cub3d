/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:27:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/09 20:27:44 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycaster_select_texture(t_smlx_texture **texture, t_raycaster *ray)
{
	if (ray->text_num == 0)
		*texture = ray->west;
	else if (ray->text_num == 1)
		*texture = ray->east;
	else if (ray->text_num == 2)
		*texture = ray->north;
	else
		*texture = ray->south;
}

void	raycaster_draw_texture(t_raycaster *ray)
{
	t_smlx_texture	*texture;
	uint32_t		color;
	float			u;
	float			v;

	raycaster_select_texture(&texture, ray);
	ray->step = 1.0 * texture->height / ray->line_height;
	ray->text_pos = (ray->draw_start - (float)ray->height / 2
			+ (float)ray->line_height / 2) * ray->step;
	ray->y = ray->draw_start;
	while (ray->y < ray->draw_end)
	{
		ray->text_y = (int)ray->text_pos & (texture->height - 1);
		ray->text_pos += ray->step;
		u = (float)ray->text_x / (float)texture->width;
		v = (float)ray->text_y / (float)texture->height;
		color = smlx_get_texture_color_at(texture, u, v);
		smlx_draw_pixel(ray->mlx, (t_vec2i){.x = ray->x, .y = ray->y}, color);
		ray->y++;
	}
}
