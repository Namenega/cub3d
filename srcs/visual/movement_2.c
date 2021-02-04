/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/02/04 16:31:43 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mvleft(t_pos *pos, t_map *map)
{
	if(KEYCODE_A) //move left if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][(int)map->y] == 7)
			map->x -= pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * MS)] == 7)
			map->y += pos->dir.x * MS;
	}
}

void		ft_mvright(t_pos *pos, t_map *map)
{
	printf("[%f]\t[%f]\n", map->x, map->y);
	if(KEYCODE_D) //move right if no wall in front of you
	{
		if(map->real_map[(int)(map->x + pos->dir.x * MS)][(int)map->y] == 7)
			map->x += pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + pos->dir.y * MS)] == 7)
			map->y -= pos->dir.x * MS;
	}
}

// int			hook_loop(t_pos *pos/*, t_map *map*/)
// {
// 	ft_rotate_left(pos);
// 	ft_rotate_right(pos);
// 	// ft_rotate_mvright(pos, map);
// 	// ft_rotate_mvleft(pos, map);
// 	// ft_rotate_mvforward(pos, map);
// 	// ft_rotate_mvbackward(pos, map);
// 	return (0);
// }
