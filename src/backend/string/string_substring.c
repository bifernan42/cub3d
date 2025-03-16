/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:13:57 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:13:57 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_substring_scalar(char *src, int32_t scalar)
{
	char	*result;

	src += string_count_leading_scalar(src, scalar);
	result = string_clone_until_scalar(src, scalar);
	return (result);
}

char	*string_substring_any(char *src, t_bitset *delimiters)
{
	char	*result;

	src += string_count_leading_any(src, delimiters);
	result = string_clone_until_any(src, delimiters);
	return (result);
}

char	*string_substring_none(char *src, t_bitset *delimiters)
{
	char	*result;

	src += string_count_leading_none(src, delimiters);
	result = string_clone_until_none(src, delimiters);
	return (result);
}

char	*string_substring_predicate(char *src, bool(predicate)(int32_t ch))
{
	char	*result;

	src += string_count_leading_predicate(src, predicate);
	result = string_clone_until_predicate(src, predicate);
	return (result);
}

char	*string_substring_sequence(char *src, char *needle)
{
	char	*result;

	src += string_count_leading_sequence(src, needle) * string_length(needle);
	result = string_clone_until_sequence(src, needle);
	return (result);
}
