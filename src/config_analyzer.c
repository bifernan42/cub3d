/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:45:47 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 11:45:48 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	config_line_is_texture_line(char *current_line)
{
	if (string_starts_with_sequence(current_line, "NO "))
		return (true);
	else if (string_starts_with_sequence(current_line, "SO "))
		return (true);
	else if (string_starts_with_sequence(current_line, "WE "))
		return (true);
	else if (string_starts_with_sequence(current_line, "EA "))
		return (true);
	return (false);
}

bool	config_line_is_color_line(char *current_line)
{
	if (string_starts_with_sequence(current_line, "F "))
		return (true);
	else if (string_starts_with_sequence(current_line, "C "))
		return (true);
	return (false);
}

bool	config_line_is_map_line(char *current_line)
{
	t_bitset	map_line_syntax;

	map_line_syntax = bitset_init_from_str("NSWE01 \t\v");
	if (string_is_all_any(current_line, &map_line_syntax))
		return (true);
	return (false);
}
