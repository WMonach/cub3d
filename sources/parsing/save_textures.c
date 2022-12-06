/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:42:05 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 13:04:39 by ebrodeur         ###   ########lyon.fr   */
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
	ft_strlcpy(data->texture_path[index], path, (size + 1));
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
	}
	else if (ft_strncmp(id, "SO", 2) == 0)
	{
		if (copy_path(data, 1, size, &path[i]) == 1)
			return (1);
	}
	else if (ft_strncmp(id, "WE", 2) == 0)
	{
		if (copy_path(data, 2, size, &path[i]) == 1)
			return (1);
	}
	else
	{
		if (copy_path(data, 3, size, &path[i]) == 1)
			return (1);
	}
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

int	copy_rgb_value(t_data *data, int index, int size, char *value)
{
	data->rgb_values[index] = malloc(sizeof(char) * (size + 1));
	if (!data->rgb_values[index])
	{
		free_tab(data->rgb_values, index);
		return (1);
	}
	ft_strlcpy(data->rgb_values[index], value, (size + 1));
	return (0);
}

int	save_rgb_values(t_data *data, char *id, char *value)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (value[i] == 9 || value[i] == 32)
		i++;
	size = ft_strlen(&value[i]) - 1;
	if (strncmp(id, "F", 1) == 0)
	{
		if (copy_rgb_value(data, 0, size, &value[i]) == 1)
			return (1);
	}
	if (strncmp(id, "C", 1) == 0)
	{
		if (copy_rgb_value(data, 1, size, &value[i]) == 1)
			return (1);
	}
	data->rgb_values[2] = NULL;
	return (0);
}
