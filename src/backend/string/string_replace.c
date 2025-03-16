/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:43:53 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:43:54 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_replace_scalar(char *source, int32_t scalar, int32_t with)
{
	char		*result;
	uint64_t	i;

	if (!source)
		return (NULL);
	result = dupz((void *)source, string_length(source));
	i = 0;
	while (result[i])
	{
		if (result[i] == scalar)
			result[i] = (char)with;
		++i;
	}
	return (result);
}

char	*string_replace_any(char *source, t_bitset *delimiters, int32_t with)
{
	char		*result;
	uint64_t	i;

	if (!source)
		return (NULL);
	result = dupz((void *)source, string_length(source));
	i = 0;
	while (result[i])
	{
		if (bitset_is_set(delimiters, (uint64_t)result[i]))
			result[i] = (char)with;
		++i;
	}
	return (result);
}

char	*string_replace_none(char *source, t_bitset *delimiters, int32_t with)
{
	char		*result;
	uint64_t	i;

	if (!source)
		return (NULL);
	result = dupz((void *)source, string_length(source));
	i = 0;
	while (result[i])
	{
		if (!bitset_is_set(delimiters, (uint64_t)result[i]))
			result[i] = (char)with;
		++i;
	}
	return (result);
}

char	*string_replace_predicate(char *source, bool(predicate)(int32_t ch),
		int32_t with)
{
	char		*result;
	uint64_t	i;

	if (!source)
		return (NULL);
	result = dupz((void *)source, string_length(source));
	i = 0;
	while (result[i])
	{
		if (predicate(result[i]))
			result[i] = (char)with;
		++i;
	}
	return (result);
}

char	*string_replace_sequence(char *haystack, char *needle, char *with,
		char *out_buffer)
{
	uint64_t	nlen;
	uint64_t	wlen;
	uint64_t	i;
	uint64_t	j;

	if (!haystack || !needle || (*needle == 0) || !with)
		return (NULL);
	wlen = string_length(with);
	nlen = string_length(needle);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		if (string_starts_with_sequence(&haystack[i], needle))
		{
			string_append_sequence(&out_buffer[j], with, UINT64_MAX);
			j += wlen;
			i += nlen;
		}
		else
			out_buffer[j++] = haystack[i++];
	}
	return (out_buffer);
}
