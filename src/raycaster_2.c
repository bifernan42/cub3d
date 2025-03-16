/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:27:40 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/09 20:27:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster_find_dist_perp_ray(t_raycaster *ray)
{
	if (ray->side == 0)
		ray->per_wall_dist = (ray->map_x - ray->pos_x + ((float)1 - ray->step_x)
				/ 2) / ray->ray_dir_x;
	else
		ray->per_wall_dist = (ray->map_y - ray->pos_y + ((float)1 - ray->step_y)
				/ 2) / ray->ray_dir_y;
}

void	raycaster_find_low_and_high_pix_in_strip(t_raycaster *ray)
{
	ray->line_height = (int)(ray->height / ray->per_wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->height / 2;
	if (ray->draw_end >= ray->height)
		ray->draw_end = ray->height - 1;
}

void	raycaster_pick_texture_from_orientation(t_raycaster *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->text_num = 0;
		else
			ray->text_num = 1;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->text_num = 2;
		else
			ray->text_num = 3;
	}
}

void	raycaster_calculate_value_of_wall_x(t_raycaster *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->per_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->pos_x + ray->per_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycaster_find_x_coord_text(t_raycaster *ray)
{
	int	width;

	if (ray->text_num == 0)
		width = ray->west->width;
	else if (ray->text_num == 1)
		width = ray->east->width;
	else if (ray->text_num == 2)
		width = ray->north->width;
	else
		width = ray->south->width;
	ray->text_x = (int)(ray->wall_x * (double)(width));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->text_x = width - ray->text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->text_x = width - ray->text_x - 1;
}
