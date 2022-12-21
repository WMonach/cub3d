/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_and_rotation_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:45:49 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 18:46:19 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_xo_and_yo_for_side_walk(t_cub *cub)
{
	if (cub->pdx > 0 && cub->pdy > 0)
	{
		cub->collision.xo = 10;
		cub->collision.yo = -10;
	}
	if (cub->pdx < 0 && cub->pdy < 0)
	{
		cub->collision.xo = -10;
		cub->collision.yo = 10;
	}
	if (cub->pdx > 0 && cub->pdy < 0)
	{
		cub->collision.xo = 10;
		cub->collision.yo = 10;
	}
	if (cub->pdx < 0 && cub->pdy > 0)
	{
		cub->collision.xo = -10;
		cub->collision.yo = -10;
	}
}

int	check_collision(char **map, int y, int x)
{
	int		i;
	char	*correct_values;

	i = 0;
	correct_values = "0NSWE";
	while (i < 5)
	{
		if (map[y][x] == correct_values[i])
			return (0);
		i++;
	}
	return (1);
}
