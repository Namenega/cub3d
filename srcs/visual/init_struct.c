/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:50 by namenega          #+#    #+#             */
/*   Updated: 2021/01/25 14:30:22 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_init_move(t_move *move, t_ray *ray, t_map *map)
{
	move->map.x = (double)map->x;
	move->map.y = (double)map->y;
	move->d_dist.x = fabs(1 / ray->dir.x);
	move->d_dist.y = fabs(1 / ray->dir.y);
	move->hit = 0;
}

void		ft_init_pos_vec(t_pos *pos)
{
	pos->plane_cam.x = 0;
	pos->plane_cam.y = 0.66;
}
