/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:48 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/15 18:42:09 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_debug(t_data *data)
{
	int a = 0;
	while (data->texture_path[a] != NULL)
	{
		printf("PATH COPY ==> %s\n", data->texture_path[a]);
		a++;
	}
	a = 0;
	while (a < 2)
	{
		printf("COLOR COPY ==> %s\n", data->rgb_values[a]);
		a++;
	}
	a = 0;
	printf("\n");
	while (data->map[a] != NULL)
	{
		printf("%s\n", data->map[a]);
		a++;
	}
	printf("\n== Map parsing OK ==\n");
	printf("Map size --> %d\n", data->map_data.map_size);
	printf("Player starting pos : X-Y [%d] [%d]\n", data->map_data.player_x, data->map_data.player_y);
	return ;
}

int	key_hook(int keycode, t_cub *cub)
{
	mlx_destroy_image(cub->vars.mlx, cub->mlx_data.img);
	cub->mlx_data.img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->mlx_data.addr = mlx_get_data_addr(cub->mlx_data.img,
			&cub->mlx_data.bits_per_pixel, &cub->mlx_data.line_length,
			&cub->mlx_data.endian);
	if (keycode == 53)
	{
		free(cub); /*FREE all*/
		exit (0);
	}
	ft_keyhook_translation(keycode, cub);
	cub->data.y_range = 0;
	cub->data.x_range = 0;
	//map_display(cub, &cub->data, &cub->mlx_data);
	//ft_draw_hero(cub, &cub->mlx_data);
	draw_rays(cub);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->mlx_data.img, 0, 0);
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
		return(1);
	return (0);
}

void	raycaster(t_cub *cub, t_data *data)
{
	(void)data;
	cub->posx = (data->map_data.player_x * 32) + 30;
	cub->posy = (data->map_data.player_y * 32) + 30;
	cub->vars.mlx = mlx_init();
	cub->vars.win = mlx_new_window(cub->vars.mlx,
			1920, 1080, "cub3d");
	cub->mlx_data.img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->mlx_data.addr = mlx_get_data_addr((cub->mlx_data.img),
			&(cub->mlx_data.bits_per_pixel), &(cub->mlx_data.line_length),
			&(cub->mlx_data.endian));
	(cub->data) = *data;
	mlx_key_hook(cub->vars.win, key_hook, cub);
	mlx_hook(cub->vars.win, 17, 1L << 0, ft_close, cub);
	mlx_hook(cub->vars.win, 02, 1L << 0, key_hook, cub);
//	map_display(cub, data, &cub->mlx_data);
//	ft_draw_hero(cub, &cub->mlx_data);
	draw_rays(cub);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->mlx_data.img, 0, 0);
	mlx_loop(cub->vars.mlx);
	return ;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (cub == NULL)
		return (1);
	cub->pa = 0;
	main_data_var_init(&data, cub);
	main_texture_var_init(&data);
	if (argc == 2)
	{
		if (parsing(argv, &data) == 0)
		{
			parsing_debug(&data);
			raycaster(cub, &data);
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
