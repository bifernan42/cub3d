/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:28:15 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 18:28:20 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_parse_texture_line(t_container_cfg *cfg, char *texture_line)
{
	char	**temp;

	if (!cfg || !texture_line)
		return ;
	temp = string_split_predicate(texture_line, is_spaces);
	if (!temp)
		return ;
	if (!cfg->path_no_texture && string_starts_with_sequence(temp[0], "NO"))
		cfg->path_no_texture = string_clone(temp[1]);
	if (!cfg->path_so_texture && string_starts_with_sequence(temp[0], "SO"))
		cfg->path_so_texture = string_clone(temp[1]);
	if (!cfg->path_ea_texture && string_starts_with_sequence(temp[0], "EA"))
		cfg->path_ea_texture = string_clone(temp[1]);
	if (!cfg->path_we_texture && string_starts_with_sequence(temp[0], "WE"))
		cfg->path_we_texture = string_clone(temp[1]);
	temp = dealloc_array(temp);
	return ;
}

static void	config_convert_color_split(int32_t *out_color, char **rgb)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;

	r = string_to_rgb(rgb[1]);
	g = string_to_rgb(rgb[2]);
	b = string_to_rgb(rgb[3]);
	if (r == -1 || g == -1 || b == -1)
		*out_color = -1;
	else
		*out_color = (r << 16) + (g << 8) + (b);
}

void	config_parse_color_line(t_container_cfg *cfg, char *color_line)
{
	char		**temp;
	t_bitset	syntax;

	if (!cfg || !color_line)
		return ;
	syntax = bitset_init_from_str(", \v\t");
	temp = string_split_any(color_line, &syntax);
	if (!temp)
		return ;
	if (cfg->floor_color == -1 && string_starts_with_sequence(color_line, "F "))
		config_convert_color_split(&cfg->floor_color, temp);
	if (cfg->ceil_color == -1 && string_starts_with_sequence(color_line, "C "))
		config_convert_color_split(&cfg->ceil_color, temp);
	temp = dealloc_array(temp);
}

void	config_parse_map_line(t_container_cfg *cfg, char *map_line)
{
	int32_t	len;

	if (!cfg || !map_line)
		return ;
	len = (int32_t)string_length(map_line);
	if (len > cfg->map_width)
		cfg->map_width = len;
	++cfg->map_height;
}
