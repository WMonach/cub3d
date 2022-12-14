/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/14 13:11:29 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_rounded(float number1, float number2, t_cub	*cub)
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
