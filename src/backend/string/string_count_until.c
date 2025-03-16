/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:33:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 14:33:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_count_until_scalar(char *source, int32_t scalar)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (source[i] == scalar)
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_until_any(char *source, t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (bitset_is_set(delimiters, (uint64_t)source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_until_none(char *source, t_bitset *delimiters)
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (!bitset_is_set(delimiters, (uint64_t)source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_until_predicate(char *source,
		bool(predicate)(int32_t ch))
{
	uint64_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i])
	{
		if (predicate(source[i]))
			break ;
		++i;
	}
	return (i);
}

uint64_t	string_count_until_sequence(char *haystack, char *needle)
{
	uint64_t	u1;
	uint64_t	u2;
	uint64_t	count;

	if (!haystack || needle[0] == '\0')
		return (0);
	u1 = 0;
	count = 0;
	while (haystack[u1])
	{
		u2 = 0;
		while (haystack[u1] && haystack[u1] == needle[u2])
		{
			u2++;
			u1++;
		}
		if (!needle[u2])
			return (count);
		count++;
		u1 = (u1 - u2) + 1;
	}
	return (count);
}
