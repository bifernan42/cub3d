/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sanitizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:35:30 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 11:35:30 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	config_sanitize_texture_line(char *texture_line)
{
	char	**temp;
	int32_t	fd;

	if (!texture_line)
		return (false);
	temp = string_split_predicate(texture_line, is_spaces);
	if (!temp)
		return (false);
	if (string_split_size(temp) != 2)
	{
		temp = dealloc_array(temp);
		return (false);
	}
	fd = open(temp[1], O_RDONLY);
	if (fd == -1)
	{
		temp = dealloc_array(temp);
		return (false);
	}
	fd = close(fd);
	temp = dealloc_array(temp);
	return (true);
}

static bool	config_sanitize_color_word(char *word)
{
	t_bitset	syntax;
	int32_t		value;

	if (!word)
		return (false);
	value = string_to_rgb(word);
	if (value == -1)
		return (false);
	syntax = bitset_init_from_str("0123456789,");
	if (!string_is_all_any(word, &syntax))
		return (false);
	return (true);
}

bool	config_sanitize_color_line(char *color_line)
{
	t_bitset	syntax;
	char		**temp;
	uint64_t	i;

	if (!color_line)
		return (false);
	syntax = bitset_init_from_str(",");
	if (string_count_any(color_line, &syntax, string_length(color_line)) > 2)
		return (false);
	syntax = bitset_init_from_str(" \n\t,");
	temp = string_split_any(color_line, &syntax);
	if (!temp)
		return (false);
	if (string_split_size(temp) < 2 || string_split_size(temp) > 4)
		return (dealloc_array(temp), (false));
	i = 1;
	while (temp[i] && config_sanitize_color_word(temp[i]))
		++i;
	if (i != string_split_size(temp))
		return (dealloc_array(temp), (false));
	temp = dealloc_array(temp);
	return (true);
}

bool	config_sanitize_map_line(char *map_line)
{
	t_bitset	syntax;

	if (!map_line)
		return (false);
	syntax = bitset_init_from_str("01NSEW \t\v");
	if (string_is_all_any(map_line, &syntax))
		return (true);
	return (false);
}
