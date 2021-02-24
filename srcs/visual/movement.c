/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:12:04 by Nathan            #+#    #+#             */
/*   Updated: 2021/02/24 18:15:17 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

/*
** Rotate to the right
*/

void		ft_rotate_right(t_pos *pos)
{
	if (KEYCODE_RIGHTARROW == 124)
	{
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(-RS) - pos->dir.y * sin(-RS);
		pos->dir.y = pos->old_dir.x * sin(-RS) + pos->dir.y * cos(-RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(-RS) -
			pos->plane_cam.y * sin(-RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(-RS) +
			pos->plane_cam.y * cos(-RS);
	}
}

/*
** Rotate to the left
*/

void		ft_rotate_left(t_pos *pos)
{
	if (KEYCODE_LEFTARROW == 123)
	{
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(RS) - pos->dir.y * sin(RS);
		pos->dir.y = pos->old_dir.x * sin(RS) + pos->dir.y * cos(RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(RS) -
			pos->plane_cam.y * sin(RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(RS) +
			pos->plane_cam.y * cos(RS);
	}
}

/*
** Move forward if no wall in front of you
*/

void		ft_mvforward(t_pos *pos, t_map *map)
{
	if (KEYCODE_W)
	{
		if (map->real_map[(int)(map->x + pos->dir.x * 0.2)]
			[(int)map->y] == 7)
			map->x += pos->dir.x * MS;
		if (map->real_map[(int)map->x]
			[(int)(map->y + pos->dir.y * 0.2)] == 7)
			map->y += pos->dir.y * MS;
	}
}

/*
** Move backward if no wall behind you
*/

void		ft_mvbackward(t_pos *pos, t_map *map)
{
	if (KEYCODE_S)
	{
		if (map->real_map[(int)(map->x - pos->dir.x * 0.2)]
			[(int)map->y] == 7)
			map->x -= pos->dir.x * MS;
		if (map->real_map[(int)map->x]
			[(int)(map->y - pos->dir.y * 0.2)] == 7)
			map->y -= pos->dir.y * MS;
	}
}
