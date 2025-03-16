/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_chrono_ends.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:57:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_chrono_ends(t_smlx_instance *self)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	self->time_prev_ms = self->time_curr_ms;
	self->time_curr_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	self->time_delt_ms = self->time_curr_ms - self->time_prev_ms;
}
