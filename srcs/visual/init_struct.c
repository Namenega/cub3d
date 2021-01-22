/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:50 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 15:43:07 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_init_move(t_move *move, t_pos *posi, t_ray *ray)
{
	move->map.x = (int)posi->pos.x;
	move->map.y = (int)posi->pos.y;
	move->d_dist.x = fabs(1 / ray->dir.x);
	move->d_dist.y = fabs(1 / ray->dir.y);
	move->hit = 0;
}

void		ft_init_pos_vec(t_pos *posi)
{
	posi->pos.x = 22;
	posi->pos.y = 12;
	posi->dir.x = -1;
	posi->dir.y = 0;
	posi->plane_cam.x = 0;
	posi->plane_cam.y = 0.66;
}
