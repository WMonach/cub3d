/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebrodeur <ebrodeur@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:25 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/08 14:27:30 by wmonacho         ###   ########lyon.fr   */
/*   Updated: 2022/12/08 14:17:57 by ebrodeur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include <string.h>
# include "../mlx/mlx.h"
# include "libft.h"
# include "../sources/get_next_line/get_next_line.h"

# define ESC 53
# define D_KEY 2
# define A_KEY 0
# define S_KEY 1
# define W_KEY 13

typedef struct s_texture {
	int		check_no_texture;
	int		check_so_texture;
	int		check_ea_texture;
	int		check_we_texture;
	int		check_f_texture;
	int		check_c_texture;
	int		check_texture_id;
	int		north_path_copy;
	int		south_path_copy;
	int		west_path_copy;
	int		east_path_copy;
	int		rgb_f_copy;
	int		rgb_c_copy;
	int		check_rgb_id;
	int		check_all_id;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
}	t_texture;

typedef struct s_map {
	int		map_size;
	int		player_x;
	int		player_y;
	int		check_north_spawn;
	int		check_south_spawn;
	int		check_west_spawn;
	int		check_east_spawn;
}	t_map;

enum {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
};

typedef struct s_data {
	int			north;
	int			south;
	int			west;
	int			east;
	int			check;
	int			size;
	int			end_line_check;
	int			id_number;
	int			nb_of_lines;
	int			length;
	int			check_comma;
	int			check_id_parsing;
	int			check_empty_line;
	int			first_line_ok;
	int			last_line_ok;
	int			no_free_tab;
	int			free_tab_map;
	int			textures_tab_size;
	int			rgb_tab_size;
	int			x_range;
	int			y_range;
	char		*line_tmp;
	char		*rgb_value;
	char		*texture_id[6];
	char		**texture_path;
	char		**rgb_values;
	char		**extension;
	char		**map;
	t_map		map_data;
	t_texture	texture;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct s_cub
{
	t_vars		vars;
	t_mlx_data	mlx_data;
	float		x;
	float		y;
	float		z;
	float		x1;
	int			Posx;
	int			Posy;
	float		x2;
	float		y1;
	float		y2;
	int			max;
}				t_cub;

int		ft_draw(t_cub *cub, t_mlx_data *img);
int		ft_draw_hero(t_cub *cub, t_mlx_data *img);
int		map_display(t_cub *cub, t_data *data, t_mlx_data *img);

/* PARSING */
char			**free_tab(char **tab, int i);

int				line_parsing_call_and_set_all_id_check(t_data *data,
					char *line, int fd);

unsigned int	map_strlcpy(char *dest, const char *src, size_t size);

int				copy_rgb_value(t_data *data, int index, int size, char *value);
int				previous_line_shorter(char **map, size_t i, size_t line_size,
					int y);
int				next_line_shorter(char **map, size_t i, size_t line_size,
					int y);
int				check_file_loop(t_data *data, char *line, int fd, int i);
int				last_char_is_not_one(char **map, int line_size, int y);
int				check_path_to_texture(t_data *data, int i, int size);
int				save_rgb_values(t_data *data, char *id, char *value);
int				map_wall_parsing_loop(t_data *data, int y, int x);
int				save_texture(t_data *data, char *id, char *path);
int				check_if_line_is_map(t_data *data, char *line);
int				check_extension(char *str, char *extension);
int				check_id(t_data *data, int i, int j, int k);
int				check_file_format(char *file, t_data *data);
int				line_check_loop(t_data *data, int y, int x);
int				check_if_spawn_is_set(t_data *data, int y);
int				count_number_of_spawn(t_data *data, int y);
int				first_or_last_line_ko(t_data *data, int y);
int				check_duplicates_rgb(t_data *data, int i);
int				check_file_opening(char *file, int size);
int				line_parsing(char	*line, t_data *data);
int				check_duplicates(t_data *data, int i);
int				space_check(char **map, int y, int x);
int				looking_for_multi_spawn(t_data *data);
int				map_parsing(char **map, t_data *data);
int				check_file(char *file, t_data *data);
int				check_chars(char *line, char *chars);
int				check_textures(t_data *data, int i);
int				map_copy(t_data *data, char *file);
int				check_colors(t_data *data, int i);
int				exterior_line_check(char *line);
int				map_wall_parsing(t_data *data);
int				close_check(char **map, int y);
int				check_rgb(t_data *data, int i);

#endif