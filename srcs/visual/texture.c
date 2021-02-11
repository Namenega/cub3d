/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:25:37 by namenega          #+#    #+#             */
/*   Updated: 2021/02/11 16:22:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_wallx_texx(t_move *move, t_pos *pos, t_map *map)
{
	// calc value of wallX
	if (move->side == 0)
		pos->wall.x = map->y + move->perp_wall_dist * pos->dir.y;
	else
		pos->wall.x = map->x + move->perp_wall_dist * pos->dir.x;
	pos->wall.x -= floor((pos->wall.x));
	//X coord on the txture
	pos->tex.x = (int)(pos->wall.x * (double)TXW);
	if (move->side == 0 && pos->dir.x > 0)
		pos->tex.x = TXW - pos->tex.x - 1;
	if (move->side == 1 && pos->dir.y < 0)
		pos->tex.x = TXW - pos->tex.x - 1;
}

void		ft_texture(t_pos *pos, t_map *map, t_move *move, t_data *data)
{
	u_int32_t	buffer[data->height][data->width];
	double		zbuffer[data->width];

	// txturing calulations
	pos->txnum = map->real_map[(int)move->map.x][(int)move->map.y]/* - 1?*/;
	ft_wallx_texx(move, pos, map);
	// how much to increase the texture coord per pxl
	pos->stept = 1.0 * TXH / move->line_h;
	pos->texpos = (move->draw_start - data->height / 2 + move->line_h / 2)
		* pos->stept;
	pos->y = move->draw_start;
	while (pos->y < move->draw_end)
	{
		pos->tex.y = (int)pos->texpos & (TXH - 1);
		pos->tex.y += pos->stept;
		//pos->color = truc[pos->txnum][TXH * pos->tex.y + pos->tex.x];
		if (move->side == 1)
			pos->color = (pos->color >> 1) & 8355711;
		buffer[pos->y][pos->x] = pos->color;
		pos->y++;
	}
	zbuffer[pos->x] = move->perp_wall_dist;
}
