/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:52 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/23 11:25:13 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_spawn_in_minimap(t_data *data, t_mlx_data *mlx_data, int i, int j)
{
	int	x;
	int	y;

	if (data->mini_map == 1)
		return ;
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
	{
		y = data->y_range;
		while (y < (data->y_range + data->minimap_coeff - 1))
		{
			x = data->x_range;
			while (x < (data->x_range + data->minimap_coeff - 1))
			{
				my_mlx_pixel_put(mlx_data, x, y, 0xe81010);
				x++;
			}
			y++;
		}
		return ;
	}
	return ;
}

void	print_wall_2d(t_data *data, t_mlx_data *mlx_data)
{
	float	x;
	float	y;

	if (data->mini_map == 1)
		return ;
	y = data->y_range;
	while (y < (data->y_range + data->minimap_coeff - 1))
	{
		x = data->x_range;
		while (x < (data->x_range + data->minimap_coeff - 1))
		{
			if (x < 1920 && x >= 0 && y < 1080 && y >= 0)
				my_mlx_pixel_put(mlx_data, x, y, 0x00663300);
			x++;
		}
		y++;
	}
	return ;
}

void	print_floor_2d(t_data *data, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	if (data->mini_map == 1)
		return ;
	y = data->y_range;
	while (y < (data->y_range + data->minimap_coeff - 1))
	{
		x = data->x_range;
		while (x < (data->x_range + data->minimap_coeff - 1))
		{
			if (x < 1920 && x >= 0 && y < 1080 && y >= 0)
				my_mlx_pixel_put(mlx_data, x, y, 0x00999999);
			x++;
		}
		y++;
	}
	return ;
}

void	calculation_of_the_coeff_minimap(t_data *data)
{
	if (data->map_data.map_size >= data->width)
	{
		data->minimap_coeff = 225 / (data->width);
		if (data->map_data.map_size / data->width > 5)
			data->mini_map = 1;
	}
	else
	{
		data->minimap_coeff = 225 / (data->map_data.map_size);
		if (data->width / data->map_data.map_size > 5)
			data->mini_map = 1;
	}
}

void	map_display(t_data *data, t_mlx_data *img)
{
	int		i;
	long	j;
	long	line_size;

	i = -1;
	line_size = 0;
	data->y_range = 0;
	calculation_of_the_coeff_minimap(data);
	while (data->map[++i])
	{
		j = -1;
		data->x_range = 0;
		line_size = ft_strlen(data->map[i]);
		while (++j < line_size)
		{
			if (data->map[i][j] == '1')
				print_wall_2d(data, img);
			if (data->map[i][j] == '0')
				print_floor_2d(data, img);
			print_spawn_in_minimap(data, img, i, j);
			data->x_range += data->minimap_coeff;
		}
		data->y_range += data->minimap_coeff;
	}
}
