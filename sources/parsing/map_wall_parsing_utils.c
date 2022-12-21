/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_parsing_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:38 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 13:27:25 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	first_or_last_line_ko(t_data *data, int y)
{
	if (y == 0 || (y == (data->map_data.map_size - 1)))
	{
		if (exterior_line_check(data->map[y]) == 1)
			return (1);
	}
	return (0);
}

int	line_check_loop(t_data *data, int y, int x)
{
	while ((size_t)(x) < ft_strlen(data->map[y]))
	{
		if (data->map[y][x] == '0')
		{
			if (space_check(data->map, y, x) == 1)
				return (1);
		}
		x++;
	}
	if (x > data->width)
		data->width = x;
	return (0);
}

int	last_char_is_not_one(char **map, int line_size, int y)
{
	if (map[y][line_size - 1] != '1')
	{
		printf("Error : map is not correctly closed on line %d\n", (y + 1));
		return (1);
	}
	return (0);
}

int	close_check(char **map, int y)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	line_size = ft_strlen(map[y]);
	if (last_char_is_not_one(map, line_size, y) == 1)
		return (1);
	if (previous_line_shorter(map, i, line_size, y) == 1)
		return (1);
	if (next_line_shorter(map, i, line_size, y) == 1)
		return (1);
	return (0);
}

int	map_wall_parsing_loop(t_data *data, int y, int x)
{
	while (y < data->map_data.map_size)
	{
		x = 0;
		if (y == 0 || (y == (data->map_data.map_size - 1)))
		{
			if (exterior_line_check(data->map[y]) == 1)
				return (1);
		}
		else
		{
			if (close_check(data->map, y) == 1)
				return (1);
			if (data->map_data.check_north_spawn == 0
				&& data->map_data.check_south_spawn == 0
				&& data->map_data.check_west_spawn == 0
				&& data->map_data.check_east_spawn == 0)
				check_if_spawn_is_set(data, y, 0);
			if (count_number_of_spawn(data, y) == 1)
				return (1);
			if (line_check_loop(data, y, x) == 1)
				return (1);
		}
		y++;
	}
	return (0);
}
