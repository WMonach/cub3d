/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:48 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/06 17:18:54 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_cub *cub)
{
	free(cub); /*FREE all*/
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_cub *cub)
{
	// mlx_destroy_image(cub->vars.mlx, cub->img);
	// cub->img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	// cub->addr = mlx_get_data_addr(cub->img,
	// 		&cub->bits_per_pixel, &cub->line_length,
	// 		&cub->endian);
	if (keycode == 53)
	{
		free(cub); /*FREE all*/
		exit (0);
	}
	// mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	(void)argc;
	(void)argv;
	cub = malloc(sizeof(t_cub));
	cub->vars.mlx = mlx_init();
	cub->vars.win = mlx_new_window(cub->vars.mlx,
			1920, 1080, "cub");
	cub->data.img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->data.addr = mlx_get_data_addr((cub->data.img),
			&(cub->data.bits_per_pixel), &(cub->data.line_length),
			&(cub->data.endian));
	mlx_key_hook(cub->vars.win, key_hook, cub);
	mlx_hook(cub->vars.win, 02, 1L << 0, key_hook, cub);
	mlx_hook(cub->vars.win, 17, 1L << 0, ft_close, cub);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->data.img, 0, 0);
	mlx_loop(cub->vars.mlx);
	return (0);
}
