/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:26:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 11:26:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_container_cfg	*container_cfg_create(char *file_buffer)
{
	t_container_cfg	*container_cfg;

	container_cfg = alloc(sizeof(t_container_cfg));
	if (!container_cfg)
		return (NULL);
	container_cfg->file_lines = string_split_scalar(file_buffer, '\n');
	if (!container_cfg->file_lines)
		return (container_cfg_destroy(container_cfg));
	container_cfg->res_x = DEFAULT_WIDTH;
	container_cfg->res_y = DEFAULT_HEIGHT;
	container_cfg->path_ea_texture = NULL;
	container_cfg->path_no_texture = NULL;
	container_cfg->path_so_texture = NULL;
	container_cfg->path_we_texture = NULL;
	container_cfg->ceil_color = -1;
	container_cfg->floor_color = -1;
	return (container_cfg);
}

t_container_cfg	*container_cfg_destroy(t_container_cfg *self)
{
	if (!self)
		return (NULL);
	if (self->file_lines)
		self->file_lines = dealloc_array(self->file_lines);
	if (self->path_no_texture)
		self->path_no_texture = dealloc(self->path_no_texture);
	if (self->path_so_texture)
		self->path_so_texture = dealloc(self->path_so_texture);
	if (self->path_we_texture)
		self->path_we_texture = dealloc(self->path_we_texture);
	if (self->path_ea_texture)
		self->path_ea_texture = dealloc(self->path_ea_texture);
	return (dealloc(self));
}
