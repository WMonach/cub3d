/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/14 14:26:23 by ebrodeur         ###   ########lyon.fr   */
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

float	ft_max(float max1, float max2)
{
	if (max1 > max2)
		return (max1);
	return (max2);
}

void	print_h_rayon(t_cub *cub, float rx, float ry)
{
	
	float	i;
	float	c;
	
	i = 0;
	c = 0;
	c = sqrt((powf(rx, 2) + powf(ry, 2))) * 32;
	cub->max = ft_max(fabsf(cub->posx + (cub->pdx * 5)), fabsf(cub->posy + (cub->pdy * 5)));
	while (i < 100000)
	{
		cub->bresenx = cub->posx + (cub->pdx * i / cub->max);
		cub->breseny = cub->posy + (cub->pdy * i / cub->max);
		if (cub->bresenx > rx)
			break ;
		if (cub->bresenx < 1919 && cub->breseny < 1079
			&& cub->bresenx >= 0 && cub->breseny >= 0)
		{
			ft_rounded(cub->bresenx, cub->breseny, cub);
			my_mlx_pixel_put(&cub->mlx_data, (int)cub->bresenx,
				(int)cub->breseny, 0xff6347);
		}
		i++;
	}
}

void	print_v_rayon(t_cub *cub, float rx, float ry)
{
	int		i;
	
	(void)rx;
	(void)ry;
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
			my_mlx_pixel_put(&cub->mlx_data, (int)cub->bresenx,
				(int)cub->breseny, 0xfff00);
		}
		i++;
	}
}

void	vertical_line_check(t_cub *cub, int mx, int my, int mp, int dof, float ra, float rx, float ry, float xo, float yo, float ntan)
{
		if ((ra > P2) && (ra < P3))
		{
			rx = (((int)cub->posx>>5) * 32) - 0.0001;
			ry = (cub->posx - rx) * ntan + cub->posy;
			xo = -32;
			yo = (-yo * ntan);
		}
		if ((ra < P2) || (ra > P3))
		{
			rx = (((int)cub->posx>>5) * 32) + 32;
			printf("RX --> %f\n", rx);
			ry = (cub->posx - rx) * ntan + cub->posy;
			printf("RY --> %f\n", ry);
			xo = 32;
			yo = (-yo * ntan);
		}
		if (ra == 0 || ra == PI)
		{
			rx = cub->posx;
			ry = cub->posy;
			dof = 15;
		}
		//printf("RX --> %f\nRY --> %f\n\n", rx, ry);
		while (dof < 15)
		{
			mx = abs((int)(rx)>>5);
			my = abs((int)(ry)>>5);
			mp = my * 15 + mx;
			printf("\nMX --> %d\nMY --> %d\nMP --> %d\n", mx, my, mp);
			if ((mp < (15 * 15)) && cub->data.map[my][mx] == '1')
			{
				printf("\n!!! HIT V WALL !!!\n");
				printf("\n!!! [%d][%d] !!!\n", my, mx);
				dof = 15;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		print_v_rayon(cub, rx, ry);
}


void	horizontal_line_check(t_cub *cub, int mx, int my, int mp, int dof, float ra, float rx, float ry, float xo, float yo, float atan)
{
		if (ra > PI)
		{
			ry = (((int)cub->posy>>5) * 32) - 0.0001;
			rx = (cub->posy - ry) * atan + cub->posx;
			yo = -32;
			xo = (-yo * atan);
		}
		if (ra < PI)
		{
			ry = (((int)cub->posy>>5) * 32) + 32;
			printf("RY --> %f\n", ry);
			rx = (cub->posy - ry) * atan + cub->posx;
			printf("RX --> %f\n", rx);
			yo = 32;
			xo = (-yo * atan);
		}
		if (ra == 0 || ra == PI)
		{
			rx = cub->posx;
			ry = cub->posy;
			dof = 15;
		}
		//printf("RX --> %f\nRY --> %f\n\n", rx, ry);
		while (dof < 15)
		{
			mx = abs((int)(rx)>>5);
			my = abs((int)(ry)>>5);
			mp = my * 15 + mx;
			printf("\nMX --> %d\nMY --> %d\nMP --> %d\n", mx, my, mp);
			if ((mp < (15 * 15)) && cub->data.map[my][mx] == '1')
			{
				printf("\n!!! HIT H WALL !!!\n");
				printf("\n!!! [%d][%d] !!!\n", my, mx);
				dof = 15;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		print_h_rayon(cub, rx, ry);
}

void	draw_rays(t_cub *cub)
{
	int		r, mx, my, mp, dof;
	float	ra, rx, ry, xo, yo, atan, ntan;

	r = 0;
	mx = 0;
	my = 0;
	mp = 0;
	rx = 0;
	ry = 0;
	xo = 0;
	yo = 0;
	ra = cub->pa;
	atan = -1/tan(ra);
	ntan = -tan(ra);
	printf("\n===========\n");
	while (r < 1)
	{
		dof = 0;
		horizontal_line_check(cub, mx, my, mp, dof, ra, rx, ry, xo, yo, atan);
		//vertical_line_check(cub, mx, my, mp, dof, ra, rx, ry, xo, yo, ntan);
		r++;
	}
	printf("\n===========\n");
}

int	ft_draw_hero(t_cub *cub, t_mlx_data *img)
{
	int		i;

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
	draw_rays(cub);
	return (1);
}





	//cub->max = ft_max(fabsf(cub->posx + (cub->pdx * 5)), fabsf(cub->posy + (cub->pdy * 5)));
	// i = 0;
	// while (i < 100000)
	// {
	// 	cub->bresenx = cub->posx + (cub->pdx * i / cub->max);
	// 	cub->breseny = cub->posy + (cub->pdy * i / cub->max);
	// 	if (cub->bresenx < 1919 && cub->breseny < 1079
	// 		&& cub->bresenx >= 0 && cub->breseny >= 0)
	// 	{
	// 		ft_rounded(cub->bresenx, cub->breseny, cub);
	// 		my_mlx_pixel_put(img, (int)cub->bresenx,
	// 			(int)cub->breseny, 0xff6347);
	// 	}
	// 	delta = DELTA;
	// 	while (delta >= -DELTA)
	// 	{
	// 		ft_rz_rotation(delta, cub);
	// 		cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
	// 		cub->breseny = cub->posy + (cub->rayly * i / cub->max);
	// 		if (cub->bresenx < 1919 && cub->breseny < 1079
	// 			&& cub->bresenx >= 0 && cub->breseny >= 0)
	// 		{
	// 			ft_rounded(cub->bresenx, cub->breseny, cub);
	// 			my_mlx_pixel_put(img, (int)cub->bresenx,
	// 				(int)cub->breseny, 0xff6347);
	// 		}
	// 		delta = delta - (DELTA / 8);
	// 	}
	// 	i++;
	//}
	//my_mlx_pixel_put(img, (cub->posx + (cub->pdx * 5)), (cub->posy + (cub->pdy * 5)), 0xff6347);