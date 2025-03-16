/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:47:07 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 10:47:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	container_open_and_parse(t_container *const self, char *file_name)
{
	self->file_buffer = file_open_read_to_end_alloc(file_name);
	if (!self->file_buffer)
		return (false);
	self->cfg = container_cfg_create(self->file_buffer);
	if (!self->cfg)
		return (false);
	if (!container_cfg_parse(self->cfg))
		return (false);
	return (true);
}

t_container	*container_create(char *file_name)
{
	t_container	*container;

	container = alloc(sizeof(t_container));
	if (!container)
		return (NULL);
	if (!container_open_and_parse(container, file_name))
		return (container_destroy(container));
	container->map = map_create(container->cfg);
	if (!container->map || !map_sanitize(container->map))
		return (container_destroy(container));
	container->smlx = smlx_instance_create(container->cfg->res_x,
			container->cfg->res_y, file_name);
	if (!container->smlx)
		return (container_destroy(container));
	container->cam = camera_create(container->map, container->cfg);
	if (!container->cam)
		return (container_destroy(container));
	container->ray = raycaster_create(container->smlx, container->cam,
			container->map, container->cfg);
	if (!container->ray)
		return (container_destroy(container));
	return (container);
}

t_container	*container_destroy(t_container *self)
{
	if (!self)
		return (NULL);
	if (self->file_buffer)
		self->file_buffer = dealloc(self->file_buffer);
	if (self->cfg)
		self->cfg = container_cfg_destroy(self->cfg);
	if (self->map)
		self->map = map_destroy(self->map);
	if (self->cam)
		self->cam = camera_destroy(self->cam);
	if (self->ray)
		self->ray = raycaster_destroy(self->ray);
	if (self->smlx)
		self->smlx = smlx_instance_destroy(self->smlx);
	return (dealloc(self));
}

int32_t	main(int32_t argc, char **argv)
{
	t_container	*cub3d;

	if (argc != 2 || !file_is_correct_extension(argv[1]))
		report_error_and_die_endl("argument count or file extension");
	cub3d = container_create(argv[1]);
	if (!cub3d)
		report_error_and_die_endl("cub3d's container constructor failed");
	cub3d_start(cub3d);
	return (0);
}
