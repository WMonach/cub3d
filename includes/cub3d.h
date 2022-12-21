/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:26:25 by wmonacho          #+#    #+#             */
/*   Updated: 2022/12/21 15:19:52 by will             ###   ########lyon.fr   */
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
# include "libft.h"
# include "get_next_line.h"

# ifdef __linux__ 
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ESC 65307
#  define D_KEY 100
#  define A_KEY 97
#  define S_KEY 115
#  define W_KEY 119
# endif
# ifdef __APPLE__ 
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define ESC 53
#  define D_KEY 2
#  define A_KEY 0
#  define S_KEY 1
#  define W_KEY 13
# endif
#  define PI 3.1415926535 
#  define P2 PI/2
#  define P3 3*PI/2
#  define DELTA 0.62831853071
#  define DR 0.0174533

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
	float		minimap_coeff;
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
	int			width;
	char		*line_tmp;
	char		*rgb_value;
	char		*texture_id[6];
	char		**texture_path;
	char		**rgb_values;
	int			c_color;
	int			f_color;
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

typedef struct s_rayh
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
}				t_rayh;

typedef struct s_rayv
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	int		mp;
	int		dof;
}				t_rayv;

typedef struct s_collision
{
	int		ym_pos;
	int		xm_pos;
	int		yo_add;
	int		xo_add;
	int		yo_sub;
	int		xo_sub;
	int		xo_right;
	int		yo_right;
	int		xo_left;
	int		yo_left;
	int		xo;
	int		yo;
}				t_collision;

typedef struct s_img
{
	void	*data;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_cub
{
	t_vars		vars;
	t_mlx_data	mlx_data;
	t_data		data;
	t_rayv		ray_v;
	t_rayh		ray_h;
	t_collision	collision;
	t_img		img_n;
	t_img		img_s;
	t_img		img_w;
	t_img		img_e;
	int			hit_wall;
	int			v_check;
	int			h_check;
	float		ty_off;
	float		lineo;
	float		lineh;
	float		x;
	float		y;
	float		z;
	float		x1;
	float		pa;
	float		pdx;
	float		pdy;
	float		posx;
	float		posy;
	float		x2;
	float		y1;
	float		y2;
	float		max;
	float		bresenx;
	float		breseny;
	float		raylx;
	float		rayly;
	float		dist;
}				t_cub;

/* EXECUTION */

char	**free_texture_tab(t_data *data);
char	**free_tab(char **tab, int i);
char	**free_rgb_tab(t_data *data);

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color);
void	print_h_rayon(t_cub *cub, float rx, float ry, float ra);
void	print_v_rayon(t_cub *cub, float rx, float ry, float ra);
void	ft_rounded(float number1, float number2, t_cub	*cub);
void	main_data_var_init(t_data *data, t_cub *cub);
void	draw_walls(t_cub *cub, float ra, int r, float j);
void	init_cub_var(t_cub *cub, t_data *data);
void	main_texture_var_init(t_data *data);
void	init_ray_var(t_cub *cub);
void	draw_rays(t_cub *cub);

float	ft_max(float max1, float max2);

unsigned int	get_value(t_cub *cub, t_img *img, int y, int x);

int		map_display(t_cub *cub, t_data *data, t_mlx_data *img);
int		ft_keyhook_translation(int keycode, t_cub *cub);
int		map_copy_and_parsing(t_data *data, char **argv);
int		ft_keyhook_rotation(int keycode, t_cub *cub);
int		ft_draw_hero(t_cub *cub, t_mlx_data *img);
int		ft_draw(t_cub *cub, t_mlx_data *img);
int		ft_rz_rotation(float ra, t_cub *cub);
int		check_ray(t_cub *cub);
int		ft_close(t_cub *cub);

/* PARSING */

char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
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
int				copy_map_in_tab(t_data *data, char *line, int fd, int i);
int				last_char_is_not_one(char **map, int line_size, int y);
int				check_path_to_texture(t_data *data, int i, int size);
int				save_rgb_values(t_data *data, char *id, char *value);
int				map_wall_parsing_loop(t_data *data, int y, int x);
int				check_if_spawn_is_set(t_data *data, int y, int i);
int				save_texture(t_data *data, char *id, char *path);
int				check_if_line_is_map(t_data *data, char *line);
int				check_extension(char *str, char *extension);
int				check_id(t_data *data, int i, int j, int k);
int				check_file_format(char *file, t_data *data);
int				line_check_loop(t_data *data, int y, int x);
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