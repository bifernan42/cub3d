/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:10:02 by pollivie          #+#    #+#             */
/*   Updated: 2024/08/07 11:10:02 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int32_t	file_size(char *file_name)
{
	char	read_buffer[4096];
	int32_t	read_size;
	int32_t	total_size;
	int32_t	file_fd;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (-1);
	read_size = 4096;
	total_size = 0;
	while (read_size == 4096)
	{
		read_size = (int32_t)read(file_fd, read_buffer, sizeof(read_buffer)
				/ sizeof(read_buffer[0]));
		total_size += read_size;
	}
	file_fd = close(file_fd);
	return (total_size);
}

char	*file_open_read_to_end_alloc(char *file_name)
{
	char	*buffer;
	int32_t	size;
	int32_t	file_fd;

	if (!file_name)
		return (NULL);
	size = file_size(file_name);
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (NULL);
	buffer = alloc((uint64_t)size + 1);
	if (!buffer)
	{
		file_fd = close(file_fd);
		return (NULL);
	}
	if (read(file_fd, buffer, (uint64_t)size) != size)
	{
		file_fd = close(file_fd);
		buffer = dealloc(buffer);
		return (NULL);
	}
	file_fd = close(file_fd);
	return (buffer);
}

bool	file_is_correct_extension(char *file_name)
{
	return (string_ends_with_sequence(file_name, ".cub"));
}

void	*dealloc_array(char **ptr)
{
	int32_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
		dealloc(ptr[i++]);
	dealloc(ptr);
	return (NULL);
}

int32_t	string_to_rgb(const char *const line)
{
	int64_t	number;
	int32_t	i;

	if (!line || line[0] == '-' || line[0] == '+')
		return (-1);
	i = 0;
	number = 0;
	while (line[i] && is_digit(line[i]))
		number = (line[i++] - '0') + number * 10;
	if (number > 255)
		return (-1);
	return ((int32_t)number);
}
