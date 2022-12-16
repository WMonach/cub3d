/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:52 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/16 10:14:16 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_wall(t_data *data, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	y = data->y_range;
	(void)data;
	while (y < (data->y_range + 31))
	{
		x = data->x_range;
		while (x < (data->x_range + 31))
		{
			my_mlx_pixel_put(mlx_data, x, y, 0x00663300);
			x++;
		}
		y++;
	}
	return ;
}

void	print_floor(t_data *data, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	y = data->y_range;
	(void)data;
	while (y < (data->y_range + 31))
	{
		x = data->x_range;
		while (x < (data->x_range + 31))
		{
			my_mlx_pixel_put(mlx_data, x, y, 0x00999999);
			x++;
		}
		y++;
	}
	return ;
}

int	map_display(t_cub *cub, t_data *data, t_mlx_data *img)
{
	int	i;
	size_t	j;
	size_t	line_size;

	i = 0;
	j = 0;
	line_size = 0;
	(void)cub;
	data->y_range = 300;
	while (data->map[i])
	{
		j = 0;
		data->x_range = 0;
		line_size = ft_strlen(data->map[i]);
		while (j < line_size)
		{
			if (data->map[i][j] == '1')
				print_wall(data, img);
			if (data->map[i][j] == '0')
				print_floor(data, img);
			data->x_range += 32;
			j++;
		}
		data->y_range += 32;
		i++;
	}
	return (0);
}
