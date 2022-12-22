/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:32:53 by ebrodeur          #+#    #+#             */
/*   Updated: 2022/12/22 20:26:40 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub_var(t_cub *cub, t_data *data)
{
	cub->posx = 0;
	cub->posy = 0;
	cub->hit_wall = 0;
	cub->p2 = PI / 2;
	cub->p3 = 3 * PI / 2;
	cub->pdx = cos(cub->pa * 5);
	cub->pdy = sin(cub->pa * 5) - (PI / 6);
	(cub->data) = *data;
}

void	main_data_var_init(t_data *data, t_cub *cub)
{
	(void)cub;
	data->width = 0;
	data->north = 0;
	data->south = 0;
	data->west = 0;
	data->east = 0;
	data->length = 0;
	data->id_number = 6;
	data->nb_of_lines = 0;
	data->check_id_parsing = 0;
	data->map_data.map_size = 0;
	data->end_line_check = 0;
	data->check_empty_line = 0;
	data->map_data.check_north_spawn = 0;
	data->map_data.check_south_spawn = 0;
	data->map_data.check_west_spawn = 0;
	data->map_data.check_east_spawn = 0;
	return ;
}

int	map_copy_and_parsing(t_data *data, char **argv)
{
	if (map_copy(data, argv[1]) == 1)
	{
		data->free_tab_map = 1;
		return (1);
	}
	if (map_wall_parsing(data) == 1)
	{
		data->free_tab_map = 1;
		return (1);
	}
	return (0);
}

void	main_texture_var_init(t_data *data)
{
	data->texture.rgb_f_copy = 0;
	data->texture.rgb_f_copy = 0;
	data->texture.north_path_copy = 0;
	data->texture.south_path_copy = 0;
	data->texture.west_path_copy = 0;
	data->texture.east_path_copy = 0;
	data->textures_tab_size = 0;
	data->rgb_tab_size = 0;
	data->texture.check_no_texture = 0;
	data->texture.check_so_texture = 0;
	data->texture.check_ea_texture = 0;
	data->texture.check_we_texture = 0;
	data->texture.check_f_texture = 0;
	data->texture.check_c_texture = 0;
	data->texture_id[0] = "NO";
	data->texture_id[1] = "SO";
	data->texture_id[2] = "WE";
	data->texture_id[3] = "EA";
	data->texture_id[4] = "F";
	data->texture_id[5] = "C";
	return ;
}

int	ft_close(t_cub *cub)
{
	free(cub);
	exit(0);
	return (0);
}
