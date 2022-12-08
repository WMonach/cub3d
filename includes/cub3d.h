/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:25 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/06 17:25:57 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include <string.h>
# include <fcntl.h>


typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_cub
{
	t_vars		vars;
	t_data		data;
	float		x;
	float		y;
	float		z;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			max;
}				t_cub;

int		ft_draw(t_cub *cub, t_data *img);

#endif