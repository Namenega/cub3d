/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:20:48 by namenega          #+#    #+#             */
/*   Updated: 2021/02/24 18:11:41 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libraries/cub3d.h"

/*
** Vector if N/S/W/E
*/

void	ft_dir_to_vec(int c, t_pos *pos)
{
	pos->dir.x = 0.0;
	pos->dir.y = 0.0;
	pos->plane_cam.x = 0.0;
	pos->plane_cam.y = 0.0;
	if (c == 3)
	{
		pos->dir.x = -1.0;
		pos->plane_cam.y = 0.66;
	}
	else if (c == 4)
	{
		pos->dir.x = 1.0;
		pos->plane_cam.y = -0.66;
	}
	else if (c == 5)
	{
		pos->dir.y = 1.0;
		pos->plane_cam.x = 0.66;
	}
	else if (c == 6)
	{
		pos->dir.y = -1.0;
		pos->plane_cam.x = -0.66;
	}
}

void	ft_verif_holes_2(t_map *map, int i, int j)
{
	if (map->real_map[i][j] <= 7 && map->real_map[i][j] >= 2)
	{
		if (!(j < map->width - 1) || (j == 0))
			ft_error_exit("Error\nMap Error\nExit Program");
		if (!(i < map->height_tmp - 1) || (i == 0))
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i][j - 1] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i][j + 1] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i + 1][j] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i - 1][j] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
	}
}

/*
** Check holes in map
*/

int		ft_verif_holes(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height_tmp)
	{
		j = 0;
		while (j < map->width)
		{
			ft_verif_holes_2(map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Check char in map
*/

int		ft_verif_char(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height_tmp)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->real_map[i][j] > 7 || map->real_map[i][j] < -1)
				ft_error_exit("Error\nWrong char in map\nExit Program");
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verif_map(t_map *map)
{
	ft_verif_char(map);
	ft_verif_holes(map);
	return (1);
}
