/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:39:23 by namenega          #+#    #+#             */
/*   Updated: 2021/01/26 17:14:56 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_verline(t_data *data, t_move *move, t_pos *pos)
{
	// int		x;

	// x = move->draw_start
	printf("pos->i = [%d]\n", pos->i);
	while (move->draw_start < move->draw_end)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, pos->i, move->draw_start, B);
		move->draw_start++;
	}
}
