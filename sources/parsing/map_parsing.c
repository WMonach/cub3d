/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:52:18 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 16:42:45 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	map_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size)
	{
		if (src[i] == '\n')
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

void	map_line_copy(t_data *data, char *line, int i)
{
	if (i == (data->map_data.map_size - 1))
		map_strlcpy(data->map[i], line, (ft_strlen(line) + 1));
	else
		map_strlcpy(data->map[i], line, ft_strlen(line));
	return ;
}

int	copy_map_in_tab(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * (data->map_data.map_size + 1));
	if (!data->map)
		return (1);
	while (i < data->map_data.map_size)
	{
		if (i > 0)
			line = get_next_line(fd);
		if (i == (data->map_data.map_size - 1))
			data->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		else
			data->map[i] = malloc(sizeof(char) * ft_strlen(line));
		if (!data->map[i])
		{
			free_tab(data->map, i);
			return (1);
		}
		map_line_copy(data, line, i);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	return (0);
}

int	map_copy(t_data *data, char *file)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	fd = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	while (i < data->nb_of_lines)
	{
		line = get_next_line(fd);
		while (line[j] == 32)
			j++;
		if (line[j] == '1')
			break ;
		free(line);
		j = 0;
		i++;
	}
	if (copy_map_in_tab(data, line, fd) == 1)
		return (1);
	close(fd);
	return (0);
}
