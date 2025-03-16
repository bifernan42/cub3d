/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:09:25 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/13 11:09:26 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slib.h"

t_entry	*hashmap_body_create(uint64_t capacity)
{
	return ((t_entry *)alloc(capacity * sizeof(t_entry)));
}

uint64_t	hashmap_body_find_empty(t_hashmap *hashmap, char *key)
{
	uint64_t	index;

	index = hashmap_hash(key) % hashmap->capacity;
	while (hashmap->body[index].key != NULL
		&& string_compare(hashmap->body[index].key, key) != 0)
		index = (index + 1) % hashmap->capacity;
	return (index);
}

void	hashmap_body_remove(t_hashmap *hashmap, char *key)
{
	uint64_t	index;

	index = hashmap_body_find_empty(hashmap, key);
	if (hashmap->body[index].key != 0)
	{
		hashmap->body[index].key = 0;
		hashmap->body[index].value = 0;
		hashmap->size--;
	}
}

void	hashmap_body_resize(t_hashmap *hashmap, uint64_t new_capacity)
{
	t_entry		*entry_old;
	uint64_t	capacity_old;
	uint64_t	i;

	entry_old = hashmap->body;
	capacity_old = hashmap->capacity;
	new_capacity = find_next_prime(new_capacity);
	hashmap->body = hashmap_body_create(new_capacity);
	hashmap->capacity = new_capacity;
	i = 0;
	while (i < capacity_old)
	{
		if (entry_old[i].key != NULL)
			hashmap_put(hashmap, entry_old[i].key, entry_old[i].value);
		++i;
	}
}
