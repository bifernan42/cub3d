/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:09:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/13 11:09:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_hashmap	*hashmap_create(uint64_t capacity)
{
	t_hashmap	*hashmap;

	hashmap = alloc(sizeof(t_hashmap));
	if (!hashmap)
		return (NULL);
	hashmap->size = 0;
	hashmap->capacity = find_next_prime(capacity);
	hashmap->body = hashmap_body_create(hashmap->capacity);
	return (hashmap);
}

void	hashmap_destroy(t_hashmap *hashmap)
{
	if (!hashmap)
		return ;
	if (hashmap->body != 0)
		dealloc(hashmap->body);
	dealloc(hashmap);
}

uintptr_t	hashmap_get(t_hashmap *hashmap, char *key)
{
	uint64_t	index;

	index = hashmap_body_find_empty(hashmap, key);
	if (hashmap->body[index].key != NULL)
		return (hashmap->body[index].value);
	else
		return (0);
}

void	hashmap_put(t_hashmap *hashmap, char *key, uintptr_t value)
{
	uint64_t	index;

	index = hashmap_body_find_empty(hashmap, key);
	if (hashmap->body[index].key != 0)
		hashmap->body[index].value = value;
	else
	{
		hashmap->size++;
		if ((double)hashmap->size / (double)hashmap->capacity > 0.8)
		{
			hashmap_body_resize(hashmap, hashmap->capacity * 2);
			index = hashmap_body_find_empty(hashmap, key);
		}
		hashmap->body[index].key = key;
		hashmap->body[index].value = value;
	}
}

uint64_t	hashmap_hash(char *str)
{
	unsigned long	seed;
	int				val;

	seed = 5381;
	while (*str)
	{
		val = *str++;
		seed = ((seed << 5) + seed) + (unsigned long)val;
	}
	return (seed);
}
