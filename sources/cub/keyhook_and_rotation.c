/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_and_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:38:45 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/16 10:56:34 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rz_rotation(float ra, t_cub *cub)
{
	cub->raylx = cub->pdx * cos(ra - cub->pa) + cub->pdy * (-sin(ra - cub->pa));
	cub->rayly = cub->pdx * sin(ra - cub->pa) + cub->pdy * cos(ra - cub->pa);
	return (1);
}

int	ft_keyhook_translation(int keycode, t_cub *cub)
{
	if ((keycode == S_KEY) && cub->hit_wall == 0)//calculer la distance arriere
	{
		cub->posx -= cub->pdx;
		cub->posy -= cub->pdy;
	}
	if ((keycode == W_KEY) && cub->hit_wall == 0)
	{
		cub->posx += cub->pdx;
		cub->posy += cub->pdy;
	}
	if (keycode == LEFT)
	{
		cub->pa -= 0.1;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
		//ft_rz_rotation(cub->pa, cub);
	}
	if (keycode == RIGHT)
	{
		cub->pa += 0.1;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
		//ft_rz_rotation(cub->pa, cub);
	}
	return (1);
}
