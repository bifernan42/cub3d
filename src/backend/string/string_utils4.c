/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:12:56 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/23 17:12:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_split_size(char **split)
{
	uint64_t	i;

	if (!split || !*split)
		return (0);
	i = 0;
	while (split[i])
		++i;
	return (i);
}
