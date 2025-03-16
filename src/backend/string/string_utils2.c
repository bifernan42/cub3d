/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:49:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:49:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_to_reverse(char *source)
{
	char		temp;
	uint64_t	len;
	uint64_t	i;

	len = string_length(source);
	if (len < 2)
		return (source);
	i = 0;
	while (i < (len - 1 - i))
	{
		temp = source[i];
		source[i] = source[len - i - 1];
		source[len - i - 1] = temp;
		++i;
	}
	return (source);
}

char	*string_to_uppercase(char *source)
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (source[i] >= 'a' && source[i] <= 'z')
			source[i] -= 32;
		++i;
	}
	return (source);
}

char	*string_to_lowercase(char *source)
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (source[i] >= 'A' && source[i] <= 'Z')
			source[i] += 32;
		++i;
	}
	return (source);
}

char	*string_to_titlecase(char *source)
{
	uint64_t	i;

	i = 0;
	source = string_to_lowercase(source);
	while (!is_alpha(source[i]))
		++i;
	if (is_alpha(source[i]))
		source[i] -= 32;
	return (source);
}

char	*string_to_capitalcase(char *source)
{
	uint64_t	i;
	int32_t		prev;

	i = 0;
	prev = ' ';
	source = string_to_lowercase(source);
	while (source[i])
	{
		if (is_alpha(source[i]) && is_spaces(prev))
			source[i] -= 32;
		prev = source[i];
		i += 1;
	}
	return (source);
}
