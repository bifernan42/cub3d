/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:34:50 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_filter_scalar(char *source, int32_t scalar)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_scalar(source, scalar, len);
	result = alloc(len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (*source == scalar)
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_any(char *source, t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_any(source, delimiters, len);
	result = alloc(len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_none(char *source, t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_none(source, delimiters, len);
	result = alloc(len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (!bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_predicate(char *source, bool(predicate)(int32_t ch))
{
	char		*result;
	uint64_t	len;
	uint64_t	i;

	if (!source)
		return (NULL);
	len = string_length(source);
	len -= string_count_predicate(source, predicate, len);
	result = alloc(len + 1);
	i = 0;
	while (*source && i < len)
	{
		if (predicate(*source))
			++source;
		else
			result[i++] = *source++;
	}
	return (result);
}

char	*string_filter_sequence(char *haystack, char *needle)
{
	char		*result;
	char		*end;
	uint64_t	nlen;
	uint64_t	rlen;
	uint64_t	i;

	if (!haystack)
		return (NULL);
	if (!needle || !needle[0])
		return (string_clone((void *)haystack));
	end = (char *)haystack + string_length(haystack);
	rlen = (uint64_t)(end - haystack);
	nlen = string_length(needle);
	rlen -= (string_count_sequence(haystack, needle, rlen) * nlen);
	result = alloc(rlen + 1);
	i = 0;
	while (haystack <= end && i < rlen)
	{
		if (string_index_of_difference(needle, haystack) == nlen)
			haystack += nlen;
		else
			result[i++] = *haystack++;
	}
	return (result);
}
