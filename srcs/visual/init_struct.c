/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:50 by namenega          #+#    #+#             */
/*   Updated: 2021/02/01 15:20:28 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_color_asign(t_map *map, t_move *move)
{
	//choose wall color
	if (map->real_map[(int)move->map.x][(int)move->map.y] == 1)
	{
		map->color.r = 0x00800000;
		map->color.g = 0;
		map->color.b = B;
	}
	else if (map->real_map[(int)move->map.x][(int)move->map.y] == 2)
	{
		map->color.r = 0;
		map->color.g = G;
		map->color.b = 0;
	}
}

void		ft_init_struct(t_move *move, t_map *map)
{
	move->map.x = (int)map->x;
	move->map.y = (int)map->y;
	if (move->dir.y == 0)
		move->d_dist.x = 0;
	else
	{
		if (move->dir.x == 0)
			move->d_dist.x = 1;
		else
			move->d_dist.x = fabs(1 / move->dir.x);
	}
	if (move->dir.x == 0)
		move->d_dist.y = 0;
	else
	{
		if (move->dir.y == 0)
			move->d_dist.y = 1;
		else
			move->d_dist.y = fabs(1 / move->dir.y);
	}
	move->hit = 0;
}
