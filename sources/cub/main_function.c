/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:50:26 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 12:43:43 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_struct(t_cub *cub, t_data *data)
{
	cub->img_n.data = mlx_xpm_file_to_image(cub->vars.mlx,
			data->texture_path[0], &cub->img_n.width, &cub->img_n.height);
	cub->img_s.data = mlx_xpm_file_to_image(cub->vars.mlx,
			data->texture_path[1], &cub->img_s.width, &cub->img_s.height);
	cub->img_w.data = mlx_xpm_file_to_image(cub->vars.mlx,
			data->texture_path[2], &cub->img_w.width, &cub->img_w.height);
	cub->img_e.data = mlx_xpm_file_to_image(cub->vars.mlx,
			data->texture_path[3], &cub->img_e.width, &cub->img_e.height);
}

void	free_if_parsing_failed(t_data *data)
{
	free_texture_tab(data);
	free_rgb_tab(data);
	if (data->free_tab_map == 1)
		free_tab(data->map, data->map_data.map_size);
	return ;
}

void	free_parsing_data(t_data *data)
{
	free_texture_tab(data);
	free_rgb_tab(data);
	free_tab(data->map, data->map_data.map_size);
	return ;
}

int	key_hook_up(int keycode, t_cub *cub)
{
	if (keycode == S_KEY)
		cub->keys.s_key = 0;
	if (keycode == W_KEY)
		cub->keys.w_key = 0;
	if (keycode == A_KEY)
		cub->keys.a_key = 0;
	if (keycode == D_KEY)
		cub->keys.d_key = 0;
	if (keycode == LEFT)
		cub->keys.left_key = 0;
	if (keycode == RIGHT)
		cub->keys.right_key = 0;
	return (0);
}

void	moves(t_cub *cub)
{	
	if (cub->keys.s_key == 1)
		move_backward(cub);
	if (cub->keys.w_key == 1)
		move_forward(cub);
	if (cub->keys.a_key == 1)
		move_left(cub);
	if (cub->keys.d_key == 1)
		move_right(cub);
	if (cub->keys.left_key == 1)
	{
		cub->pa -= 0.04;
		if (cub->pa < 0)
			cub->pa += 2 * PI;
		cub->pdx = cos(cub->pa) * 4;
		cub->pdy = sin(cub->pa) * 4;
	}
	if (cub->keys.right_key == 1)
	{
		cub->pa += 0.04;
		if (cub->pa > 2 * PI)
			cub->pa -= 2 * PI;
		cub->pdx = cos(cub->pa) * 4;
		cub->pdy = sin(cub->pa) * 4;
	}
	return ;
}
