/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/15 13:46:14 by ebrodeur         ###   ########lyon.fr   */
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

void	print_h_rayon(t_cub *cub, float rx, float ry, float ra)
{
	float	i;
	float	c;
	float	length;

	i = 0;
	c = 0;
	length = 0;
	c = sqrtf((powf(rx - cub->posx, 2) + powf(ry - cub->posy, 2)));
	cub->max = ft_max(fabsf(rx - cub->posx), fabsf(ry - cub->posy));
	while (length <= c && i < 100000)
	{
		ft_rz_rotation(ra, cub);
		cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
		cub->breseny = cub->posy + (cub->rayly * i / cub->max);
		length = sqrtf((powf(cub->bresenx - cub->posx, 2) + powf(cub->breseny - cub->posy, 2)));
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

void	print_v_rayon(t_cub *cub, float rx, float ry, float ra)
{
	float	i;
	float	c;
	float	length;

	i = 0;
	c = 0;
	length = 0;
	c = sqrtf((powf(rx - cub->posx, 2) + powf(ry - cub->posy, 2)));
	cub->max = ft_max(fabsf(rx - cub->posx), fabsf(ry - cub->posy));
	while (length <= c && i < 100000)
	{
		ft_rz_rotation(ra, cub);
		cub->bresenx = cub->posx + (cub->raylx * i / cub->max);
		cub->breseny = cub->posy + (cub->rayly * i / cub->max);
		length = sqrtf((powf(cub->bresenx - cub->posx, 2) + powf(cub->breseny - cub->posy, 2)));
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

void	init_ray_var(t_cub *cub)
{
	cub->ray_v.mx = 0;
	cub->ray_v.my = 0;
	cub->ray_v.mp = 0;
	cub->ray_v.rx = 0;
	cub->ray_v.ry = 0;
	cub->ray_v.xo = 0;
	cub->ray_v.yo = 0;
	cub->ray_v.dof = 0;
	cub->ray_h.mx = 0;
	cub->ray_h.my = 0;
	cub->ray_h.mp = 0;
	cub->ray_h.rx = 0;
	cub->ray_h.ry = 0;
	cub->ray_h.xo = 0;
	cub->ray_h.yo = 0;
	cub->ray_h.dof = 0;
}

int	check_ray(t_cub *cub)
{
	if (sqrtf((powf(cub->ray_h.rx - cub->posx, 2) + powf(cub->ray_h.ry - cub->posy, 2))) >= sqrtf((powf(cub->ray_v.rx - cub->posx, 2) + powf(cub->ray_v.ry - cub->posy, 2))))
		return (1);
	else
		return (0);
	return (0);
}

void	draw_rays(t_cub *cub)
{
	int		r;
	float	ra, atan, ntan;

	r = 0;
	ra = cub->pa - DR * 30;
	if (ra < 0)
		ra += 2 *PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	while (r < 60)
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
		ra += DR;
		if (ra < 0)
			ra += 2 *PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}
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
