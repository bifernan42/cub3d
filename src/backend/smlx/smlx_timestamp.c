/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_timestamp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:54:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/22 13:54:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

int64_t	smlx_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}
