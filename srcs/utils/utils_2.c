/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:39:23 by namenega          #+#    #+#             */
/*   Updated: 2021/01/29 19:55:21 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mlx_pxl_put(t_data *data, int x, int y, t_rgb color)
{
	(void)color;
	(data->addr)[y * (data->pxl_line) + x] = color.r + color.g + color.b;
}

void		ft_verline(t_data *data, t_move *move, t_pos *pos, t_map *map)
{
	while (move->draw_start < move->draw_end)
	{
		ft_mlx_pxl_put(data, pos->x, move->draw_start, map->color);
		move->draw_start++;
	}
}
