/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trim_trailing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:22:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 15:22:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_trim_trailing_scalar(char *source, int32_t scalar)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_scalar(source, scalar);
	return (string_trim_right(source, amount));
}

char	*string_trim_trailing_any(char *source, t_bitset *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_any(source, delimiters);
	return (string_trim_right(source, amount));
}

char	*string_trim_trailing_none(char *source, t_bitset *delimiters)
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_none(source, delimiters);
	return (string_trim_right(source, amount));
}

char	*string_trim_trailing_predicate(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	amount;

	if (!source)
		return (NULL);
	amount = string_count_trailing_predicate(source, predicate);
	return (string_trim_right(source, amount));
}

char	*string_trim_trailing_sequence(char *haystack, char *needle)
{
	uint64_t	amount;

	if (!haystack)
		return (NULL);
	amount = string_length(needle) * string_count_trailing_sequence(haystack,
			needle);
	return (string_trim_right(haystack, amount));
}
