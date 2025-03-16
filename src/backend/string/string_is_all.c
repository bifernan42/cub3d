/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_is_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:11:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/23 13:11:46 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

bool	string_is_all_scalar(char *source, int32_t scalar)
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (source[i] != scalar)
			return (false);
		++i;
	}
	return (true);
}

bool	string_is_all_any(char *source, t_bitset *any)
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (!bitset_is_set(any, (uint64_t)source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool	string_is_all_none(char *source, t_bitset *none)
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (bitset_is_set(none, (uint64_t)source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool	string_is_all_predicate(char *source, bool(predicate)(int32_t ch))
{
	uint64_t	i;

	i = 0;
	while (source[i])
	{
		if (!predicate(source[i]))
			return (false);
		++i;
	}
	return (true);
}

bool	string_is_all_sequence(char *source, char *sequence)
{
	return (string_compare(source, sequence) == 0);
}
