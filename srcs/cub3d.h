/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 18:07:41 by namenega         ###   ########.fr       */
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
	int		width;
	int		height;
	int		r;
	int		g;
	int		b;
	char	*path;
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

#include "utils.h"

/*
** MAIN.C
*/

int		main(int ac, char const **av);
int		ft_error_msg(char *s);

/*
** PARSING.C
*/

t_data	*ft_data(char *file, int ac);
int		ft_get_data(t_data *data, char *file);
int		ft_parsing_data(char *line, t_data *data);

/*
** GETTING_DATA.C
*/

int		ft_resolution(t_data *data, char *line);

/*
** FREE.C
*/

void	ft_free_data(t_data *data, char *str);

#endif