/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_texture_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:47:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:47:05 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

t_smlx_texture	*smlx_texture_create(t_smlx_instance *smlx, char *path,
		int32_t id)
{
	t_smlx_texture	*texture;

	texture = alloc(sizeof(t_smlx_texture));
	if (!texture)
		return (NULL);
	texture->id = id;
	texture->img = mlx_xpm_file_to_image(smlx->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (smlx_texture_destroy(smlx, texture));
	texture->data = (uint8_t *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size, &texture->endiant);
	if (!texture->data)
		return (smlx_texture_destroy(smlx, texture));
	return (texture);
}
