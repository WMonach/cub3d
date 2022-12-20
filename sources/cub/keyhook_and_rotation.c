/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_and_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:38:45 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/20 12:34:19 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_forward(t_cub *cub)
{
	if (cub->pdx < 0)
		cub->collision.xo = -10;
	else
		cub->collision.xo = 10;
	if (cub->pdy < 0)
		cub->collision.yo = -10;
	else
		cub->collision.yo = 10;
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_add = (cub->posx + cub->collision.xo) / 32.0;
	cub->collision.yo_add = (cub->posy + cub->collision.yo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos, cub->collision.xo_add) == 0)
		cub->posx += cub->pdx;
	if (check_collision(cub->data.map, cub->collision.yo_add, cub->collision.xm_pos) == 0)
		cub->posy += cub->pdy;
}

void	move_backward(t_cub *cub)
{
	if (cub->pdx < 0)
		cub->collision.xo = -10;
	else
		cub->collision.xo = 10;
	if (cub->pdy < 0)
		cub->collision.yo = -10;
	else
		cub->collision.yo = 10;
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_sub = (cub->posx - cub->collision.xo) / 32.0;
	cub->collision.yo_sub = (cub->posy - cub->collision.yo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos, cub->collision.xo_sub) == 0)
		cub->posx -= cub->pdx;
	if (check_collision(cub->data.map, cub->collision.yo_sub, cub->collision.xm_pos) == 0)
		cub->posy -= cub->pdy;
}

void	move_right(t_cub *cub)
{
	printf("right PDX --> %f\n", cub->pdx);
	if (cub->pdx < 0)
		cub->collision.xo = -10;
	else
		cub->collision.xo = 10;
	printf("right PDY --> %f\n", cub->pdy);
	if (cub->pdy < 0)
		cub->collision.yo = -10;
	else
		cub->collision.yo = 10;
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_right = (cub->posx + cub->collision.yo) / 32.0;
	cub->collision.yo_right = (cub->posy + cub->collision.xo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos, cub->collision.xo_right) == 0)
	{
		printf("checking : [%d][%d] --> %c\n", cub->collision.ym_pos, cub->collision.xo_right, cub->data.map[ cub->collision.ym_pos][cub->collision.xo_right]);
		cub->posx += -cub->pdy;
	}
	if (check_collision(cub->data.map, cub->collision.yo_right, cub->collision.xm_pos) == 0)
	{
		printf("checking : [%d][%d] --> %c\n", cub->collision.yo_right, cub->collision.xm_pos, cub->data.map[cub->collision.yo_right][cub->collision.xm_pos]);
		cub->posy += cub->pdx;
	}
}

void	move_left(t_cub *cub)
{
	if (cub->pdx < 0)
		cub->collision.xo = -10;
	else
		cub->collision.xo = 10;
	if (cub->pdy < 0)
		cub->collision.yo = -10;
	else
		cub->collision.yo = 10;
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_left = (cub->posx - cub->collision.yo) / 32.0;
	cub->collision.yo_left = (cub->posy - cub->collision.xo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos, cub->collision.xo_left) == 0)
		cub->posx += cub->pdy;
	if (check_collision(cub->data.map, cub->collision.yo_left, cub->collision.xm_pos) == 0)
		cub->posy += -cub->pdx;
}

int	ft_keyhook_translation(int keycode, t_cub *cub)
{
	if (keycode == S_KEY)
		move_backward(cub);
	if (keycode == W_KEY)
		move_forward(cub);
	if (keycode == A_KEY)
		move_left(cub);
	if (keycode == D_KEY)
		move_right(cub);
	if (keycode == LEFT)
	{
		cub->pa -= 0.1;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
	}
	if (keycode == RIGHT)
	{
		cub->pa += 0.1;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
		cub->pdx = cos(cub->pa) * 5;
		cub->pdy = sin(cub->pa) * 5;
	}
	return (1);
}
