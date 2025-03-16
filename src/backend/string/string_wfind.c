/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_wfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:55:31 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 11:55:31 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_wfind_scalar(char *source, int32_t scalar,
		uint64_t *out_start, uint64_t *out_end)
{
	uint64_t	len;

	if (!source)
		return (0);
	len = 0;
	while (source[*out_start] && source[*out_start] == scalar)
		(*out_start) += 1;
	*out_end = *out_start;
	while (source[*out_end] && source[*out_end] != scalar)
		(*out_end) += 1;
	len = *out_end - *out_start;
	return (len);
}

uint64_t	string_wfind_any(char *source, t_bitset *delimiters,
		uint64_t *out_start, uint64_t *out_end)
{
	uint64_t	len;

	if (!source)
		return (0);
	len = 0;
	while (source[*out_start] && bitset_is_set(delimiters,
			(uint64_t)source[*out_start]))
		(*out_start) += 1;
	*out_end = *out_start;
	while (source[*out_end] && !bitset_is_set(delimiters,
			(uint64_t)source[*out_end]))
		(*out_end) += 1;
	len = *out_end - *out_start;
	return (len);
}

uint64_t	string_wfind_none(char *source, t_bitset *delimiters,
		uint64_t *out_start, uint64_t *out_end)
{
	uint64_t	len;

	if (!source)
		return (0);
	len = 0;
	while (source[*out_start] && !bitset_is_set(delimiters,
			(uint64_t)source[*out_start]))
		(*out_start) += 1;
	*out_end = *out_start;
	while (source[*out_end] && bitset_is_set(delimiters,
			(uint64_t)source[*out_end]))
		(*out_end) += 1;
	len = *out_end - *out_start;
	return (len);
}

uint64_t	string_wfind_predicate(char *source, bool(predicate)(int32_t ch),
		uint64_t *out_start, uint64_t *out_end)
{
	uint64_t	len;

	if (!source)
		return (0);
	len = 0;
	while (source[*out_start] && predicate(source[*out_start]))
		(*out_start) += 1;
	*out_end = *out_start;
	while (source[*out_end] && !predicate(source[*out_end]))
		(*out_end) += 1;
	len = *out_end - *out_start;
	return (len);
}

uint64_t	string_wfind_sequence(char *source, char *needle,
		uint64_t *out_start, uint64_t *out_end)
{
	uint64_t	len;
	uint64_t	nlen;
	uint64_t	slen;

	if (!source)
		return (0);
	len = 0;
	nlen = string_length(needle);
	slen = string_length(source);
	if (slen < nlen || (slen - *out_start) < nlen)
		return (0);
	while (source[*out_start]
		&& string_starts_with_sequence(&source[*out_start], needle))
		*out_start += nlen;
	*out_end = *out_start;
	while (source[*out_end] && !string_starts_with_sequence(&source[*out_end],
			needle))
		*out_end += 1;
	len = *out_end - *out_start;
	return (len);
}
