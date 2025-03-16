/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:44:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 12:44:38 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_copy_until_scalar(char *dest, char *src, int32_t scalar,
		uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (*src == scalar)
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_any(char *dest, char *src, t_bitset *delimiters,
		uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (bitset_is_set(delimiters, (uint64_t)(*src)))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_none(char *dest, char *src, t_bitset *delimiters,
		uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (!bitset_is_set(delimiters, (uint64_t)(*src)))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_predicate(char *dest, char *src,
		bool(predicate)(int32_t ch), uint64_t destsize)
{
	uint64_t	i;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	while (*src && i < (destsize - 1))
	{
		if (predicate(*src))
			break ;
		dest[i++] = *src++;
	}
	dest[i] = 0x00;
	return (i);
}

uint64_t	string_copy_until_sequence(char *dest, char *src, char *needle,
		uint64_t destsize)
{
	uint64_t	i;
	char		*end;

	if (!dest || !src || destsize == 0)
		return (string_length(src));
	i = 0;
	end = string_search_sequence(src, needle, string_length(src));
	if (!end)
		return (string_copy_until_scalar(dest, src, '\0', destsize));
	else
	{
		while (src < end && i < (destsize - 1))
			dest[i++] = *src++;
		dest[i] = 0x00;
	}
	return (i);
}
