/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_trailing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:28 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:34:28 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_count_trailing_scalar(char *source, int32_t scalar)
{
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	slen = string_length(source);
	if (slen == 0)
		return (0);
	while ((slen - i))
	{
		if (source[slen - i - 1] != scalar)
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_trailing_any(char *source, t_bitset *delimiters)
{
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	slen = string_length(source);
	if (slen == 0)
		return (0);
	while (source[slen - i - 1])
	{
		if (!bitset_is_set(delimiters, (uint64_t)source[slen - i - 1]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_trailing_none(char *source, t_bitset *delimiters)
{
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	slen = string_length(source);
	if (slen == 0)
		return (0);
	while (slen - i)
	{
		if (bitset_is_set(delimiters, (uint64_t)source[slen - i - 1]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_trailing_predicate(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	slen;
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	slen = string_length(source);
	if (slen == 0)
		return (0);
	while (slen - i)
	{
		if (!predicate(source[slen - i - 1]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_trailing_sequence(char *haystack, char *needle)
{
	uint64_t	haystack_len;
	uint64_t	needle_len;
	uint64_t	count;
	char		*haystack_end;

	if (!haystack || !needle)
		return (0);
	count = 0;
	needle_len = string_length(needle);
	haystack_len = string_length(haystack);
	haystack_end = (char *)haystack;
	haystack = (char *)(haystack + haystack_len - needle_len);
	while (haystack >= haystack_end && string_ncompare(haystack, needle,
			needle_len) == 0)
	{
		haystack -= needle_len;
		count++;
	}
	return (count);
}
