/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:18:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 11:18:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	report_error_and_die_endl(char *msg)
{
	printf("error :%s\n", msg);
	exit(1);
}

void	report_error_cleanup_and_die_endl(t_container *cub3d, char *msg)
{
	container_destroy(cub3d);
	report_error_and_die_endl(msg);
}

void	cub3d_assert(bool cond, char *label)
{
	if (!cond)
	{
		fprintf(stderr, "assertion failed: %s\n", label);
		fflush(stderr);
		abort();
	}
}
