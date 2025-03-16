/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:27:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/09 20:27:36 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	raycaster_init(t_raycaster *ray, t_camera *camera, t_map *map)
{
	ray->width = ray->mlx->width;
	ray->height = ray->mlx->height;
	ray->cam = camera;
	ray->map = map;
	ray->pos_x = camera->pos_x;
	ray->pos_y = camera->pos_y;
	ray->dir_x = camera->dir_x;
	ray->dir_y = camera->dir_y;
	ray->plane_x = camera->pln_x;
	ray->plane_y = camera->pln_y;
}

static void	raycaster_side_dist(t_raycaster *ray)
{
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

static void	raycaster_dda(t_raycaster *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= ray->map->width || ray->map_y < 0
			|| ray->map_y >= ray->map->height)
			return ;
		if (ray->map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	raycaster_draw(t_raycaster *ray, t_camera *camera, t_map *map)
{
	raycaster_init(ray, camera, map);
	ray->x = 0;
	while (ray->x < ray->width)
	{
		ray->camera_x = 2 * ray->x / (double)ray->width - 1;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		ray->map_x = (int)ray->pos_x;
		ray->map_y = (int)ray->pos_y;
		ray->hit = 0;
		raycaster_side_dist(ray);
		raycaster_dda(ray);
		raycaster_find_dist_perp_ray(ray);
		raycaster_find_low_and_high_pix_in_strip(ray);
		raycaster_pick_texture_from_orientation(ray);
		raycaster_calculate_value_of_wall_x(ray);
		raycaster_find_x_coord_text(ray);
		raycaster_draw_texture(ray);
		ray->x++;
	}
}
