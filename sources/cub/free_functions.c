/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:36:51 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 19:22:37 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**free_texture_tab(t_data *data)
{
	if (data->texture.north_path_copy == 1)
		free(data->texture_path[0]);
	if (data->texture.south_path_copy == 1)
		free(data->texture_path[1]);
	if (data->texture.west_path_copy == 1)
		free(data->texture_path[2]);
	if (data->texture.east_path_copy == 1)
		free(data->texture_path[3]);
	free(data->texture_path);
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
