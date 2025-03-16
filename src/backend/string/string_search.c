/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:45:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 12:45:15 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_search_scalar(char *source, int32_t scalar, uint64_t n)
{
	uint64_t	i;

	if (!source || !n)
		return (NULL);
	if (scalar == '\0')
		return ((char *)&source[string_length(source)]);
	i = 0;
	while (source[i] && i < n)
	{
		if (source[i] == scalar)
			return ((char *)&source[i]);
		++i;
	}
	return (NULL);
}

char	*string_search_any(char *source, t_bitset *delimiters, uint64_t n)
{
	uint64_t	i;

	i = 0;
	if (!source || !delimiters || n == 0)
		return (NULL);
	while (source[i] && i < n)
	{
		if (bitset_is_set(delimiters, (uint64_t)source[i]))
			return ((char *)&source[i]);
		++i;
	}
	return (NULL);
}

char	*string_search_none(char *source, t_bitset *delimiters, uint64_t n)
{
	uint64_t	i;

	i = 0;
	if (!source || !delimiters || n == 0)
		return (NULL);
	while (source[i] && i < n)
	{
		if (!bitset_is_set(delimiters, (uint64_t)source[i]))
			return ((char *)&source[i]);
		++i;
	}
	return (NULL);
}

char	*string_search_predicate(char *source, bool(predicate)(int32_t ch),
		uint64_t n)
{
	uint64_t	i;

	if (!source || !predicate || !n)
		return (NULL);
	i = 0;
	while (source[i] && i < n)
	{
		if (predicate(source[i]))
			return ((char *)&source[i]);
		++i;
	}
	return (NULL);
}

char	*string_search_sequence(char *haystack, char *needle, uint64_t n)
{
	uint64_t	u1;
	uint64_t	u2;

	if (!haystack && n == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	u1 = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2] && u1 < n)
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			return ((char *)&haystack[(uint64_t)u1 - u2]);
		u1 = (u1 - u2) + 1;
	}
	return (0);
}
