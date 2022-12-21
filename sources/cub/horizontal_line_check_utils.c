/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_line_check_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:32:34 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 18:34:24 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_h_case_1(t_cub *cub, float atan)
{
	cub->ray_h.ry = (((int)cub->posy >> 5) * 32) - 0.0001;
	cub->ray_h.rx = (cub->posy - cub->ray_h.ry) * atan + cub->posx;
	cub->ray_h.yo = -32;
	cub->ray_h.xo = (-cub->ray_h.yo * atan);
	return ;
}

void	set_ray_h_case_2(t_cub *cub, float atan)
{
	cub->ray_h.ry = (((int)cub->posy >> 5) * 32) + 32;
	cub->ray_h.rx = (cub->posy - cub->ray_h.ry) * atan + cub->posx;
	cub->ray_h.yo = 32;
	cub->ray_h.xo = (-cub->ray_h.yo * atan);
	return ;
}

void	set_ray_h_case_3(t_cub *cub)
{
	cub->ray_h.rx = cub->posx;
	cub->ray_h.ry = cub->posy;
	cub->ray_h.dof = cub->data.width;
	return ;
}
