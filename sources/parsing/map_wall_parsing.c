/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:44 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 16:43:32 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exterior_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] == 32)
		i++;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != 32)
		{
			printf("Error : map is not closed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	space_check(char **map, int y, int x)
{
	if (map[y][x + 1] == 32)
	{
		printf("Error : empty space in map\n");
		return (1);
	}
	if (map[y][x - 1] == 32)
	{
		printf("Error : empty space in map\n");
		return (1);
	}
	if (map[y - 1][x] == 32)
	{
		printf("Error : empty space in map\n");
		return (1);
	}
	if (map[y + 1][x] == 32)
	{
		printf("Error : empty space in map\n");
		return (1);
	}
	return (0);
}

int	close_check(char **map, int y)
{
	size_t	i;
	size_t	diff;
	size_t	line_size;

	i = 0;
	line_size = ft_strlen(map[y]);
	diff = line_size - ft_strlen(map[y + 1]);
	if (last_char_is_not_one(map, line_size, y) == 1)
		return (1);
	if (line_size > ft_strlen(map[y + 1]))
	{
		while (i < diff)
		{
			if (map[y][line_size - 1] != '1')
			{
				printf("Error : map is not correctly closed on line %d\n",
					(y + 1));
				return (1);
			}
			line_size--;
			i++;
		}
	}
	return (0);
}

int	map_wall_parsing(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < data->map_data.map_size)
	{
		x = 0;
		if (first_or_last_line_ko(data, y) == 1)
			return (1);
		else
		{
			if (close_check(data->map, y) == 1)
				return (1);
			check_if_spawn_is_set(data, y);
			if (count_number_of_spawn(data, y) == 1)
				return (1);
			if (line_check_loop(data, y, x) == 1)
				return (1);
		}
		y++;
	}
	if (looking_for_multi_spawn(data) == 1)
		return (1);
	return (0);
}
