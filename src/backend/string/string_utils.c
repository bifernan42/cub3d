/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:32:50 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/06 13:32:51 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

uint64_t	string_length(char *string)
{
	char	*ptr;

	if (!string)
		return (0);
	ptr = (char *)string;
	while (*ptr)
		++ptr;
	return ((uint64_t)(ptr - string));
}

uint64_t	string_split_length(char **split)
{
	uint64_t	total;
	uint64_t	i;

	if (!split || *split == 0)
		return (0);
	i = 0;
	total = 0;
	while (split[i])
		total += string_length(split[i++]);
	return (total);
}

uint64_t	string_index_of_difference(char *s1, char *s2)
{
	uint64_t	index;

	if (!s1 || !s2)
		return (NOTFOUND);
	index = 0;
	while (s1[index] && s1[index] == s2[index])
		++index;
	return (index);
}

uint64_t	string_compute_replace_sequence_size(char *haystack, char *needle,
		char *with)
{
	uint64_t	hlen;
	uint64_t	nlen;
	uint64_t	wlen;
	uint64_t	count;

	hlen = string_length(haystack);
	nlen = string_length(needle);
	wlen = string_length(with);
	count = string_count_sequence(haystack, needle, hlen);
	hlen = hlen - (count * nlen);
	hlen = hlen + (count * wlen);
	return (hlen);
}
