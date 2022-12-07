/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:48 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/07 12:24:21 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**free_texture_tab(t_data *data)
{
	if (data->texture.north_path_copy == 1)
		free(data->texture_path[0]);
	if (data->texture.south_path_copy == 1)
		free(data->texture_path[1]);
	if (data->texture.west_path_copy == 1)
		free(data->texture_path[2]);
	if (data->texture.east_path_copy == 1)
		free(data->texture_path[3]);
	free(data->texture_path);
	return (0);
}

char	**free_rgb_tab(t_data *data)
{
	if (data->texture.rgb_f_copy == 1)
		free(data->rgb_values[0]);
	if (data->texture.rgb_c_copy == 1)
		free(data->rgb_values[1]);
	free(data->rgb_values);
	return (0);
}

char	**free_tab(char **tab, int i)
{
	if (i == 0)
	{
		free(tab);
		return (0);
	}
	while (i >= 0)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	free(tab);
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

void	main_data_var_init(t_data *data)
{
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

int	parsing(char **argv, t_data *data)
{
	if (!argv[1])
		return (1);
	if (check_file_format(argv[1], data) == 1)
	{
		printf("Error : bad file format : need .cub\n");
		data->no_free_tab = 1;
		return (1);
	}
	data->texture_path = malloc(sizeof(char *) * 5);
	if (!data->texture_path)
		return (1);
	data->rgb_values = malloc(sizeof(char *) * 3);
	if (!data->rgb_values)
		return (1);
	if (check_file(argv[1], data) == 1)
		return (1);
	if (map_copy_and_parsing(data, argv) == 1)
		return(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_cub	*cub;

	(void)cub;
	main_data_var_init(&data);
	main_texture_var_init(&data);
	if (argc == 2)
	{
		if (parsing(argv, &data) == 0)
		{
//////////////////////////////////////////////////////////////////////////////////////////////
			int a = 0;
			while (data.texture_path[a] != NULL)
			{
				printf("PATH COPY ==> %s\n", data.texture_path[a]);
				a++;
			}
			a = 0;
			while (a < 2)
			{
				printf("COLOR COPY ==> %s\n", data.rgb_values[a]);
				a++;
			}
			printf("\n== Map parsing OK ==\n");
			printf("Map size --> %d\n", data.map_data.map_size);
//////////////////////////////////////////////////////////////////////////////////////////////
			// cub = malloc(sizeof(t_cub));
			// cub->vars.mlx = mlx_init();
			// cub->vars.win = mlx_new_window(cub->vars.mlx,
			// 		1920, 1080, "cub");
			// cub->img = mlx_new_image(cub->vars.mlx, 1920, 1080);
			// cub->addr = mlx_get_data_addr((cub->img),
			// 		&(cub->bits_per_pixel), &(cub->line_length),
			// 		&(cub->endian));
			// mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->img, 0, 0);
			// mlx_loop(cub->vars.mlx);
			free_texture_tab(&data);
			free_rgb_tab(&data);
			free_tab(data.map, data.map_data.map_size);
			return (0);
		}
		if (data.no_free_tab != 1)
		{
			free_texture_tab(&data);
			free_rgb_tab(&data);
			if (data.free_tab_map == 1)
				free_tab(data.map, data.map_data.map_size);
		}
		return (1);
	}
	printf("Error : wrong number of arguments\n");
	return (1);
}
