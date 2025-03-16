/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:57:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 20:57:52 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	on_keypressed(int32_t keycode, void *param)
{
	t_container	*self;

	self = (t_container *)param;
	if (keycode == SMLX_KEY_W)
		self->cam->move_up = true;
	else if (keycode == SMLX_KEY_S)
		self->cam->move_down = true;
	if (keycode == SMLX_KEY_A)
		self->cam->move_left = true;
	else if (keycode == SMLX_KEY_D)
		self->cam->move_right = true;
	if (keycode == SMLX_KEY_LEFT)
		self->cam->rotate_right = true;
	else if (keycode == SMLX_KEY_RIGHT)
		self->cam->rotate_left = true;
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(param);
	return (0);
}

int32_t	on_keyreleased(int32_t keycode, void *param)
{
	t_container	*self;

	self = (t_container *)param;
	if (keycode == SMLX_KEY_W)
		self->cam->move_up = false;
	else if (keycode == SMLX_KEY_S)
		self->cam->move_down = false;
	if (keycode == SMLX_KEY_A)
		self->cam->move_left = false;
	else if (keycode == SMLX_KEY_D)
		self->cam->move_right = false;
	if (keycode == SMLX_KEY_LEFT)
		self->cam->rotate_right = false;
	else if (keycode == SMLX_KEY_RIGHT)
		self->cam->rotate_left = false;
	else if (keycode == SMLX_KEY_ESC)
		on_program_quit(param);
	return (0);
}

int32_t	on_mouse_move(int32_t x, int32_t y, void *param)
{
	t_container	*self;
	t_camera	*cam;
	int32_t		middle_x;
	int32_t		middle_y;
	float		rot_amount;

	(void)y;
	self = (t_container *)param;
	cam = self->cam;
	middle_x = self->smlx->width / 2;
	middle_y = self->smlx->height / 2;
	rot_amount = (x - middle_x) * 0.0001;
	camera_rota(cam, rot_amount);
	mlx_mouse_move(self->smlx->mlx, self->smlx->win, middle_x, middle_y);
	return (0);
}

int32_t	on_program_quit(void *param)
{
	t_container	*self;

	self = (t_container *)param;
	mlx_loop_end(self->smlx->mlx);
	container_destroy(self);
	exit(0);
	return (0);
}

int32_t	on_program_start(t_container *const self, t_smlx_instance *const smlx)
{
	int32_t	middle_x;
	int32_t	middle_y;

	middle_x = smlx->width / 2;
	middle_y = smlx->height / 2;
	smlx_chrono_starts(self->smlx);
	mlx_hook(smlx->win, 17, 0, on_program_quit, self);
	mlx_hook(smlx->win, KeyPress, KeyPressMask, on_keypressed, self);
	mlx_hook(smlx->win, KeyRelease, KeyReleaseMask, on_keyreleased, self);
	mlx_hook(smlx->win, MotionNotify, PointerMotionMask, on_mouse_move, self);
	mlx_mouse_move(self->smlx->mlx, self->smlx->win, middle_x, middle_y);
	mlx_loop_hook(smlx->mlx, cub3d_render, self);
	mlx_mouse_hide(smlx->mlx, smlx->win);
	mlx_loop(smlx->mlx);
	return (0);
}
