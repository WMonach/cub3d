/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:13:38 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 19:41:21 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_textures(t_data *data, int i)
{
	if (check_path_to_texture(data, i, 2) == 1)
	{
		data->texture.rgb_f_copy = 1;
		return (1);
	}
	if (check_duplicates(data, i) == 1)
	{
		printf("Error : duplicate texture detected\n");
		data->texture.rgb_f_copy = 1;
		return (1);
	}
	return (0);
}

int	check_colors(t_data *data, int i)
{
	data->length = 0;
	if (check_rgb(data, i) == 1)
	{
		data->texture.rgb_f_copy = 1;
		return (1);
	}
	if (check_duplicates_rgb(data, i) == 1)
	{
		printf("Error : duplicate RGB detected\n");
		data->texture.rgb_f_copy = 1;
		return (1);
	}
	return (0);
}

int	textures_parsing_and_save(t_data *data, int i, int j)
{
	if (check_textures(data, i) == 1)
		return (1);
	save_texture(data, data->texture_id[j], &data->line_tmp[i]);
	if (data->texture.check_no_texture == 1
		&& data->texture.check_so_texture == 1
		&& data->texture.check_we_texture == 1
		&& data->texture.check_ea_texture == 1)
		data->texture.check_texture_id = 1;
	return (0);
}

int	check_id(t_data *data, int i, int j, int k)
{
	if (ft_strlen(data->texture_id[j]) == 2)
	{
		if (data->line_tmp[i] == data->texture_id[j][k]
			&& data->line_tmp[i + 1] == data->texture_id[j][k + 1])
		{
			if (textures_parsing_and_save(data, i, j) == 1)
				return (1);
			else
				return (0);
		}
	}
	else if (ft_strlen(data->texture_id[j]) == 1)
	{
		if (data->line_tmp[i] == data->texture_id[j][k])
		{
			if (check_colors(data, i) == 1)
				return (1);
			save_rgb_values(data, data->texture_id[j], &data->line_tmp[i]);
			if (data->texture.check_f_texture == 1
				&& data->texture.check_c_texture == 1)
				data->texture.check_rgb_id = 1;
			return (0);
		}
	}
	return (1);
}
