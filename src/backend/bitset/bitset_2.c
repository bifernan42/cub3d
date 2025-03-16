/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:46:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/21 15:46:16 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_bitset	bitset_and(t_bitset *bitset1, t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] & bitset2->set[index];
		++index;
	}
	return (result);
}

t_bitset	bitset_or(t_bitset *bitset1, t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] | bitset2->set[index];
		++index;
	}
	return (result);
}

t_bitset	bitset_xor(t_bitset *bitset1, t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] ^ (bitset2->set[index]);
		++index;
	}
	return (result);
}

t_bitset	bitset_difference(t_bitset *bitset1, t_bitset *bitset2)
{
	t_bitset	result;
	uint64_t	index;

	index = 0;
	while (index < 4)
	{
		result.set[index] = bitset1->set[index] & ~(bitset2->set[index]);
		++index;
	}
	return (result);
}
