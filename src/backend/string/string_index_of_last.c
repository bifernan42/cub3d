/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_index_of_last.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:08:46 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:17:03 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_index_of_last_scalar(char *source, int32_t scalar)
{
	uint64_t	last;
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	last = 0;
	while (source[i])
	{
		if (source[i] == scalar)
			last = i;
		++i;
	}
	if (last == 0 && source[last] != scalar)
		return (NOTFOUND);
	return (last);
}

uint64_t	string_index_of_last_any(char *source, t_bitset *delimiters)
{
	uint64_t	last;
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	last = 0;
	while (source[i])
	{
		if (bitset_is_set(delimiters, (uint64_t)source[i]))
			last = i;
		++i;
	}
	if (last == 0 && bitset_is_set(delimiters, (uint64_t)source[last]))
		return (NOTFOUND);
	return (last);
}

uint64_t	string_index_of_last_none(char *source, t_bitset *delimiters)
{
	uint64_t	last;
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	last = 0;
	while (source[i])
	{
		if (!bitset_is_set(delimiters, (uint64_t)source[i]))
			last = i;
		++i;
	}
	if (last == 0 && !bitset_is_set(delimiters, (uint64_t)source[last]))
		return (NOTFOUND);
	return (last);
}

uint64_t	string_index_of_last_predicate(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	last;
	uint64_t	i;

	if (!source)
		return (NOTFOUND);
	i = 0;
	last = 0;
	while (source[i])
	{
		if (predicate(source[i]) == true)
			last = i;
		++i;
	}
	if (last == 0 && !predicate(source[last]))
		return (NOTFOUND);
	return (last);
}

uint64_t	string_index_of_last_sequence(char *haystack, char *needle)
{
	uint64_t	u1;
	uint64_t	u2;
	uint64_t	last;

	if (!haystack || needle[0] == '\0')
		return (0);
	u1 = 0;
	last = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2])
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			last = (u1 - u2);
		u1 = (u1 - u2) + 1;
	}
	u2 = string_index_of_difference(needle, haystack);
	if (last == 0 && needle[u2] != 0)
		return (NOTFOUND);
	return (last);
}
