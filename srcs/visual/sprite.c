/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:45:52 by namenega          #+#    #+#             */
/*   Updated: 2021/02/26 12:16:49 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

void		ft_malloc_sprite(t_map *map)
{
	map->spr_x = ft_calloc(sizeof(int*), (map->numsprite + 1));
	if (!map->spr_x)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	map->spr_y = ft_calloc(sizeof(int*), (map->numsprite + 1));
	if (!map->spr_y)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	map->numsprite = 0;
}

void		ft_draw_stripe(t_spr *spr, t_data *data, t_pos *pos)
{
	spr->texx = (int)(spr->stripe - (-spr->spr_w / 2 + spr->spr_screenx)) *
		TXW / spr->spr_w;
	if (spr->transform.y > 0 && spr->stripe > 0 && spr->stripe <
		data->width && spr->transform.y < data->zbuff[spr->stripe])
	{
		spr->y = spr->dwstart.y;
		while (spr->y < spr->dwend.y)
		{
			spr->d = spr->y * 256 - data->height * 128 +
				spr->spr_h * 128;
			spr->texy = ((spr->d * data->sprite.h) / spr->spr_h) / 256;
			pos->color = data->sprite.addr[data->sprite.w * spr->texy +
				spr->texx];
			if (pos->color != 0)
				ft_mlx_pxl_put(data, spr->stripe, spr->y, pos->color);
			spr->y++;
		}
	}
}

void		ft_init_sprite(t_spr *spr, t_map *map, t_global *glb, int i)
{
	spr->spr.y = map->spr_x[i] - map->y;
	spr->spr.x = map->spr_y[i] - map->x;
	spr->invdir = 1.0 / (glb->pos->plane_cam.x * glb->pos->dir.y -
		glb->pos->dir.x * glb->pos->plane_cam.y);
	spr->transform.x = spr->invdir * (glb->pos->dir.y * spr->spr.x -
		glb->pos->dir.x * spr->spr.y);
	spr->transform.y = spr->invdir * (-glb->pos->plane_cam.y * spr->spr.x +
		glb->pos->plane_cam.x * spr->spr.y);
	spr->spr_screenx = (int)((glb->data->width / 2) * (1 + spr->transform.x /
		spr->transform.y));
	spr->spr_h = abs((int)(glb->data->height / spr->transform.y));
	spr->dwstart.y = -spr->spr_h / 2 + glb->data->height / 2;
	if (spr->dwstart.y < 0)
		spr->dwstart.y = 0;
	spr->dwend.y = spr->spr_h / 2 + glb->data->height / 2;
	if (spr->dwend.y >= glb->data->height)
		spr->dwend.y = glb->data->height - 1;
	spr->spr_w = abs((int)(glb->data->height / spr->transform.y));
	spr->dwstart.x = -spr->spr_h / 2 + spr->spr_screenx;
	if (spr->dwstart.x < 0)
		spr->dwstart.x = 0;
	spr->dwend.x = spr->spr_w / 2 + spr->spr_screenx;
	if (spr->dwend.x >= glb->data->width)
		spr->dwend.x = glb->data->width - 1;
}

/*
** Sorting sprite from far to close
*/

void		ft_sort_sprite(t_spr *spr, t_map *map)
{
	int		i;
	double	first;
	double	second;

	i = 0;
	while (i < map->numsprite && (i + 1 != map->numsprite))
	{
		first = ((map->y - map->spr_x[i]) * (map->y - map->spr_x[i]) +
			(map->x - map->spr_y[i]) * (map->x - map->spr_y[i]));
		second = ((map->y - map->spr_x[i + 1]) * (map->y - map->spr_x[i + 1]) +
			(map->x - map->spr_y[i + 1]) * (map->x - map->spr_y[i + 1]));
		if (first < second)
		{
			spr->tmp = map->spr_x[i];
			map->spr_x[i] = map->spr_x[i + 1];
			map->spr_x[i + 1] = spr->tmp;
			spr->tmp = map->spr_y[i];
			map->spr_y[i] = map->spr_y[i + 1];
			map->spr_y[i + 1] = spr->tmp;
		}
		else
			i++;
	}
}

void		ft_img_sprite(t_map *map, t_global *glb)
{
	int		i;

	i = 0;
	glb->spr = ft_calloc_2(sizeof(t_spr));
	if (!glb->spr)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	ft_sort_sprite(glb->spr, map);
	while (i < map->numsprite)
	{
		ft_init_sprite(glb->spr, map, glb, i);
		glb->spr->stripe = glb->spr->dwstart.x;
		while (glb->spr->stripe < glb->spr->dwend.x)
		{
			ft_draw_stripe(glb->spr, glb->data, glb->pos);
			glb->spr->stripe++;
		}
		i++;
	}
	free(glb->spr);
}
