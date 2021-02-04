/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/02/04 19:37:40 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mvleft(t_pos *pos, t_map *map)
{
	printf("gauche - [%f]\t[%f]\n", map->x, map->y);
	printf("[%d]\n", map->real_map[(int)(map->x + pos->dir.x * MS)][(int)(map->y)]);
	//move left if no wall in front of you
	if(map->real_map[(int)(map->x + pos->plane_cam.x * MS)][(int)(map->y)] == 7 &&
	map->real_map[(int)((map->x - 0.1) + pos->dir.x * MS)][(int)(map->y)] == 7 &&
	map->real_map[(int)((map->x + 0.1) + pos->dir.x * MS)][(int)(map->y )] == 7)
		map->x -= pos->dir.y * 0.1;
	if(map->real_map[(int)(map->x)][(int)((map->y) + pos->dir.y * MS)] == 7 &&
	map->real_map[(int)(map->x)][(int)((map->y - 0.1) + pos->dir.y * MS)] == 7 &&
	map->real_map[(int)(map->x)][(int)((map->y + 0.1) + pos->dir.y * MS)] == 7)
		map->y += pos->dir.x * 0.1;
}

void		ft_mvright(t_pos *pos, t_map *map)
{
	printf("droite - [%f]\t[%f]\n", map->x, map->y);
	printf("[%d]\n", map->real_map[(int)((map->x) + pos->dir.x * MS)][(int)(map->y)]);
	if(KEYCODE_D) //move right if no wall in front of you
	{
		if(map->real_map[(int)((map->x) + pos->dir.x * MS)][(int)(map->y)] == 7 &&
		map->real_map[(int)((map->x + 0.1) + pos->dir.x * MS)][(int)(map->y)] == 7 &&
		map->real_map[(int)((map->x - 0.1) + pos->dir.x * MS)][(int)(map->y )] == 7)
			map->x += pos->dir.y * 0.1;
		if(map->real_map[(int)map->x][(int)((map->y) + pos->dir.y * MS)] == 7 &&
		map->real_map[(int)(map->x)][(int)((map->y + 0.1) + pos->dir.y * MS)] == 7 &&
		map->real_map[(int)(map->x)][(int)((map->y - 0.1) + pos->dir.y * MS)] == 7)
			map->y -= pos->dir.x * 0.1;
	}
}

/* if (params->map[(int)(params->player->posx - params->player->planex * params->player->movespeed)][(int)(params->player->posy)] == '0' &&
    params->map[(int)(params->player->posx - params->player->planex *
    params->player->movespeed)][(int)(params->player->posy - 0.01)] == '0' &&
    params->map[(int)(params->player->posx - params->player->planex *
    params->player->movespeed)][(int)(params->player->posy + 0.01)] == '0')
        params->player->posx -= params->player->planex * 0.1;
    if (params->map[(int)params->player->posx][(int)(params->player->posy -
    params->player->planey * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posx - 0.01)][(int)(params->player->posy -
    params->player->planey * params->player->movespeed)] == '0' &&
    params->map[(int)(params->player->posx + 0.01)][(int)(params->player->posy -
    params->player->planey * params->player->movespeed)] == '0')
        params->player->posy -= params->player->planey * 0.1;*/