/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:12:04 by Nathan            #+#    #+#             */
/*   Updated: 2021/02/01 14:17:00 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*void		ft_rotate_right(t_pos *pos)
{
	if (key_right_arrow) //rotate to the right
	{
		//both cam dir and cam plane must be rotated
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

void		ft_rotate_left(t_pos *pos)
{
	if (key_left_arrow) //rotate to the left
	{
		//both cam dir and cam plane must be rotated
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

void		ft_mvforward(t_pos *pos, t_map *map)
{
	if(key_W_forward) //move forward if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][map->y] == false)
			map->x += pos->dir.x * MS;
		if(map->real_map[map->x][(int)(map->y + pos->dir.y * MS)] == false)
			map->y += pos->dir.y * MS;
	}
}

void		ft_mvbackward(t_pos *pos, t_map *map)
{
	if(key_S_backward) //move backward if no wall behind you
	{
		if(map->real_map[(int)(map->x - pos->dir.x * MS)][map->y] == false)
			map->x -= pos->dir.x * MS;
		if(map->real_map[map->x][(int)(map->y - pos->dir.y * MS)] == false)
			map->y -= pos->dir.y * MS;
	}
}*/


// fleches R/L = rotation camera
// WASD = avancer, gauche, reculer, droite

// mlx_loop_hook(mlx_ptr, &f, (void *)truc);
// mlx_hook(data->win_ptr, XEVENT_KEYPRESS, 0, &f, (void *)truc);
// mlx_hook(data->win_ptr, XEVENT_KEYRELEASE, 0, &f, (void *)truc);
// mlx_hook(data->win_ptr, XEVENT_EXIT, 0, &f, (void *)truc);
