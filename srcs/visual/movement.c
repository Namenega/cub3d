/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:12:04 by Nathan            #+#    #+#             */
/*   Updated: 2021/02/04 19:11:23 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_rotate_right(t_pos *pos/*, t_global *glb*/)
{
	if (KEYCODE_RIGHTARROW) //rotate to the right
	{
		// both cam dir and cam plane must be rotated
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(-RS) - pos->dir.y * sin(-RS);
		pos->dir.y = pos->old_dir.x * sin(-RS) + pos->dir.y * cos(-RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(-RS) - pos->plane_cam.y * sin(-RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(-RS) + pos->plane_cam.y * cos(-RS);
	}
}

void		ft_rotate_left(t_pos *pos)
{
	if (KEYCODE_LEFTARROW) //rotate to the left
	{
		//both cam dir and cam plane must be rotated
		pos->old_dir.x = pos->dir.x;
		pos->dir.x = pos->dir.x * cos(RS) - pos->dir.y * sin(RS);
		pos->dir.y = pos->old_dir.x * sin(RS) + pos->dir.y * cos(RS);
		pos->old_pl_cam.x = pos->plane_cam.x;
		pos->plane_cam.x = pos->plane_cam.x * cos(RS) - pos->plane_cam.y * sin(RS);
		pos->plane_cam.y = pos->old_pl_cam.x * sin(RS) + pos->plane_cam.y * cos(RS);
	}
}

void		ft_mvforward(t_pos *pos, t_map *map)
{
	printf("front - [%f]\t[%f]\n", map->x, map->y);
	if(KEYCODE_W) //move forward if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][(int)map->y] == 7 &&
		map->real_map[(int)(map->x + 0.2 + pos->dir.x * MS)][(int)map->y] == 7 &&
		map->real_map[(int)(map->x - 0.2 + pos->dir.x * MS)][(int)map->y] == 7)
			map->x += pos->dir.x * 0.1;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * MS)] == 7 &&
		map->real_map[(int)map->x][(int)(map->y - 0.2 + pos->dir.y * MS)] == 7 &&
		map->real_map[(int)map->x][(int)(map->y + 0.2 + pos->dir.y * MS)] == 7)
			map->y += pos->dir.y * 0.1;
	}
}

void		ft_mvbackward(t_pos *pos, t_map *map)
{
	printf("back - [%f]\t[%f]\n", map->x, map->y);
	if(KEYCODE_S) //move backward if no wall behind you
	{
		if(map->real_map[(int)(map->x - pos->dir.x * MS)][(int)map->y] == 7 &&
		map->real_map[(int)(map->x - 0.2 - pos->dir.x * MS)][(int)map->y] == 7 &&
		map->real_map[(int)(map->x + 0.2 - pos->dir.x * MS)][(int)map->y] == 7)
			map->x -= pos->dir.x * MS;
		if(map->real_map[(int)map->x][(int)(map->y - pos->dir.y * MS)] == 7 &&
		map->real_map[(int)map->x][(int)(map->y - 0.2 - pos->dir.y * MS)] == 7 &&
		map->real_map[(int)map->x][(int)(map->y + 0.2 - pos->dir.y * MS)] == 7)
			map->y -= pos->dir.y * MS;
	}
}

/* void    up(t_params *params)
// {
//     if (params->map[(int)(params->player->posx + params->player->dirx * params->player->movespeed)][(int)params->player->posy] == '0' &&

//     params->map[(int)(params->player->posx + params->player->dirx * params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0' &&

//     params->map[(int)(params->player->posx + params->player->dirx * params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0')

//         params->player->posx += params->player->dirx * 0.1;


//     if (params->map[(int)params->player->posx][(int)(params->player->posy
//     + params->player->diry * params->player->movespeed)] == '0' &&
//     params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy +
//     0.01 + params->player->diry * params->player->movespeed)] == '0' &&
//     params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
//     0.01 + params->player->diry * params->player->movespeed)] == '0')
//         params->player->posy += params->player->diry * 0.1;
// }
// void    down(t_params *params)
// {
//     if (params->map[(int)(params->player->posx - params->player->dirx *
//     params->player->movespeed)][(int)params->player->posy] == '0' &&
//     params->map[(int)(params->player->posx - params->player->dirx *
//     params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0' &&
//     params->map[(int)(params->player->posx - params->player->dirx *
//     params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0')
//         params->player->posx -= params->player->dirx * 0.1;
//     if (params->map[(int)params->player->posx][(int)(params->player->posy -
//     params->player->diry * params->player->movespeed)] == '0' &&
//     params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
//     params->player->diry * params->player->movespeed)] == '0' &&
//     params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy -
//     params->player->diry * params->player->movespeed)] == '0')
//         params->player->posy -= params->player->diry * 0.1;
// }*/
