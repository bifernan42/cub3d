/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:46:11 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 15:46:12 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_bitset	bitset_init_empty(void)
{
	t_bitset	bitset;

	zeroed(&bitset, 4 * sizeof(uint64_t));
	return (bitset);
}

t_bitset	bitset_init_from_str(char *string)
{
	t_bitset	bitset;
	uint8_t		offset;
	uint8_t		index;
	uint64_t	*set;

	bitset = bitset_init_empty();
	while (*string)
	{
		index = (uint8_t)(*string);
		offset = index % 64;
		set = &bitset.set[index / 64];
		*set |= (1ULL << offset);
		string++;
	}
	return (bitset);
}

t_bitset	bitset_set_bit_range(t_bitset *bitset, char *string)
{
	uint8_t		offset;
	uint8_t		index;
	uint64_t	*set;

	while (*string)
	{
		index = (uint8_t)(*string);
		offset = index % 64;
		set = &bitset->set[index / 64];
		*set |= (1ULL << offset);
		string++;
	}
	return (*bitset);
}

void	bitset_set_bit(t_bitset *bitset, uint64_t index, bool value)
{
	uint8_t		offset;
	uint64_t	*set;

	if (index < BITSET_SIZE)
	{
		set = (uint64_t *)&bitset->set[index / 64];
		offset = index % 64;
		if (value)
			*set |= (1ULL << offset);
		else
			*set &= ~(1ULL << offset);
	}
}

bool	bitset_is_set(t_bitset *bitset, uint64_t index)
{
	uint8_t		offset;
	uint64_t	set;

	if (index < BITSET_SIZE)
	{
		set = (uint64_t)bitset->set[index / 64];
		offset = index % 64;
		return ((set >> offset) & 1ULL);
	}
	return (false);
}
