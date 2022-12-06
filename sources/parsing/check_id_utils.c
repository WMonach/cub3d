/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:07:56 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 11:08:17 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_duplicates_rgb(t_data *data, int i)
{
	if ((ft_strncmp(&data->line_tmp[i], "F", 1) == 0)
		&& data->texture.check_f_texture == 0)
		data->texture.check_f_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "F", 1) == 0)
		&& data->texture.check_f_texture == 1)
		return (1);
	if ((ft_strncmp(&data->line_tmp[i], "C", 1) == 0)
		&& data->texture.check_c_texture == 0)
		data->texture.check_c_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "C", 1) == 0)
		&& data->texture.check_c_texture == 1)
		return (1);
	return (0);
}

int	check_duplicates(t_data *data, int i)
{
	if ((ft_strncmp(&data->line_tmp[i], "NO", 2) == 0)
		&& data->texture.check_no_texture == 0)
		data->texture.check_no_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "NO", 2) == 0)
		&& data->texture.check_no_texture == 1)
		return (1);
	if ((ft_strncmp(&data->line_tmp[i], "SO", 2) == 0)
		&& data->texture.check_so_texture == 0)
		data->texture.check_so_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "SO", 2) == 0)
		&& data->texture.check_so_texture == 1)
		return (1);
	if ((ft_strncmp(&data->line_tmp[i], "WE", 2) == 0)
		&& data->texture.check_we_texture == 0)
		data->texture.check_we_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "WE", 2) == 0)
		&& data->texture.check_we_texture == 1)
		return (1);
	if ((ft_strncmp(&data->line_tmp[i], "EA", 2) == 0)
		&& data->texture.check_ea_texture == 0)
		data->texture.check_ea_texture = 1;
	else if ((ft_strncmp(&data->line_tmp[i], "EA", 2) == 0)
		&& data->texture.check_ea_texture == 1)
		return (1);
	return (0);
}
