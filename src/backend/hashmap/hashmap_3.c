/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:18:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/13 11:18:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

bool	is_prime(uint64_t num)
{
	uint64_t	i;

	if (num <= 1)
		return (false);
	if (num == 2)
		return (true);
	if (num % 2 == 0)
		return (false);
	i = 3;
	while (i <= (num * num))
	{
		if (num % i == 0)
			return (false);
		i += 2;
	}
	return (true);
}

uint64_t	find_next_prime(uint64_t n)
{
	uint64_t	result;

	result = n + 1;
	while (true)
	{
		if (is_prime(result))
			return (result);
		result++;
	}
}
