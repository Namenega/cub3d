/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/08 17:41:59 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/mlx/mlx.h"
# include "get_next_line.h"
# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF

typedef struct	s_data
{
	int			width;
	int			height;
	int			r;
	int			g;
	int			b;
	char		*path_sprite;
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_west;
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

#include "utils.h"

/*
** PARSING/MAIN.C
*/

int		main(int ac, char const **av);
int		ft_error_msg(char *s);

/*
** PARSING/PARSING.C
*/

t_data	*ft_data(char *file, int ac);
int		ft_get_data(t_data *data, char *file);
int		ft_parsing_data(char *line, t_data *data);

/*
** PARSING/SPRITES_PATH/GETTING_DATA.C
*/

int		ft_resolution(t_data *data, char *line);
int		ft_sprite(t_data *data, char *line);
int		ft_color_groundsky(t_data *data, char *line);

/*
** PARSING/SPRITES_PATH/DIRECTIONS.C
*/

int		ft_north(t_data *data, char *line);
int		ft_south(t_data *data, char *line);
int		ft_west(t_data *data, char *line);
int		ft_east(t_data *data, char *line);

/*
** PARSING/EVENT.C
*/

int		ft_event(t_data *data);
int		ft_exit_hook(void *x);

/*
** PARSING/FREE.C
*/

void	ft_free_data(t_data *data, char *str);

#endif