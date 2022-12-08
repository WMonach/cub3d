/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/08 17:00:47 by wmonacho         ###   ########lyon.fr   */
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
	while (y < (data->y_range + 32))
	{
		x = data->x_range;
		while (x < (data->x_range + 32))
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
		my_mlx_pixel_put(img, cub->posx, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx, cub->posy + 1, 0xffff00);
		my_mlx_pixel_put(img, cub->posx, cub->posy + 2, 0xffff00);
		my_mlx_pixel_put(img, cub->posx, cub->posy + 3, 0xffff00);
		my_mlx_pixel_put(img, cub->posx, cub->posy + 4, 0xffff00);
		my_mlx_pixel_put(img, cub->posx, cub->posy + 5, 0xffff00);
		cub->posx++;
	}
	cub->posx -= 5;
	i = -1;
	while (++i <= 5)
	{
		my_mlx_pixel_put(img, cub->posx, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx + 1, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx + 2, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx + 3, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx + 4, cub->posy, 0xffff00);
		my_mlx_pixel_put(img, cub->posx + 5, cub->posy, 0xffff00);
		cub->posy++;
	}
	cub->posy -= 6;
	return (1);
}
