/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:25:08 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/23 08:28:42 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_line_checking(t_data *data, char *line)
{
	(void)line;
	if (data->check_id_parsing == 0)
		data->check_id_parsing = 1;
	if (check_chars(line, "01NSEW ") == 1)
	{
		data->texture.rgb_f_copy = 1;
		return (1);
	}
	data->map_data.map_size++;
	return (0);
}

int	empty_line_in_map(t_data *data, char *line)
{
	if ((line[0] == '\n' || line[0] == '\0') && data->check_id_parsing == 1)
	{
		data->check_empty_line = 1;
		return (0);
	}
	return (1);
}

int	line_open(t_data *data, char *line)
{
	int	i;

	i = 0;
	(void)data;
	while (line[i] == 32)
		i++;
	if (line[i] == '0')
	{
		data->texture.rgb_f_copy = 1;
		printf("Error : a line of the map begins with a 0\n");
		return (1);
	}
	return (0);
}

int	line_parsing_loop(t_data *data, char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	data->line_tmp = line;
	while (line && line[i] && data->check_rgb_id == 0)
	{
		j = 0;
		while (j < data->id_number)
		{
			k = 0;
			while (data->texture_id[j][k])
			{
				if (check_id(data, i, j, k) == 0)
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	line_parsing(char *line, t_data *data)
{
	int	line_is_in_map;

	line_is_in_map = check_if_line_is_map(data, line);
	if (line && data->texture.check_all_id == 1 && line_is_in_map == 0)
	{
		if (data->check_empty_line == 1)
		{
			printf("Error : invalid map : empty line detected\n");
			data->texture.rgb_f_copy = 1;
			return (1);
		}
		if (map_line_checking(data, line) == 1)
			return (1);
		return (0);
	}
	if (empty_line_in_map(data, line) == 0)
		return (0);
	if (line_open(data, line) == 1)
		return (1);
	if (line_parsing_loop(data, line) == 0)
		return (0);
	if (error_return(data) == 0)
		printf("Error : unknown element found\n");
	return (1);
}
