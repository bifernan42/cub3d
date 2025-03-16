/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_chrono_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:57:56 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

int64_t	smlx_chrono_delta(t_smlx_instance *self)
{
	return (self->time_delt_ms);
}
