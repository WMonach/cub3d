/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:25:23 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/06 13:07:45 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_if_spawn_is_set(t_data *data, int y)
{
	int	i;

	i = 0;
	while (data->map[y][i])
	{
		if (data->map[y][i] == 'N' && data->map_data.check_north_spawn == 0)
			data->map_data.check_north_spawn = 1;
		if (data->map_data.check_north_spawn == 1)
			return (0);
		if (data->map[y][i] == 'S' && data->map_data.check_south_spawn == 0)
			data->map_data.check_south_spawn = 1;
		if (data->map_data.check_south_spawn == 1)
			return (0);
		if (data->map[y][i] == 'W' && data->map_data.check_west_spawn == 0)
			data->map_data.check_west_spawn = 1;
		if (data->map_data.check_west_spawn == 1)
			return (0);
		if (data->map[y][i] == 'E' && data->map_data.check_east_spawn == 0)
			data->map_data.check_east_spawn = 1;
		if (data->map_data.check_east_spawn == 1)
			return (0);
		i++;
	}
	return (1);
}

int	count_number_of_spawn(t_data *data, int y)
{
	int	i;

	i = 0;
	while (data->map[y][i])
	{
		if (data->map[y][i] == 'N')
			data->north++;
		if (data->map[y][i] == 'S')
			data->south++;
		if (data->map[y][i] == 'W')
			data->west++;
		if (data->map[y][i] == 'E')
			data->east++;
		i++;
	}
	return (0);
}

int	west_and_east_spawn_check(t_data *data)
{
	if (data->map_data.check_west_spawn == 1)
	{
		if (data->north > 0 || data->south > 0 || data->west > 1
			|| data->east > 0)
		{
			printf("Error : Multiple spawn detected\n");
			return (1);
		}
	}
	if (data->map_data.check_east_spawn == 1)
	{
		if (data->north > 0 || data->south > 0 || data->west > 0
			|| data->east > 1)
		{
			printf("Error : Multiple spawn detected\n");
			return (1);
		}
	}
	return (0);
}

int	looking_for_multi_spawn(t_data *data)
{
	if (data->map_data.check_north_spawn == 1)
	{
		if (data->north > 1 || data->south > 0 || data->west > 0
			|| data->east > 0)
		{
			printf("Error : Multiple spawn detected\n");
			return (1);
		}
	}
	if (data->map_data.check_south_spawn == 1)
	{
		if (data->north > 0 || data->south > 1 || data->west > 0
			|| data->east > 0)
		{
			printf("Error : Multiple spawn detected\n");
			return (1);
		}
	}
	if (west_and_east_spawn_check(data) == 1)
		return (1);
	return (0);
}
