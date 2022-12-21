/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:50:26 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/21 19:22:10 by ebrodeur         ###   ########lyon.fr   */
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
