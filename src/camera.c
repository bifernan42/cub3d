/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:19:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 19:19:33 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	camera_init_direction(t_camera *camera, char direction)
{
	if (direction == 'N')
	{
		camera->dir_y = -1.0f;
		camera->pln_x = 0.66f;
	}
	else if (direction == 'S')
	{
		camera->dir_y = 1.0f;
		camera->pln_x = -0.66f;
	}
	else if (direction == 'E')
	{
		camera->dir_x = 1.0f;
		camera->pln_y = 0.66f;
	}
	else if (direction == 'W')
	{
		camera->dir_x = -1.0f;
		camera->pln_y = -0.66f;
	}
}

t_camera	*camera_create(t_map *map, t_container_cfg *cfg)
{
	t_camera	*camera;

	camera = alloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	(void)cfg;
	camera->pos_x = (float_t)map->player_pos_x;
	camera->pos_y = (float_t)map->player_pos_y;
	camera_init_direction(camera, map->player_dir);
	camera->prev_time = smlx_timestamp();
	camera->curr_time = smlx_timestamp();
	camera->map = map;
	return (camera);
}

t_camera	*camera_destroy(t_camera *cam)
{
	if (!cam)
		return (NULL);
	return (dealloc(cam));
}
