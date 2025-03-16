/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:27:54 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/08 18:27:55 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	container_cfg_parse_info_lines(t_container_cfg *cfg)
{
	uint64_t	i;

	i = 0;
	if (!cfg)
		return (false);
	while (cfg->file_lines[i])
	{
		if (config_line_is_texture_line(cfg->file_lines[i])
			&& config_sanitize_texture_line(cfg->file_lines[i]))
		{
			config_parse_texture_line(cfg, cfg->file_lines[i]);
			++cfg->info_line;
		}
		else if (config_line_is_color_line(cfg->file_lines[i])
			&& config_sanitize_color_line(cfg->file_lines[i]))
		{
			config_parse_color_line(cfg, cfg->file_lines[i]);
			++cfg->info_line;
		}
		++i;
	}
	return (true);
}

bool	container_cfg_parse_map_lines(t_container_cfg *cfg)
{
	t_bitset	syntax;
	uint64_t	pos_count;
	uint64_t	i;
	char		*ln;

	if (cfg->info_line != 6)
		return (false);
	i = 6;
	pos_count = 0;
	syntax = bitset_init_from_str("NSWE");
	while (cfg->file_lines[i])
	{
		ln = cfg->file_lines[i];
		pos_count += string_count_any(ln, &syntax, string_length(ln));
		if (config_line_is_map_line(ln) && config_sanitize_map_line(ln))
			config_parse_map_line(cfg, ln);
		else
			return (false);
		++i;
	}
	if (pos_count != 1)
		return (false);
	cfg->map_lines = &cfg->file_lines[cfg->info_line];
	return (true);
}

bool	container_cfg_parse(t_container_cfg *cfg)
{
	if (!container_cfg_parse_info_lines(cfg))
		return (false);
	if (!container_cfg_parse_map_lines(cfg))
		return (false);
	return (true);
}
