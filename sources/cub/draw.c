/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:52 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/08 11:14:21 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_draw(t_cub *cub, t_mlx_data *img)
{
	int	i;

	i = -1;
	cub->max = 1000;
	cub->x1 = 0;
	cub->y1 = 1;
	while (++i < cub->max)
	{
		{
			cub->x1++;
			cub->y1++;
			// ft_rounded(fdf->temp.x1, fdf->temp.y1, fdf);
			my_mlx_pixel_put(img, (int)cub->x1,
				(int)cub->y1, 0xffefd5);
		}
	}
	return (1);
}
