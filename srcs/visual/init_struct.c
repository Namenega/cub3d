/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:50 by namenega          #+#    #+#             */
/*   Updated: 2021/02/23 14:09:38 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Choose wall color
*/

void		ft_color_asign(t_map *map, t_data *data)
{
	map->colorc = data->b_sky + data->g_sky * 256 + data->r_sky * 65536;
	map->colorf = data->b_ground + data->g_ground * 256 + data->r_ground * 65536;
	// ft_free_things(data);
}

/*
** Initie delta_dist, hit et position
*/

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
