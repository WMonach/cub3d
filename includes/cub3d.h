/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:25 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/06 14:37:13 by wmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <string.h>
# include <fcntl.h>


typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_cub
{
	t_vars		vars;
	char		*addr;
	void		*img;
	float		x;
	float		y;
	float		z;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_cub;

#endif