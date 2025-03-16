/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_contains.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:39:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:39:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

bool	string_contains_scalar(char *source, int32_t scalar, uint64_t n)
{
	return (string_search_scalar(source, scalar, n) != NULL);
}

bool	string_contains_any(char *source, t_bitset *delimiters, uint64_t n)
{
	return (string_search_any(source, delimiters, n) != NULL);
}

bool	string_contains_none(char *source, t_bitset *delimiters, uint64_t n)
{
	return (string_search_any(source, delimiters, n) == NULL);
}

bool	string_contains_predicate(char *source, bool(predicate)(int32_t ch),
		uint64_t n)
{
	return (string_search_predicate(source, predicate, n) != NULL);
}

bool	string_contains_sequence(char *haystack, char *needle, uint64_t n)
{
	return (string_search_sequence(haystack, needle, n) != NULL);
}
