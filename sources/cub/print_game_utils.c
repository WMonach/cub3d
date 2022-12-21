/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:26:14 by will              #+#    #+#             */
/*   Updated: 2022/12/22 00:27:15 by will             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	(void)ra;
	i = 0;
	c = 0;
	length = 0;
	c = sqrtf((powf(rx - cub->posx, 2) + powf(ry - cub->posy, 2)));
	cub->dist = c;
	cub->max = ft_max(fabsf(rx - cub->posx), fabsf(ry - cub->posy));
	cub->h_check = 1;
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
}
