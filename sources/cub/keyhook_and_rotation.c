/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_and_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:38:45 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 11:50:03 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (check_collision(cub->data.map, cub->collision.ym_pos,
			cub->collision.xo_add) == 0)
		cub->posx += cub->pdx;
	if (check_collision(cub->data.map, cub->collision.yo_add,
			cub->collision.xm_pos) == 0)
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
	if (check_collision(cub->data.map, cub->collision.ym_pos,
			cub->collision.xo_sub) == 0)
		cub->posx -= cub->pdx;
	if (check_collision(cub->data.map, cub->collision.yo_sub,
			cub->collision.xm_pos) == 0)
		cub->posy -= cub->pdy;
}

void	move_right(t_cub *cub)
{
	set_xo_and_yo_for_side_walk(cub);
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_right = (cub->posx + cub->collision.yo) / 32.0;
	cub->collision.yo_right = (cub->posy + cub->collision.xo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos,
			cub->collision.xo_right) == 0)
		cub->posx += -cub->pdy;
	if (check_collision(cub->data.map, cub->collision.yo_right,
			cub->collision.xm_pos) == 0)
		cub->posy += cub->pdx;
}

void	move_left(t_cub *cub)
{
	set_xo_and_yo_for_side_walk(cub);
	cub->collision.ym_pos = cub->posy / 32.0;
	cub->collision.xm_pos = cub->posx / 32.0;
	cub->collision.xo_left = (cub->posx - cub->collision.yo) / 32.0;
	cub->collision.yo_left = (cub->posy - cub->collision.xo) / 32.0;
	if (check_collision(cub->data.map, cub->collision.ym_pos,
			cub->collision.xo_left) == 0)
		cub->posx += cub->pdy;
	if (check_collision(cub->data.map, cub->collision.yo_left,
			cub->collision.xm_pos) == 0)
		cub->posy += -cub->pdx;
}

int	key_hook_down(int keycode, t_cub *cub)
{
	if (keycode == 53)
	{
		free(cub);
		exit (0);
	}
	if (keycode == S_KEY)
		cub->keys.s_key = 1;
	if (keycode == W_KEY)
		cub->keys.w_key = 1;
	if (keycode == A_KEY)
		cub->keys.a_key = 1;
	if (keycode == D_KEY)
		cub->keys.d_key = 1;
	if (keycode == LEFT)
		cub->keys.left_key = 1;
	if (keycode == RIGHT)
		cub->keys.right_key = 1;
	return (0);
}
