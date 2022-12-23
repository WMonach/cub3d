/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_wall_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:45:56 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 20:09:29 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	print_ceil(t_cub *cub, float j, float i)
{
	while (i < (540 - cub->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_rounded(j, i, cub);
			my_mlx_pixel_put(&cub->mlx_data, (int)j,
				(int)i, cub->data.c_color);
		}
		i++;
	}
	return (i);
}

float	print_wall(t_cub *cub, float j, float i)
{
	while (i < (540 + cub->lineh / 2))
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			if (cub->v_check == 1)
				print_vertical_wall(cub, j, i);
			else
			{
				if (cub->ray_h.ry > cub->posy)
					my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i,
						get_value(cub, &cub->img_s, j, i));
				if (cub->ray_h.ry < cub->posy)
					my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i,
						get_value(cub, &cub->img_n, j, i));
			}
		}
		i++;
	}
	return (i);
}

float	print_floor(t_cub *cub, float j, float i)
{
	while (i < 1080)
	{
		if (j < 1919 && i < 1079 && j >= 0 && i >= 0)
		{
			ft_rounded(j, i, cub);
			my_mlx_pixel_put(&cub->mlx_data, (int)j,
				(int)i, cub->data.f_color);
		}
		i++;
	}
	return (i);
}

void	print_3d_wall(t_cub *cub, float ra, float j)
{
	float	i;

	(void)ra;
	i = 0;
	i = print_ceil(cub, j, i);
	i = print_wall(cub, j, i);
	i = print_floor(cub, j, i);
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
	cub->lineo = (960 - cub->lineh / 2);
	print_3d_wall(cub, ra, j);
	return ;
}
