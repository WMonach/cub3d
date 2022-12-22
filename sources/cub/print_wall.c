/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:40:20 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 08:42:58 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vertical_wall(t_cub *cub, float j, float i)
{
	if (cub->ray_v.rx > cub->posx)
		my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i,
			get_value(cub, &cub->img_e, j, i));
	if (cub->ray_v.rx < cub->posx)
		my_mlx_pixel_put(&cub->mlx_data, (int)j, (int)i,
			get_value(cub, &cub->img_w, j, i));
}
