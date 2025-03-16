/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_chrono_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:42 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:57:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_chrono_starts(t_smlx_instance *self)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	self->time_prev_ms = self->time_curr_ms;
	self->time_curr_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}
