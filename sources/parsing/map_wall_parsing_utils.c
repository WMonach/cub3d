/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_parsing_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:38 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 16:34:24 by ebrodeur         ###   ########lyon.fr   */
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
