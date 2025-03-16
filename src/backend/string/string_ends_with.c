/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:53:23 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:53:23 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

bool	string_ends_with_scalar(char *source, int32_t scalar)
{
	uint64_t	slen;

	if (!source || !source[0])
		return (false);
	slen = string_length(source);
	if (slen == 0)
		return (false);
	return (source[slen - 1] == scalar);
}

bool	string_ends_with_any(char *source, t_bitset *delimiters)
{
	uint64_t	slen;

	if (!source || !source[0])
		return (false);
	slen = string_length(source);
	if (slen == 0)
		return (false);
	return (bitset_is_set(delimiters, (uint64_t)source[slen - 1]) == true);
}

bool	string_ends_with_none(char *source, t_bitset *delimiters)
{
	uint64_t	slen;

	if (!source || !source[0])
		return (false);
	slen = string_length(source);
	if (slen == 0)
		return (false);
	return (bitset_is_set(delimiters, (uint64_t)source[slen - 1]) == false);
}

bool	string_ends_with_predicate(char *source, bool(predicate)(int32_t ch))
{
	uint64_t	slen;

	if (!source || !source[0])
		return (false);
	slen = string_length(source);
	if (slen == 0)
		return (false);
	return (predicate(source[slen - 1]) == true);
}

bool	string_ends_with_sequence(char *haystack, char *needle)
{
	uint64_t	slen;
	uint64_t	nlen;

	if (!haystack || !haystack[0] || !needle || !needle[0])
		return (false);
	slen = string_length(haystack);
	nlen = string_length(needle);
	if (slen < nlen)
		return (false);
	return (string_search_sequence(&haystack[slen - nlen], needle,
			nlen) != NULL);
}
