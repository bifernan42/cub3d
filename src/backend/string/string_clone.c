/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:29:04 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 13:29:04 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_clone(char *src)
{
	if (!src)
		return (NULL);
	return (dupz((void *)src, string_length(src)));
}

char	*string_clone_scalar(int32_t ch)
{
	char	*result;

	result = alloc(2);
	result[0] = (char)ch;
	result[1] = 0x00;
	return (result);
}

char	*string_nclone(char *src, uint64_t n)
{
	if (!src)
		return (NULL);
	return (dupz((void *)src, string_length(src) - n));
}
