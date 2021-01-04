/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/04 17:59:42 by namenega         ###   ########.fr       */
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
# include "utils.h"
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
}				t_data;

int		main(void);

#endif