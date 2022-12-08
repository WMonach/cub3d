/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/08 14:26:45 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_wall(t_data *data, t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	y = data->y_range;
	(void)data;
	while (y < (data->y_range + 32))
	{
		x = data->x_range;
		while (x < (data->x_range + 32))
		{
			my_mlx_pixel_put(mlx_data, x, y, 0x00FF0000);
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
	while (y < (data->y_range + 32))
	{
		x = data->x_range;
		while (x < (data->x_range + 32))
		{
			my_mlx_pixel_put(mlx_data, x, y, 0x00FFFFFF);
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
	data->y_range = 0;
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

int	ft_draw_hero(t_cub *cub, t_mlx_data *img)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		my_mlx_pixel_put(img, cub->Posx, cub->Posy, 0xf0fff0);
		cub->Posy += 5;
		my_mlx_pixel_put(img, cub->Posx, cub->Posy, 0xf0fff0);
		cub->Posy -= 5;
		cub->Posx++;
	}
	cub->Posx -= 5;
	i = -1;
	while (++i <= 5)
	{
		my_mlx_pixel_put(img, cub->Posx, cub->Posy, 0xf0fff0);
		cub->Posx += 5;
		my_mlx_pixel_put(img, cub->Posx, cub->Posy, 0xf0fff0);
		cub->Posx -= 5;
		cub->Posy++;
	}
	cub->Posy -= 6;
	return (1);
}
