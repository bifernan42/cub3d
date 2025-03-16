/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:59 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 15:45:59 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_dfs(t_map *map, int32_t x, int32_t y)
{
	if (x < 0 || x > (map->width + PADDING) || y < 0 || y > (map->height
			+ PADDING) || map->grid[y][x] == '1' || map->visited[y * map->width
		+ x])
		return ;
	if (map->grid[y][x] == '2' || map->grid[y][x] == '\0')
	{
		map->enclosed = false;
		return ;
	}
	map->visited[y * map->width + x] = true;
	map_dfs(map, x + 1, y);
	map_dfs(map, x - 1, y);
	map_dfs(map, x, y + 1);
	map_dfs(map, x, y - 1);
}

static bool	map_find_player(t_map *map)
{
	int32_t	x;
	int32_t	y;
	char	p;

	y = 0;
	while (y <= map->height)
	{
		x = 0;
		while (x <= map->width)
		{
			p = map->grid[y][x];
			if (p == 'W' || p == 'N' || p == 'E' || p == 'S')
			{
				map->player_pos_x = x;
				map->player_pos_y = y;
				map->player_dir = p;
				map->grid[y][x] = '0';
				return (true);
			}
			++x;
		}
		++y;
	}
	return (false);
}

bool	map_sanitize(t_map *map)
{
	map->enclosed = true;
	if (!map_find_player(map))
		return (false);
	map_dfs(map, map->player_pos_x, map->player_pos_y);
	return (map->enclosed);
}
