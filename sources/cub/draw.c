/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/23 10:53:09 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_line_check(t_cub *cub, float ra, float ntan)
{
	if ((ra > cub->p2) && (ra < cub->p3))
		set_ray_v_case_1(cub, ntan);
	if ((ra < cub->p2) || (ra > cub->p3))
		set_ray_v_case_2(cub, ntan);
	if (ra == 0 || ra == PI)
		set_ray_v_case_3(cub);
	while (cub->ray_v.dof < cub->dof_limit)
	{
		cub->ray_v.mx = ((int)(cub->ray_v.rx) >> 5);
		cub->ray_v.my = ((int)(cub->ray_v.ry) >> 5);
		vertical_mx_my_check(cub);
		cub->ray_v.mp = cub->ray_v.my * cub->data.width + cub->ray_v.mx;
		if (cub->ray_h.mp > 0 && (cub->ray_v.mp
				< (cub->data.width * cub->data.map_data.map_size))
			&& cub->data.map[cub->ray_v.my][cub->ray_v.mx] == '1')
			cub->ray_v.dof = cub->dof_limit;
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
		set_ray_h_case_1(cub, atan);
	if (ra < PI)
		set_ray_h_case_2(cub, atan);
	if (ra == 0 || ra == PI)
		set_ray_h_case_3(cub);
	while (cub->ray_h.dof < cub->dof_limit)
	{
		cub->ray_h.mx = ((int)(cub->ray_h.rx) >> 5);
		cub->ray_h.my = ((int)(cub->ray_h.ry) >> 5);
		horizontal_mx_my_check(cub);
		cub->ray_h.mp = cub->ray_h.my * cub->data.width + cub->ray_h.mx;
		if (cub->ray_h.mp > 0 && (cub->ray_h.mp
				< (cub->data.width * cub->data.map_data.map_size))
			&& cub->data.map[cub->ray_h.my][cub->ray_h.mx] == '1')
			cub->ray_h.dof = cub->dof_limit;
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

	r = 0;
	j = 0;
	cub->ra = 0.0;
	cub->ra = set_ra_before_loop(cub->ra, cub->pa);
	while (r < 1919)
	{
		cub->v_check = 0;
		init_ray_var(cub);
		cub->atan = -1 / tanf(cub->ra);
		cub->ntan = -tanf(cub->ra);
		horizontal_line_check(cub, cub->ra, cub->atan);
		vertical_line_check(cub, cub->ra, cub->ntan);
		if (check_ray(cub) == 0)
			print_h_rayon(cub, cub->ray_h.rx, cub->ray_h.ry, cub->ra);
		else
			print_v_rayon(cub, cub->ray_v.rx, cub->ray_v.ry, cub->ra);
		draw_walls(cub, cub->ra, r, j);
		j += 1;
		cub->ra = set_ra_end_of_loop(cub->ra);
		r++;
	}
}

int	ft_draw_hero(t_cub *cub, t_mlx_data *img)
{
	int		i;
	int		player_x;
	int		player_y;
	int		j;

	(void)img;
	player_x = (cub->posx / 32) * cub->data.minimap_coeff;
	player_y = ((cub->posy / 32) * cub->data.minimap_coeff);
	if (player_y > 0)
		player_y -= 2;
	j = 0;
	i = -1;
	if (cub->data.mini_map == 1)
		return (1);
	while (++i <= 5)
	{
		if ( player_x < 1920 && player_x >= 0 && player_y + j < 1080 && player_y + j >= 0)
		{
			my_mlx_pixel_put(img, player_x, player_y + j, 0xffff00);
			my_mlx_pixel_put(img, player_x + 1, player_y + j, 0xffff00);
			my_mlx_pixel_put(img, player_x + 2, player_y + j, 0xffff00);
			my_mlx_pixel_put(img, player_x + 3, player_y + j, 0xffff00);
			my_mlx_pixel_put(img, player_x + 4, player_y + j, 0xffff00);
			my_mlx_pixel_put(img, player_x + 5, player_y + j, 0xffff00);
		}
		j++;
	}
	return (1);
}

int	ft_rz_rotation(float ra, t_cub *cub)
{
	cub->raylx = cub->pdx * cos(ra - cub->pa) + cub->pdy * (-sin(ra - cub->pa));
	cub->rayly = cub->pdx * sin(ra - cub->pa) + cub->pdy * cos(ra - cub->pa);
	return (1);
}
