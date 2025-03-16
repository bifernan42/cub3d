/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:08:09 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:08:10 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_clone_until_scalar(char *src, int32_t scalar)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_scalar(src, scalar);
	result = alloc(len + 1);
	string_copy_until_scalar(result, src, scalar, len + 1);
	return (result);
}

char	*string_clone_until_any(char *src, t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_any(src, delimiters);
	result = alloc(len + 1);
	string_copy_until_any(result, src, delimiters, len + 1);
	return (result);
}

char	*string_clone_until_none(char *src, t_bitset *delimiters)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_none(src, delimiters);
	result = alloc(len + 1);
	string_copy_until_none(result, src, delimiters, len + 1);
	return (result);
}

char	*string_clone_until_predicate(char *src, bool(predicate)(int32_t ch))
{
	char		*result;
	uint64_t	len;

	len = string_count_until_predicate(src, predicate);
	result = alloc(len + 1);
	string_copy_until_predicate(result, src, predicate, len + 1);
	return (result);
}

char	*string_clone_until_sequence(char *src, char *needle)
{
	char		*result;
	uint64_t	len;

	len = string_count_until_sequence(src, needle);
	result = alloc(len + 1);
	string_copy_until_sequence(result, src, needle, len + 1);
	return (result);
}
