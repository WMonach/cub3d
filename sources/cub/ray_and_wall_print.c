/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_wall_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:45:56 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/19 15:06:47 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_h_3d_wall(t_cub *cub, float ra, float rx, float ry)
{
	float	i;

	(void)ra;
	(void)ry;
	i = 300;
	while (i < cub->lineh)
	{
		my_mlx_pixel_put(&cub->mlx_data, rx, i, 0xff6347);
		i++;
	}
}

void	print_v_3d_wall(t_cub *cub, float ra, float j)
{
	float	i;
	float	ty;
	float	ty_step;

	ty = 0;
	ty_step = 32.0 / cub->lineh;
	(void)ra;
	i = 0;
	while (i < (540 - cub->lineh / 2))//PLAFOND
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_rounded(j, i, cub);
			my_mlx_pixel_put(&cub->mlx_data, (int)j,
				(int)i, 0x87cefa);
		}
		i++;
	}
	while (i < (540 + cub->lineh / 2))//MUR - TEXTURE
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_rounded(j, i, cub);
			if (cub->v_check == 1)
				my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i, 0xeee685);
			else
				my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i,  0x8b864e);
		}
		ty += ty_step;
		i++;
	}
	while (i < 1080)//SOL
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_rounded(j, i, cub);
			my_mlx_pixel_put(&cub->mlx_data, (int)j,
				(int)i,  0x6c7b8b);
		}
		i++;
	}
}

void	draw_walls(t_cub *cub, float ra, int r, float j)
{
	float	ca;

	(void)r;
	ca = cub->pa - ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	cub->dist = cub->dist * cos(ca);
	cub->lineh = ((25 * 1920) / cub->dist);
	if (cub->lineh > 1920)
		cub->lineh = 1920;
	cub->lineo = (1080 - cub->lineh / 2);
	print_v_3d_wall(cub, ra, j);
	return ;
}


void	print_h_rayon(t_cub *cub, float rx, float ry, float ra)
{
	float	i;
	float	c;
	float	length;

	(void)ra;
	i = 0;
	c = 0;
	length = 0;
	c = sqrtf((powf(rx - cub->posx, 2) + powf(ry - cub->posy, 2)));
	cub->dist = c;
	cub->max = ft_max(fabsf(rx - cub->posx), fabsf(ry - cub->posy));
	cub->h_check = 1;
	// while (length <= c && i < 100000)
	// {
	// 	ft_rz_rotation(ra, cub);
	// 	cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
	// 	cub->breseny = cub->posy + (cub->rayly * i / cub->max);
	// 	length = sqrtf((powf(cub->bresenx - cub->posx, 2) + powf(cub->breseny - cub->posy, 2)));
	// 	if (cub->bresenx < 1919 && cub->breseny < 1079
	// 		&& cub->bresenx >= 0 && cub->breseny >= 0)
	// 	{
	// 		ft_rounded(cub->bresenx, cub->breseny, cub);
	// 		my_mlx_pixel_put(&cub->mlx_data, (int)cub->bresenx,
	// 			(int)cub->breseny, 0xff6347);
	// 	}
	// 	i++;
	// }
}

void	print_v_rayon(t_cub *cub, float rx, float ry, float ra)
{
	float	i;
	float	c;
	float	length;

	(void)ra;
	i = 0;
	c = 0;
	length = 0;
	c = sqrtf((powf(rx - cub->posx, 2) + powf(ry - cub->posy, 2)));
	cub->dist = c;
	cub->max = ft_max(fabsf(rx - cub->posx), fabsf(ry - cub->posy));
	cub->v_check = 1;
	// while (length <= c && i < 100000)
	// {
	// 	ft_rz_rotation(ra, cub);
	// 	cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
	// 	cub->breseny = cub->posy + (cub->rayly * i / cub->max);
	// 	length = sqrtf((powf(cub->bresenx - cub->posx, 2) + powf(cub->breseny - cub->posy, 2)));
	// 	if (cub->bresenx < 1919 && cub->breseny < 1079
	// 		&& cub->bresenx >= 0 && cub->breseny >= 0)
	// 	{
	// 		ft_rounded(cub->bresenx, cub->breseny, cub);
	// 		my_mlx_pixel_put(&cub->mlx_data, (int)cub->bresenx,
	// 			(int)cub->breseny, 0xff6347);
	// 	}
	// 	i++;
	// }
}
