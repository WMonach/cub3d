/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:42:05 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/07 14:29:25 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	copy_path(t_data *data, int index, int size, char *path)
{
	data->texture_path[index] = malloc(sizeof(char) * (size + 1));
	if (!data->texture_path[index])
	{
		free_tab(data->texture_path, index);
		return (1);
	}
	map_strlcpy(data->texture_path[index], path, (size + 1));
	data->textures_tab_size++;
	return (0);
}

int	west_and_east_copy(t_data *data, char *path, char *id, int i)
{
	int	size;

	size = (ft_strlen(&path[i]) - 1);
	if (ft_strncmp(id, "WE", 2) == 0)
	{
		if (copy_path(data, 2, size, &path[i]) == 1)
			return (1);
		data->texture.west_path_copy = 1;
	}
	else
	{
		if (copy_path(data, 3, size, &path[i]) == 1)
			return (1);
		data->texture.east_path_copy = 1;
	}
	return (0);
}

int	copy_textures_path(t_data *data, char *path, char *id, int i)
{
	int	size;

	size = (ft_strlen(&path[i]) - 1);
	if (ft_strncmp(id, "NO", 2) == 0)
	{
		if (copy_path(data, 0, size, &path[i]) == 1)
			return (1);
		data->texture.north_path_copy = 1;
	}
	else if (ft_strncmp(id, "SO", 2) == 0)
	{
		if (copy_path(data, 1, size, &path[i]) == 1)
			return (1);
		data->texture.south_path_copy = 1;
	}
	else if (west_and_east_copy(data, path, id, i) == 1)
		return (1);
	else
		return (0);
	return (0);
}

int	save_texture(t_data *data, char *id, char *path)
{
	int	i;

	i = 2;
	while (path[i] == 9 || path[i] == 32)
		i++;
	if (copy_textures_path(data, path, id, i) == 1)
		return (1);
	data->texture_path[4] = NULL;
	return (0);
}
