/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tokenize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:41 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/21 10:59:42 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_tokenize_scalar(char *source, int32_t scalar, int32_t marker)
{
	char	*result;

	result = string_replace_scalar(source, scalar, marker);
	return (result);
}

char	*string_tokenize_any(char *source, t_bitset *delimiters, int32_t marker)
{
	char	*result;

	result = string_replace_any(source, delimiters, marker);
	return (result);
}

char	*string_tokenize_none(char *source, t_bitset *delimiters,
		int32_t marker)
{
	char	*result;

	result = string_replace_none(source, delimiters, marker);
	return (result);
}

char	*string_tokenize_predicate(char *source, bool(predicate)(int32_t ch),
		int32_t marker)
{
	char	*result;

	result = string_replace_predicate(source, predicate, marker);
	return (result);
}

char	*string_tokenize_sequence(char *haystack, char *needle, int32_t marker)
{
	char	*result;
	char	temp[2];

	temp[0] = (char)marker;
	temp[1] = 0x00;
	result = alloc(string_compute_replace_sequence_size(haystack, needle, temp)
			+ 1);
	result = string_replace_sequence(haystack, needle, temp, result);
	return (result);
}
