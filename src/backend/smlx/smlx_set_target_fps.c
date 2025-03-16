/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_set_target_fps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:07:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 14:07:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_set_target_fps(t_smlx_instance *self, int64_t target_fps)
{
	if (target_fps)
		self->time_trgt_ms = 1000 / target_fps;
	else
		self->time_trgt_ms = 0;
}
