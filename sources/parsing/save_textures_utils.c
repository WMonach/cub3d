/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:28:57 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/07 14:29:29 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	copy_rgb_value(t_data *data, int index, int size, char *value)
{
	data->rgb_values[index] = malloc(sizeof(char) * (size + 1));
	if (!data->rgb_values[index])
	{
		free_tab(data->rgb_values, index);
		return (1);
	}
	map_strlcpy(data->rgb_values[index], value, (size + 1));
	data->rgb_tab_size++;
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
		data->texture.rgb_f_copy = 1;
	}
	if (strncmp(id, "C", 1) == 0)
	{
		if (copy_rgb_value(data, 1, size, &value[i]) == 1)
			return (1);
		data->texture.rgb_c_copy = 1;
	}
	data->rgb_values[2] = NULL;
	return (0);
}
