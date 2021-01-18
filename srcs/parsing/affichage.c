/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/18 17:47:47 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_affichage(t_data *data)
{
	int			i;
	t_pos		*pos;
	t_ray		*ray;

	i = 0;
	pos = (t_pos*)malloc(sizeof(t_pos));
	ray = (t_ray*)malloc(sizeof(t_ray));
	pos->pos.x = 22;
	pos->pos.y = 12;
	pos->dir.x = -1;
	pos->dir.y = 0;
	pos->plane_cam.x = 0;
	pos->plane_cam.y = 0.66;
	while (i < data->width)
	{
		pos->camera.x = 2 * (double)i / (double)data->width - 1;
		ray->dir.x = pos->dir.x + (pos->plane_cam.x * pos->camera.x);
		ray->dir.y = pos->dir.y + (pos->plane_cam.y * pos->camera.y);
		i++;
	}
	printf("plane_cam.x = [%f]", pos->camera.x);
	return (1);
}
