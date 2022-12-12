/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/12 17:36:11 by wmonacho         ###   ########lyon.fr   */
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

int	draw_ray(t_cub *cub)
{
	float	ra;
	float	atan;
	float	ry;
	float	rx;

	ra = cub->pa;
	atan = -1 / tan(ra);
	if (ra > 1)
	{
		ry = cub->posy
		return (1);
	}
	return (1);
}

static void	ft_rounded(float number1, float number2, t_cub	*cub)
{
	float	comma;
	int		temp;
	int		rounded_down;

	comma = 0.5;
	rounded_down = number1;
	temp = comma + number1;
	if (temp > rounded_down)
		cub->bresenx = temp;
	else
		cub->bresenx = rounded_down;
	rounded_down = number2;
	temp = comma + number2;
	if (temp > rounded_down)
		cub->breseny = temp;
	else
		cub->breseny = rounded_down;
}

static float	ft_max(float max1, float max2)
{
	if (max1 > max2)
		return (max1);
	return (max2);
}

int	ft_draw_hero(t_cub *cub, t_mlx_data *img)
{
	int		i;
	float	delta;

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
	cub->max = ft_max(fabsf(cub->posx + (cub->pdx * 5)), fabsf(cub->posy + (cub->pdy * 5)));
	i = 0;
	while (i < 100000)
	{
		cub->bresenx = cub->posx + (cub->pdx * i / cub->max);
		cub->breseny = cub->posy + (cub->pdy * i / cub->max);
		if (cub->bresenx < 1919 && cub->breseny < 1079
			&& cub->bresenx >= 0 && cub->breseny >= 0)
		{
			ft_rounded(cub->bresenx, cub->breseny, cub);
			my_mlx_pixel_put(img, (int)cub->bresenx,
				(int)cub->breseny, 0xff6347);
		}
		delta = DELTA;
		while (delta >= -DELTA)
		{
			ft_rz_rotation(delta, cub);
			cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
			cub->breseny = cub->posy + (cub->rayly * i / cub->max);
			if (cub->bresenx < 1919 && cub->breseny < 1079
				&& cub->bresenx >= 0 && cub->breseny >= 0)
			{
				ft_rounded(cub->bresenx, cub->breseny, cub);
				my_mlx_pixel_put(img, (int)cub->bresenx,
					(int)cub->breseny, 0xff6347);
			}
			delta = delta - (DELTA / 8);
		}
		i++;
	}
	my_mlx_pixel_put(img, (cub->posx + (cub->pdx * 5)), (cub->posy + (cub->pdy * 5)), 0xff6347);
	return (1);
}
