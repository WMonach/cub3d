/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:48 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/22 11:49:53 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(t_cub *cub)
{
	mlx_destroy_image(cub->vars.mlx, cub->mlx_data.img);
	cub->mlx_data.img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->mlx_data.addr = mlx_get_data_addr(cub->mlx_data.img,
			&cub->mlx_data.bits_per_pixel, &cub->mlx_data.line_length,
			&cub->mlx_data.endian);
	moves(cub);
	cub->data.y_range = 0;
	cub->data.x_range = 0;
	draw_rays(cub);
	map_display(&cub->data, &cub->mlx_data);
	ft_draw_hero(cub, &cub->mlx_data);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win,
		cub->mlx_data.img, 0, 0);
	return (1);
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
		return (1);
	return (0);
}

void	raycaster(t_cub *cub, t_data *data)
{
	cub->posx = (data->map_data.player_x * 32) + 16;
	cub->posy = (data->map_data.player_y * 32) + 16;
	cub->vars.mlx = mlx_init();
	cub->vars.win = mlx_new_window(cub->vars.mlx,
			1920, 1080, "cub3d");
	cub->mlx_data.img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->mlx_data.addr = mlx_get_data_addr((cub->mlx_data.img),
			&(cub->mlx_data.bits_per_pixel), &(cub->mlx_data.line_length),
			&(cub->mlx_data.endian));
	(cub->data) = *data;
	set_texture_struct(cub, data);
	mlx_hook(cub->vars.win, 17, 1L << 0, ft_close, cub);
	mlx_hook(cub->vars.win, 02, 1L << 0, key_hook_down, cub);
	mlx_hook(cub->vars.win, 03, 1L << 1, key_hook_up, cub);
	draw_rays(cub);
	map_display(data, &cub->mlx_data);
	ft_draw_hero(cub, &cub->mlx_data);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win,
		cub->mlx_data.img, 0, 0);
	mlx_loop_hook(cub->vars.mlx, key_hook, cub);
	mlx_loop(cub->vars.mlx);
	return ;
}

float	player_starting_angle(t_data *data)
{
	if (data->map_data.check_north_spawn == 1)
		return (-PI / 2);
	if (data->map_data.check_south_spawn == 1)
		return (-3 * PI / 2);
	if (data->map_data.check_west_spawn == 1)
		return (PI);
	if (data->map_data.check_east_spawn == 1)
		return (0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (cub == NULL)
		return (1);
	main_data_var_init(&data, cub);
	main_texture_var_init(&data);
	if (argc == 2)
	{
		if (parsing(argv, &data) == 0)
		{
			cub->pa = player_starting_angle(&data);
			init_cub_var(cub, &data);
			raycaster(cub, &data);
			free_parsing_data(&data);
			return (0);
		}
		if (data.no_free_tab != 1)
			free_if_parsing_failed(&data);
	}
	free(cub);
	if (argc != 2)
		printf("Error : wrong number of arguments\n");
	return (1);
}
