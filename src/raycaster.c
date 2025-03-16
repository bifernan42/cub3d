/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:22:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 20:22:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

t_raycaster	*raycaster_create(t_smlx_instance *smlx, t_camera *camera,
		t_map *map, t_container_cfg *cfg)
{
	t_raycaster	*raycaster;

	raycaster = alloc(sizeof(t_raycaster));
	if (!raycaster)
		return (NULL);
	raycaster->mlx = smlx;
	raycaster->cam = camera;
	raycaster->map = map;
	raycaster->north = smlx_texture_create(smlx, cfg->path_no_texture, 0);
	raycaster->south = smlx_texture_create(smlx, cfg->path_so_texture, 1);
	raycaster->west = smlx_texture_create(smlx, cfg->path_we_texture, 2);
	raycaster->east = smlx_texture_create(smlx, cfg->path_ea_texture, 3);
	if (!raycaster->north || !raycaster->south || !raycaster->west
		|| !raycaster->east)
		return (raycaster_destroy(raycaster));
	return (raycaster);
}

t_raycaster	*raycaster_destroy(t_raycaster *raycaster)
{
	if (!raycaster)
		return (NULL);
	if (raycaster->north)
		raycaster->north = smlx_texture_destroy(raycaster->mlx,
				raycaster->north);
	if (raycaster->south)
		raycaster->south = smlx_texture_destroy(raycaster->mlx,
				raycaster->south);
	if (raycaster->west)
		raycaster->west = smlx_texture_destroy(raycaster->mlx, raycaster->west);
	if (raycaster->east)
		raycaster->east = smlx_texture_destroy(raycaster->mlx, raycaster->east);
	return (dealloc(raycaster));
}

// void	log_raycaster(const t_raycaster *ray)
// {
// 	printf("Raycaster State:\n");
// 	// Camera related logs
// 	printf("Camera Position: (%.2f, %.2f)\n", ray->cam->pos_x, ray->cam->pos_y);
// 	printf("Camera Direction: (%.2f, %.2f)\n", ray->cam->dir_x,
// 		ray->cam->dir_y);
// 	printf("Camera Plane: (%.2f, %.2f)\n", ray->cam->pln_x, ray->cam->pln_y);
// 	printf("Camera Time: Current: %.2f, Previous: %.2f\n", ray->cam->curr_time,
// 		ray->cam->prev_time);
// 	// Player related logs
// 	printf("Player Position: (%.2f, %.2f)\n", ray->pos_x, ray->pos_y);
// 	printf("Player Direction: (%.2f, %.2f)\n", ray->dir_x, ray->dir_y);
// 	printf("Player Plane: (%.2f, %.2f)\n", ray->plane_x, ray->plane_y);
// 	// Raycasting related logs
// 	printf("Camera X: %.2f\n", ray->camera_x);
// 	printf("Ray Direction: (%.2f, %.2f)\n", ray->ray_dir_x, ray->ray_dir_y);
// 	printf("Map Position: (%d, %d)\n", ray->map_x, ray->map_y);
// 	printf("Side Distances: X: %.2f, Y: %.2f\n", ray->side_dist_x,
// 		ray->side_dist_y);
// 	printf("Delta Distances: X: %.2f, Y: %.2f\n", ray->delta_dist_x,
// 		ray->delta_dist_y);
// 	printf("Perpendicular Wall Distance: %.2f\n", ray->per_wall_dist);
// 	// Step and hit info
// 	printf("Step: X: %d, Y: %d\n", ray->step_x, ray->step_y);
// 	printf("Hit: %d, Side: %d\n", ray->hit, ray->side);
// 	// Drawing info
// 	printf("Line Height: %d, Pitch: %d\n", ray->line_height, ray->pitch);
// 	printf("Draw Start: %d, Draw End: %d\n", ray->draw_start, ray->draw_end);
// 	// Texture info
// 	printf("Texture Number: %d\n", ray->text_num);
// 	printf("Wall X: %.2f\n", ray->wall_x);
// 	printf("Texture Coordinates: X: %d, Y: %d\n", ray->text_x, ray->text_y);
// 	printf("Texture Step: %.2f, Texture Position: %.2f\n", ray->step,
// 		ray->text_pos);
// 	printf("Color: %u\n", ray->color);
// 	// General settings
// 	printf("Screen Size: Width: %d, Height: %d\n", ray->width, ray->height);
// 	printf("Current Pixel: X: %d, Y: %d\n", ray->x, ray->y);
// 	// Map and textures (addresses)
// 	printf("Map: %p\n", (void *)ray->map);
// 	printf("Textures - North: %p, South: %p, West: %p, East: %p\n",
// 		(void *)ray->north, (void *)ray->south, (void *)ray->west,
// 		(void *)ray->east);
// 	printf("Ceiling - Texture: %p, Color: %u\n", (void *)ray->ceil_text,
// 		ray->ceil_color);
// 	printf("Floor - Texture: %p, Color: %u\n", (void *)ray->floor_text,
// 		ray->floor_color);
// 	printf("\n");
// 	fflush(stdout);
// }
