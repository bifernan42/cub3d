/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_starts_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:47:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:47:35 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

bool	string_starts_with_scalar(char *source, int32_t scalar)
{
	if (!source)
		return (false);
	return (source[0] == scalar);
}

bool	string_starts_with_any(char *source, t_bitset *delimiters)
{
	if (!source)
		return (false);
	return (bitset_is_set(delimiters, (uint64_t)source[0]) == true);
}

bool	string_starts_with_none(char *source, t_bitset *delimiters)
{
	if (!source)
		return (false);
	return (bitset_is_set(delimiters, (uint64_t)source[0]) == false);
}

bool	string_starts_with_predicate(char *source, bool(predicate)(int32_t ch))
{
	if (!source)
		return (false);
	return (predicate(source[0]) == true);
}

bool	string_starts_with_sequence(char *haystack, char *needle)
{
	if (!haystack || !needle)
		return (false);
	return (string_search_sequence(haystack, needle, string_length(needle)));
}
