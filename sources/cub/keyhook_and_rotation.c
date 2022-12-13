/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_and_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:38:45 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/13 10:49:50 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rz_rotation(float delta, t_cub *cub)
{
	cub->raylx = cub->pdx * cos(delta) + cub->pdy * (-sin(delta));
	cub->rayly = cub->pdx * sin(delta) + cub->pdy * cos(delta);
	return (1);
}

int	ft_rx_rotation(float delta, t_cub *cub)
{
	cub->raylx = cub->pdx;
	cub->rayly = cub->pdy * cos(delta);
	return (1);
}

int	ft_ry_rotation(float delta, t_cub *cub)
{
	cub->raylx = cub->pdx * cos(delta);
	cub->rayly = cub->pdy;
	return (1);
}

int	ft_keyhook_translation(int keycode, t_cub *cub)
{
	if (keycode == S_KEY || keycode == DOWN)
	{
		cub->posx -= cub->pdx;
		cub->posy -= cub->pdy;

	}
	if (keycode == W_KEY || keycode == UP)
	{
		cub->posx += cub->pdx;
		cub->posy += cub->pdy;
	}
	if (keycode == A_KEY || keycode == LEFT)
	{
		cub->pa -= 0.1;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
		ft_rz_rotation(DELTA, cub);
	}
	if (keycode == D_KEY || keycode == RIGHT)
	{
		cub->pa += 0.1;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
		ft_rz_rotation(DELTA, cub);
	}
	return (1);
}
