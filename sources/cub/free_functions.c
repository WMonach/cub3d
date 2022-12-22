/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:36:51 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 13:21:22 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**free_texture_tab(t_data *data)
{
	if (data->texture.north_path_copy == 1)
	{
		free(data->texture_path[0]);
		data->texture_path[0] = NULL;
	}
	if (data->texture.south_path_copy == 1)
	{
		free(data->texture_path[1]);
		data->texture_path[1] = NULL;
	}
	if (data->texture.west_path_copy == 1)
	{
		free(data->texture_path[2]);
		data->texture_path[2] = NULL;
	}
	if (data->texture.east_path_copy == 1)
	{
		free(data->texture_path[3]);
		data->texture_path[3] = NULL;
	}
	free(data->texture_path);
	data->texture_path = NULL;
	return (0);
}

char	**free_rgb_tab(t_data *data)
{
	if (data->texture.rgb_f_copy == 0)
	{
		free(data->rgb_values[0]);
		free(data->rgb_values[1]);
	}
	free(data->rgb_values);
	return (0);
}

char	**free_tab(char **tab, int i)
{
	if (i == 0)
	{
		free(tab);
		return (0);
	}
	while (i >= 0)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}
