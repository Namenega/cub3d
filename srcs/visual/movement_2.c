/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/02/01 16:49:52 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mvleft(t_pos *pos, t_map *map)
{
	if(KEYCODE_A) //move forward if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][(int)map->y] == 0)
			map->x += pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * MS)] == 0)
			map->y -= pos->dir.x * MS;
	}
}

void		ft_mvright(t_pos *pos, t_map *map)
{
	if(KEYCODE_D) //move forward if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][(int)map->y] == 0)
			map->x -= pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * MS)] == 0)
			map->y += pos->dir.x * MS;
	}
}

int			hook_loop(t_pos *pos, t_map *map)
{
	ft_rotate_left(pos);
	ft_rotate_right(pos);
	ft_rotate_mvright(pos);
	ft_rotate_mvleft(pos);
	ft_rotate_mvforward(pos);
	ft_rotate_mvbackward(pos);
	return (0);
}
