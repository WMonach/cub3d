/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:48 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/06 14:38:05 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	(void)argc;
	(void)argv;
	cub = malloc(sizeof(t_cub));
	cub->vars.mlx = mlx_init();
	cub->vars.win = mlx_new_window(cub->vars.mlx,
			1920, 1080, "cub");
	cub->img = mlx_new_image(cub->vars.mlx, 1920, 1080);
	cub->addr = mlx_get_data_addr((cub->img),
			&(cub->bits_per_pixel), &(cub->line_length),
			&(cub->endian));
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->img, 0, 0);
	mlx_loop(cub->vars.mlx);
	printf("cub3d\n");
	return (0);
}
