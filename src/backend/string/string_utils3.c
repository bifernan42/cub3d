/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:03:26 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 13:03:27 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_compute_scalar_split_size(char *source, int32_t scalar)
{
	uint64_t	word_count;

	word_count = 0;
	while (*source)
	{
		while (*source && *source == scalar)
			++source;
		if (*source)
			++word_count;
		while (*source && *source != scalar)
			++source;
	}
	return (word_count);
}

uint64_t	string_compute_any_split_size(char *source, t_bitset *delimiters)
{
	uint64_t	word_count;

	word_count = 0;
	while (*source)
	{
		while (*source && bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		if (*source)
			++word_count;
		while (*source && !bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
	}
	return (word_count);
}

uint64_t	string_compute_none_split_size(char *source, t_bitset *delimiters)
{
	uint64_t	word_count;

	word_count = 0;
	while (*source)
	{
		while (*source && !bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
		if (*source)
			++word_count;
		while (*source && bitset_is_set(delimiters, (uint64_t)(*source)))
			++source;
	}
	return (word_count);
}

uint64_t	string_compute_predicate_split_size(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	word_count;

	word_count = 0;
	while (*source)
	{
		while (*source && predicate(*source))
			++source;
		if (*source)
			++word_count;
		while (*source && !predicate(*source))
			++source;
	}
	return (word_count);
}

uint64_t	string_compute_sequence_split_size(char *source, char *needle)
{
	uint64_t	word_count;
	uint64_t	nlen;
	uint64_t	slen;
	uint64_t	i;

	i = 0;
	word_count = 0;
	nlen = string_length(needle);
	slen = string_length(source);
	while (source[i])
	{
		while (i < slen && string_starts_with_sequence(&source[i], needle))
			i += nlen;
		if (source[i])
			++word_count;
		while (i < slen && !string_starts_with_sequence(&source[i], needle))
			++i;
	}
	return (word_count);
}
