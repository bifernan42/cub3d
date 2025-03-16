/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_texture_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:51:22 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 13:51:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

t_smlx_texture	*smlx_texture_destroy(t_smlx_instance *self,
		t_smlx_texture *texture)
{
	if (!self || !texture)
		return (NULL);
	if (texture->img)
		mlx_destroy_image(self->mlx, texture->img);
	dealloc(texture);
	return (NULL);
}
