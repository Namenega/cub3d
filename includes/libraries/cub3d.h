/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/02/25 19:22:54 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** INCLUDES
*/

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

/*
** DEFINES
*/

# define MS 0.1
# define RS 0.1
# define TXW 64
# define TXH 64

# define XEVENT_KEYPRESS 2
# define XEVENT_KEYRELEASE 3
# define XEVENT_EXIT 17

# define KEYCODE_ESC 53
# define KEYCODE_RIGHTARROW 124
# define KEYCODE_LEFTARROW 123
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2

/*
** Sprite texture's variables
*/

typedef struct		s_tex
{
	void			*img;
	int				*addr;
	int				w;
	int				h;
	int				line_length;
	int				bit;
	int				endian;
}					t_tex;

/*
** Data's variables
*/

typedef struct		s_data
{
	int				width;
	int				height;
	int				bits_per_pxl;
	int				line_length;
	int				endian;
	int				width_verif;
	int				height_verif;
	int				r_sky;
	int				g_sky;
	int				b_sky;
	int				r_ground;
	int				g_ground;
	int				b_ground;
	int				*addr;
	char			*path_sprite;
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	int				r_sky_verif;
	int				g_sky_verif;
	int				b_sky_verif;
	int				r_ground_verif;
	int				g_ground_verif;
	int				b_ground_verif;
	int				path_sprite_verif;
	int				path_north_verif;
	int				path_south_verif;
	int				path_east_verif;
	int				path_west_verif;
	void			*mlx;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				pxl_line;
	int				parsed;
	t_list			*lst_line;
	t_tex			north;
	t_tex			south;
	t_tex			west;
	t_tex			east;
	t_tex			sprite;
	double			*zbuff;
}					t_data;

/*
** Color's variables
*/

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

/*
** Map's variables
*/

typedef struct		s_map
{
	int				i;
	int				j;
	double			x;
	double			y;
	int				width;
	int				height;
	int				height_tmp;
	int				**real_map;
	t_rgb			color;
	int				position;
	u_int32_t		colorc;
	u_int32_t		colorf;
	int				numsprite;
	double			*spr_x;
	double			*spr_y;
}					t_map;

/*
** Vector's variables
*/

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

/*
** Position's variables
*/

typedef struct		s_pos
{
	int				x;
	int				y;
	t_vec			dir;
	t_vec			old_dir;
	t_vec			plane_cam;
	t_vec			old_pl_cam;
	t_vec			camera;
	t_vec			wall;
	t_vec			tex;
	double			stept;
	double			texpos;
	u_int32_t		color;
}					t_pos;

/*
** Movement's variables
*/

typedef struct		s_move
{
	t_vec			dir;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
	t_vec			map;
	t_vec			step;
	t_vec			d_dist;
	t_vec			side_dist;
}					t_move;

/*
** Sprite's variables
*/

typedef struct		s_spr
{
	int				*sp_order;
	double			*sp_dist;
	t_vec			spr;
	double			invdir;
	t_vec			transform;
	int				spr_screenx;
	int				vmovesc;
	int				spr_w;
	int				spr_h;
	t_vec			dwstart;
	t_vec			dwend;
	int				stripe;
	int				texx;
	int				texy;
	int				y;
	int				d;
	double			tmp;
}					t_spr;

/*
** Global Struct
*/

typedef struct		s_global
{
	const char		*argv;
	t_spr			*spr;
	t_move			*move;
	t_pos			*pos;
	t_data			*data;
	t_map			*map;
}					t_global;

/*
** PARSING/MAIN.C
*/

int					main(int ac, char const **av);
int					ft_error_msg(char *s);
void				ft_error_exit(char *s);
void				ft_malloc_protect(t_global *glb);

/*
** PARSING/PARSING.C
*/

t_data				*ft_data(char *file, int ac, t_map *map, t_pos *pos);
int					ft_get_data(t_data *data, char *file, t_map *map,
						t_pos *pos);
int					ft_gnl(int fd, t_data *data, t_map *map, t_pos *pos);
void				ft_loop_parse(t_list *each_line, t_data *data,
						t_map *map, t_pos *pos);
int					ft_parsing_data(t_list *el, t_data *data,
						t_map *map, t_pos *pos);

/*
** PARSING/PARSING2.C
*/

int					ft_data_parsed(t_data *data, t_pos *pos,
						t_map *map, t_list *el);
int					ft_parsing_begin(char *line, t_data *data);

/*
** PARSING/SPRITES_PATH/RESOLUTION.C
*/

int					ft_resolution(t_data *data, char *line);
void				ft_error_resolution_1(char *line);
unsigned long int	ft_uli_error(const char *line);
void				ft_error_resolution_3(char *line);
void				ft_error_resolution_4(char *line);

/*
** PARSING/SPRITES_PATH/OBSTACLE.C
*/

int					ft_sprite(t_data *data, char *line);

/*
** PARSING/SPRITES_PATH/SKY.C
*/

int					ft_color_sky(t_data *data, char *line);
void				ft_error_skyground_1(char *line);
void				ft_empty_line(char *strs);
t_data				*ft_error_skyg_2(t_data *data);

/*
** PARSING/SPRITES_PATH/GROUND.C
*/

int					ft_color_ground(t_data *data, char *line);
t_data				*ft_error_ground(t_data *data);
void				ft_error_skyground_5(t_data *data);
char				**split_rgb_ground(char *line);
void				ft_error_skyground_6(char **strs);

/*
** PARSING/SPRITES_PATH/DIRECTIONS.C
*/

int					ft_north(t_data *data, char *line);
int					ft_south(t_data *data, char *line);
int					ft_west(t_data *data, char *line);
int					ft_east(t_data *data, char *line);

/*
** PARSING/MAP_PARSING/MAP.C
*/

int					ft_map(t_list *el, t_data *data, t_map *map, t_pos *pos);
t_map				*ft_get_map_hw(t_map *map, t_list *el);
t_map				*ft_map_data(t_map *map, t_list *el, t_pos *pos);
t_map				*ft_map_asign(t_list *el, t_map *map, t_pos *pos);
void				ft_char_to_int(t_pos *pos, t_map *map, t_list *el);

/*
** PARSING/MAP_PARSING/VERIF_MAP.C
*/

int					ft_verif_map(t_map *map);
int					ft_verif_char(t_map *map);
int					ft_verif_holes(t_map *map);
void				ft_verif_holes_2(t_map *map, int i, int j);
void				ft_dir_to_vec(int c, t_pos *pos);

/*
** VISUAL/AFFICHAGE.C
*/

int					ft_affichage(t_global *glb);
void				ft_s_p(t_map *map, t_move *move, t_data *data, t_pos *pos);
void				ft_condition_ray(t_move *move, t_map *map);
void				ft_move_square(t_move *move, t_map *map);
void				ft_pxl_tofill(t_move *move, t_data *data, t_map *map);

/*
** VISUAL/INIT_STRUCT.C
*/

void				ft_init_struct(t_move *move, t_map *map);
void				ft_color_asign(t_map *map, t_data *data);

/*
** VISUAL/TEXTURE.C
*/

void				ft_texture(t_pos *pos, t_map *map, t_move *move,
						t_data *data);
void				ft_wallx_texx(t_move *move, t_pos *pos, t_map *map,
						t_tex tex);
void				ft_img(t_data *data);
void				ft_free_things(t_data *data);

/*
** VISUAL/SPRITE.C
*/

void				ft_img_sprite(t_map *map, t_global *glb);
void				ft_sort_sprite(t_spr *spr, t_map *map);
void				tmp(t_map *map, int i, int j, char coord);
void				ft_init_sprite(t_spr *spr, t_map *map, t_global *glb,
						int i);
void				ft_draw_stripe(t_spr *spr, t_data *data, t_pos *pos);
void				ft_malloc_sprite(t_map *map);

/*
** VISUALS/MOVEMENT.C
*/

void				ft_rotate_right(t_pos *pos);
void				ft_rotate_left(t_pos *pos);
void				ft_mvforward(t_pos *pos, t_map *map);
void				ft_mvbackward(t_pos *pos, t_map *map);

/*
** VISUALS/MOVEMENT_2.C
*/

void				ft_mvright(t_pos *pos, t_map *map);
void				ft_mvleft(t_pos *pos, t_map *map);

/*
** PARSING/EVENT.C
*/

int					ft_drop_the_cub(t_global *glb);
int					ft_exit_hook(void *x);
int					ft_keypress_hook(int key, t_global *glb);
int					ft_keyrelease_hook(int key, t_global *glb);
int					hook_loop(t_global *glb, int ac);

/*
** PARSING/BMP.C
*/

void				ft_save(t_global *glb);

/*
** PARSING/FREE.C
*/

void				ft_free_data(t_data *data, char *str);

/*
** UTILS/UTILS_2.C
*/

void				ft_verline(t_data *data, t_move *move, t_pos *pos,
						t_map *map);
void				ft_mlx_pxl_put(t_data *data, int x, int y, u_int32_t color);
void				*ft_calloc_2(size_t nmemb);
void				ft_mlx_data(t_data *data);
void				ft_position_asign(int c, t_map *map, t_pos *pos);

#endif
