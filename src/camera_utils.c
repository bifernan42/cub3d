/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:39:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/09 20:39:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	camera_can_move(t_camera *cam, t_vec2 pos)
{
	const int32_t	map_x = (int)pos.x;
	const int32_t	map_y = (int)pos.y;

	if (cam->map->grid[map_y][map_x] == '0')
		return (true);
	return (false);
}

void	camera_move(t_camera *cam, float_t amount)
{
	t_vec2	new_pos;

	new_pos.x = cam->pos_x + cam->dir_x * amount;
	new_pos.y = cam->pos_y + cam->dir_y * amount;
	if (camera_can_move(cam, new_pos))
	{
		cam->pos_x = new_pos.x;
		cam->pos_y = new_pos.y;
	}
}

void	camera_strafe(t_camera *cam, float_t amount)
{
	t_vec2	new_pos;

	new_pos.x = cam->pos_x + cam->pln_x * amount;
	new_pos.y = cam->pos_y + cam->pln_y * amount;
	if (camera_can_move(cam, new_pos))
	{
		cam->pos_x = new_pos.x;
		cam->pos_y = new_pos.y;
	}
}

void	camera_rota(t_camera *cam, float_t amount)
{
	double	old_dir_x;
	double	old_pln_x;

	old_dir_x = cam->dir_x;
	old_pln_x = cam->pln_x;
	cam->dir_x = cam->dir_x * cos(amount) - cam->dir_y * sin(amount);
	cam->dir_y = old_dir_x * sin(amount) + cam->dir_y * cos(amount);
	cam->pln_x = cam->pln_x * cos(amount) - cam->pln_y * sin(amount);
	cam->pln_y = old_pln_x * sin(amount) + cam->pln_y * cos(amount);
}

void	camera_update(t_camera *cam)
{
	double	frame_time;
	double	move_speed;
	double	rot_speed;

	cam->prev_time = cam->curr_time;
	cam->curr_time = smlx_timestamp();
	frame_time = (cam->curr_time - cam->prev_time) / 1000.0;
	move_speed = frame_time * 5.0;
	rot_speed = frame_time * 3.0;
	if (cam->move_up)
		camera_move(cam, move_speed);
	if (cam->move_down)
		camera_move(cam, -move_speed);
	if (cam->move_left)
		camera_strafe(cam, -move_speed);
	if (cam->move_right)
		camera_strafe(cam, move_speed);
	if (cam->rotate_right)
		camera_rota(cam, -rot_speed);
	if (cam->rotate_left)
		camera_rota(cam, rot_speed);
}
