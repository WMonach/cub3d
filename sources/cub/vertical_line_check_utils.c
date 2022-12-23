/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line_check_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:27:20 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 19:51:53 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_v_case_1(t_cub *cub, float ntan)
{
	cub->ray_v.rx = (((int)cub->posx >> 5) * 32) - 0.0001;
	cub->ray_v.ry = (cub->posx - cub->ray_v.rx) * ntan + cub->posy;
	cub->ray_v.xo = -32;
	cub->ray_v.yo = (-cub->ray_v.xo * ntan);
	return ;
}

void	set_ray_v_case_2(t_cub *cub, float ntan)
{
	cub->ray_v.rx = (((int)cub->posx >> 5) * 32) + 32;
	cub->ray_v.ry = (cub->posx - cub->ray_v.rx) * ntan + cub->posy;
	cub->ray_v.xo = 32;
	cub->ray_v.yo = (-cub->ray_v.xo * ntan);
	return ;
}

void	set_ray_v_case_3(t_cub *cub)
{
	cub->ray_v.rx = cub->posx;
	cub->ray_v.ry = cub->posy;
	cub->ray_v.dof = cub->data.width;
	return ;
}
