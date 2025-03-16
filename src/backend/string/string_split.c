/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:04:45 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 13:04:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	**string_split_scalar(char *source, int32_t scalar)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	if (!source)
		return (NULL);
	size = string_compute_scalar_split_size(source, scalar);
	result = alloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && *source == scalar)
			++source;
		if (*source)
			result[i++] = string_clone_until_scalar(source, scalar);
		while (*source && *source != scalar)
			++source;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_any(char *source, t_bitset *delimiters)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	if (!source || !delimiters)
		return (NULL);
	size = string_compute_any_split_size(source, delimiters);
	result = alloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		if (*source)
			result[i++] = string_clone_until_any(source, delimiters);
		while (*source && !bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_none(char *source, t_bitset *delimiters)
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	if (!source || !delimiters)
		return (NULL);
	size = string_compute_none_split_size(source, delimiters);
	result = alloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && !bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		if (*source)
			result[i++] = string_clone_until_none(source, delimiters);
		while (*source && bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_predicate(char *source, bool(predicate)(int32_t ch))
{
	char		**result;
	uint64_t	size;
	uint64_t	i;

	if (!source || !predicate)
		return (NULL);
	size = string_compute_predicate_split_size(source, predicate);
	result = alloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		while (*source && predicate(*source))
			++source;
		if (*source)
			result[i++] = string_clone_until_predicate(source, predicate);
		while (*source && !predicate(*source))
			++source;
	}
	result[i] = NULL;
	return (result);
}

char	**string_split_sequence(char *haystack, char *needle)
{
	char		**result;
	uint64_t	len;
	uint64_t	nlen;
	uint64_t	i;
	uint64_t	j;

	if (!haystack || !needle)
		return (NULL);
	nlen = string_length(needle);
	len = string_wcount_sequence(haystack, needle);
	len += string_count_sequence(haystack, needle, string_length(haystack));
	result = alloc((len + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		while (haystack[j] && string_starts_with_sequence(&haystack[j], needle))
			j += nlen;
		if (haystack[j])
			result[i] = string_substring_sequence(&haystack[j], needle);
		j += string_length(result[i++]);
	}
	return (result);
}
