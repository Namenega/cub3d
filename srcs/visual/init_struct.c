/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:50 by namenega          #+#    #+#             */
/*   Updated: 2021/01/29 18:40:58 by namenega         ###   ########.fr       */
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

void		ft_init_move(t_move *move, t_ray *ray, t_map *map)
{
	move->map.x = (double)map->x;
	move->map.y = (double)map->y;
	if (ray->dir.y == 0)
		move->d_dist.x = 0;
	else
	{
		if (ray->dir.x == 0)
			move->d_dist.x = 1;
		else
			move->d_dist.x = fabs(1 / ray->dir.x);
	}
	if (ray->dir.x == 0)
		move->d_dist.y = 0;
	else
	{
		if (ray->dir.y == 0)
			move->d_dist.y = 1;
		else
			move->d_dist.y = fabs(1 / ray->dir.y);
	}
	move->hit = 0;
}

void		ft_init_pos_vec(t_pos *pos)
{
	pos->ttime = 0;
	pos->oldtime = 0;
	pos->x = 0;
}
