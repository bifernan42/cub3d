/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:33:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 15:33:08 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_alloc(t_map *map, int32_t height, int32_t width)
{
	int32_t	i;

	map->grid = alloc(sizeof(char *) * ((uint64_t)height + PADDING + 1));
	map->visited = alloc(sizeof(bool) * (((uint64_t)height + PADDING)
				* ((uint64_t)width + PADDING)));
	if (!map->grid)
		return (false);
	i = 0;
	while (i < (height + PADDING))
	{
		map->grid[i] = alloc(sizeof(char) * ((uint64_t)width + PADDING + 1));
		if (!map->grid[i])
			return (false);
		filled(map->grid[i], '2', ((uint64_t)(width + PADDING) * sizeof(char)));
		++i;
	}
	map->grid[i] = NULL;
	return (true);
}

void	map_copy(t_map *map, int32_t height, char **from)
{
	int32_t	y;
	int32_t	x;

	y = 1;
	while (y <= height)
	{
		x = 1;
		while (from[y - 1][x - 1] && is_spaces(from[y - 1][x - 1]))
			map->grid[y][x++] = '2';
		while (from[y - 1][x - 1])
		{
			if (is_spaces(from[y - 1][x - 1]))
				map->grid[y][x] = '2';
			else
				map->grid[y][x] = from[y - 1][x - 1];
			++x;
		}
		++y;
	}
}

t_map	*map_create(t_container_cfg *cfg)
{
	t_map	*map;

	map = alloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = cfg->map_height;
	map->width = cfg->map_width;
	map->enclosed = true;
	if (!map_alloc(map, cfg->map_height, cfg->map_width))
		return (map_destroy(map));
	map_copy(map, map->height, cfg->map_lines);
	return (map);
}

t_map	*map_destroy(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->grid)
		map->grid = dealloc_array(map->grid);
	if (map->visited)
		map->visited = dealloc(map->visited);
	return (dealloc(map));
}
