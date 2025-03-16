/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_tick_rate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:11:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 14:11:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"
#include <stdio.h>

void	smlx_tick_rate(t_smlx_instance *self)
{
	int64_t	curr_ms;
	int64_t	delt_ms;

	curr_ms = smlx_timestamp();
	delt_ms = curr_ms - self->time_last_ms;
	if (delt_ms >= self->time_trgt_ms)
	{
		self->render_ready = true;
		self->time_last_ms = curr_ms;
	}
	else
		self->render_ready = false;
}
