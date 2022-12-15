/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/15 19:21:08 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_line_check(t_cub *cub, float ra, float ntan)
{
	if ((ra > P2) && (ra < P3))
	{
		cub->ray_v.rx = (((int)cub->posx>>5) * 32) - 0.0001;
		cub->ray_v.ry = (cub->posx - cub->ray_v.rx) * ntan + cub->posy;
		cub->ray_v.xo = -32;
		cub->ray_v.yo = (-cub->ray_v.xo * ntan);
	}
	if ((ra < P2) || (ra > P3))
	{
		cub->ray_v.rx = (((int)cub->posx>>5) * 32) + 32;
		cub->ray_v.ry = (cub->posx - cub->ray_v.rx) * ntan + cub->posy;
		cub->ray_v.xo = 32;
		cub->ray_v.yo = (-cub->ray_v.xo * ntan);
	}
	if (ra == 0 || ra == PI)
	{
		cub->ray_v.rx = cub->posx;
		cub->ray_v.ry = cub->posy;
		cub->ray_v.dof = 15;
	}
	while (cub->ray_v.dof < 15)
	{
		cub->ray_v.mx = abs((int)(cub->ray_v.rx)>>5);
		cub->ray_v.my = abs((int)(cub->ray_v.ry)>>5);
		cub->ray_v.mp = cub->ray_v.my * 15 + cub->ray_v.mx;
		if (cub->ray_h.mp > 0 && (cub->ray_v.mp < (15 * 15)) && cub->data.map[cub->ray_v.my][cub->ray_v.mx] == '1')
			cub->ray_v.dof = 15;
		else
		{
			cub->ray_v.rx += cub->ray_v.xo;
			cub->ray_v.ry += cub->ray_v.yo;
			cub->ray_v.dof += 1;
		}
	}
}

void	horizontal_line_check(t_cub *cub, float ra, float atan)
{
	if (ra > PI)
	{
		cub->ray_h.ry = (((int)cub->posy>>5) * 32) - 0.0001;
		cub->ray_h.rx = (cub->posy - cub->ray_h.ry) * atan + cub->posx;
		cub->ray_h.yo = -32;
		cub->ray_h.xo = (-cub->ray_h.yo * atan);
	}
	if (ra < PI)
	{
		cub->ray_h.ry = (((int)cub->posy>>5) * 32) + 32;
		cub->ray_h.rx = (cub->posy - cub->ray_h.ry) * atan + cub->posx;
		cub->ray_h.yo = 32;
		cub->ray_h.xo = (-cub->ray_h.yo * atan);
	}
	if (ra == 0 || ra == PI)
	{
		cub->ray_h.rx = cub->posx;
		cub->ray_h.ry = cub->posy;
		cub->ray_h.dof = 15;
	}
	while (cub->ray_h.dof < 15)
	{
		cub->ray_h.mx = abs((int)(cub->ray_h.rx)>>5);
		cub->ray_h.my = abs((int)(cub->ray_h.ry)>>5);
		cub->ray_h.mp = cub->ray_h.my * 15 + cub->ray_h.mx;
		if (cub->ray_h.mp > 0 && (cub->ray_h.mp < (15 * 15)) && cub->data.map[cub->ray_h.my][cub->ray_h.mx] == '1')
			cub->ray_h.dof = 15;
		else
		{
			cub->ray_h.rx += cub->ray_h.xo;
			cub->ray_h.ry += cub->ray_h.yo;
			cub->ray_h.dof += 1;
		}
	}
}

void	draw_rays(t_cub *cub)
{
	int		r;
	float	j;
	float	ra, atan, ntan;

	r = 0;
	j = 0;
	ra = cub->pa - DR * 30;
	if (ra < 0)
		ra += 2 *PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	while (r < 1919)
	{
		init_ray_var(cub);
		atan = -1 / tan(ra);
		ntan = -tan(ra);
		horizontal_line_check(cub, ra, atan);
		vertical_line_check(cub, ra, ntan);
		if (check_ray(cub) == 0)
		 	print_h_rayon(cub, cub->ray_h.rx, cub->ray_h.ry, ra);
		else
		 	print_v_rayon(cub, cub->ray_v.rx, cub->ray_v.ry, ra);
		draw_walls(cub, ra, r, j);
		j += 1;
		ra += DR / (1919 / 60);
		if (ra < 0)
			ra += 2 *PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}
}

int	ft_draw_hero(t_cub *cub, t_mlx_data *img)
{
	(void)img;
	// int		i;

	// i = -1;
	// while (++i <= 5)
	// {
	// 	my_mlx_pixel_put(img, cub->posx, cub->posy, 0xffff00);
	// 	my_mlx_pixel_put(img, cub->posx + 1, cub->posy, 0xffff00);
	// 	my_mlx_pixel_put(img, cub->posx + 2, cub->posy, 0xffff00);
	// 	my_mlx_pixel_put(img, cub->posx + 3, cub->posy, 0xffff00);
	// 	my_mlx_pixel_put(img, cub->posx + 4, cub->posy, 0xffff00);
	// 	my_mlx_pixel_put(img, cub->posx + 5, cub->posy, 0xffff00);
	// 	cub->posy++;
	// }
	// cub->posy -= 6;
	draw_rays(cub);
	return (1);
}
