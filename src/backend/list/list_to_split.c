/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:10:06 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 12:10:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	**list_to_split(t_list *self)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	size = list_size(self);
	i = 0;
	result = alloc(size + 1 * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = string_clone((char *)list_peek_at(self, i));
		++i;
	}
	result[i] = NULL;
	return (result);
}
