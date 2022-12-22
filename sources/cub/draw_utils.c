/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:35:57 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 20:28:36 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_ra_end_of_loop(float ra)
{
	ra = ra + ((2 * PI / 6) / 1919);
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	return (ra);
}

float	set_ra_before_loop(float ra, float pa)
{
	ra = pa - (PI / 6);
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	return (ra);
}

void	vertical_mx_my_check(t_cub *cub)
{
	if (cub->ray_v.my < 0)
		cub->ray_v.my = 1;
	if (cub->ray_v.mx < 0)
		cub->ray_v.mx = 1;
	if (cub->ray_v.my >= cub->data.map_data.map_size)
		cub->ray_v.my = cub->data.map_data.map_size - 1;
}

void	horizontal_mx_my_check(t_cub *cub)
{
	if (cub->ray_h.my < 0)
		cub->ray_h.my = 1;
	if (cub->ray_h.mx < 0)
		cub->ray_h.mx = 1;
	if (cub->ray_h.my >= cub->data.map_data.map_size)
		cub->ray_h.my = cub->data.map_data.map_size - 1;
}