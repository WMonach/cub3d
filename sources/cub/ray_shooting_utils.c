/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shooting_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:48:04 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/23 09:20:19 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_value(t_cub *cub, t_img *img, int y, int x)
{
	int	texx;
	int	texy;

	(void)y;
	texx = 0;
	if (cub->v_check == 1)
		texx = ((cub->ray_v.ry / 32) - cub->ray_v.my) * 32;
	else
		texx = ((cub->ray_h.rx / 32) - cub->ray_h.mx) * 32;
	texy = ((x - (540 - cub->lineh / 2)) / cub->lineh) * img->height;
	img->addr = (int *)mlx_get_data_addr(img->data, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img->addr[texy * img->line_length / 4 + texx]);
}

int	check_ray(t_cub *cub)
{
	if (sqrtf((powf(cub->ray_h.rx - cub->posx, 2)
				+ powf(cub->ray_h.ry - cub->posy, 2)))
		>= sqrtf((powf(cub->ray_v.rx - cub->posx, 2)
				+ powf(cub->ray_v.ry - cub->posy, 2))))
		return (1);
	else
		return (0);
	return (0);
}

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length
			+ x * (mlx_data->bits_per_pixel / 8));
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
	cub->atan = 0;
	cub->ntan = 0;
}
