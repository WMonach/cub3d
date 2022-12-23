/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:56:31 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 09:34:10 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	line_parsing_call_and_set_all_id_check(t_data *data, char *line, int fd)
{
	if (data->texture.check_texture_id == 1
		&& data->texture.check_rgb_id == 1)
		data->texture.check_all_id = 1;
	if (line_parsing(line, data) == 1)
	{
		free(line);
		close(fd);
		return (1);
	}
	return (0);
}

int	check_file_loop(t_data *data, char *line, int fd, int i)
{
	while (i < data->nb_of_lines)
	{
		line = get_next_line(fd);
		if ((line[0] == '\n' || line[0] == '\0')
			&& data->check_id_parsing == 0)
			;
		else
		{
			if (line_parsing_call_and_set_all_id_check(data, line, fd) == 1)
				return (1);
		}
		i++;
		free(line);
	}
	return (0);
}

int	error_return(t_data *data)
{
	if (data->texture.check_rgb_id != 1 && data->texture.check_texture_id == 1)
	{
		data->texture.rgb_f_copy = 1;
		printf("Error : a color for floor or ceiling is missing\n");
		return (1);
	}
	if (data->texture.check_texture_id != 1)
	{
		data->texture.rgb_f_copy = 1;
		printf("Error : a texture is missing\n");
		return (1);
	}
	return (0);
}
