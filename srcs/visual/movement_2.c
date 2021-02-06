/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:49:04 by namenega          #+#    #+#             */
/*   Updated: 2021/02/06 15:00:37 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//move left if no wall in front of you
void		ft_mvleft(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y > 0));
	j = 0.2 - (0.4 * (pos->dir.x < 0));
	if(map->real_map[(int)map->x][(int)(map->y + j)] == 7)
		map->y += pos->dir.x * MS;
	if(map->real_map[(int)(map->x + i)][(int)map->y] == 7)
		map->x -= pos->dir.y * MS;
}

//move right if no wall in front of you
void		ft_mvright(t_pos *pos, t_map *map)
{
	double i;
	double j;

	i = 0.2 - (0.4 * (pos->dir.y < 0));
	j = 0.2 - (0.4 * (pos->dir.x > 0));
		if(map->real_map[(int)(map->x + i)][(int)map->y] == 7)
			map->x += pos->dir.y * MS;
		if(map->real_map[(int)map->x][(int)(map->y + j)] == 7)
			map->y -= pos->dir.x * MS;
}
