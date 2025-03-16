/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:19:33 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/11 12:19:34 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

char	*string_append_scalar(char *dest, int32_t scalar, uint64_t destsize)
{
	uint64_t	i;

	i = string_length(dest);
	if ((i + 1) < destsize)
	{
		dest[i++] = (char)scalar;
		dest[i] = 0x00;
	}
	return (dest);
}

char	*string_append_sequence(char *dest, char *sequence, uint64_t destsize)
{
	uint64_t	i;
	uint64_t	j;

	if (!dest || !destsize)
		return (NULL);
	if (!sequence)
		return (dest);
	i = string_length(dest);
	j = 0;
	while ((i + 1) < destsize && sequence[j])
		dest[i++] = (char)sequence[j++];
	dest[i] = 0x00;
	return (dest);
}

char	*string_append_scalar_sequence(char *dest, int32_t scalar,
		char *sequence, uint64_t destsize)
{
	uint64_t	i;
	uint64_t	j;

	i = string_length(dest);
	if ((i + 1) < destsize)
	{
		dest[i++] = (char)scalar;
		dest[i] = 0x00;
	}
	if (!sequence)
		return (dest);
	j = 0;
	while (sequence[j] && (i + 1) < destsize)
		dest[i++] = (char)sequence[j++];
	dest[i] = 0x00;
	return (dest);
}

char	*string_append_many_sequence(char *dest, char **many, uint64_t destsize)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	k;
	char		*sequence;

	j = 0;
	i = string_length(dest);
	while (many[j])
	{
		k = 0;
		sequence = (char *)many[j];
		while (sequence[k] && (i + 1) < destsize)
			dest[i++] = (char)sequence[k++];
		dest[i] = 0x00;
	}
	return (dest);
}

char	*string_append_many_scalar_sequence(char *dest, int32_t scalar,
		char **many, uint64_t destsize)
{
	uint64_t	i;
	uint64_t	j;
	uint64_t	k;
	char		*sequence;

	j = 0;
	i = string_length(dest);
	while (many[j])
	{
		k = 0;
		sequence = (char *)many[j];
		if ((i + 1) < destsize)
		{
			dest[i++] = (char)scalar;
			dest[i] = 0x00;
		}
		while (sequence[k] && (i + 1) < destsize)
			dest[i++] = (char)sequence[k++];
		dest[i] = 0x00;
	}
	return (dest);
}
