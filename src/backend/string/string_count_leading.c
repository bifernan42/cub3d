/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_leading.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:34:18 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_count_leading_scalar(char *source, int32_t scalar)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (source[i] != scalar)
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_leading_any(char *source, t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (!bitset_is_set(delimiters, (uint64_t)source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_leading_none(char *source, t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (bitset_is_set(delimiters, (uint64_t)source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_leading_predicate(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (!predicate(source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_leading_sequence(char *haystack, char *needle)
{
	uint64_t	count;
	uint64_t	index;
	uint64_t	diff;
	uint64_t	nlen;
	uint64_t	hlen;

	if (!haystack || needle[0] == '\0')
		return (0);
	count = 0;
	index = 0;
	hlen = string_length(haystack);
	nlen = string_length(needle);
	while (index < hlen)
	{
		diff = string_index_of_difference(needle, &haystack[index]);
		if (diff == nlen)
		{
			index += diff;
			count += 1;
		}
		else
			return (count);
	}
	return (count);
}
