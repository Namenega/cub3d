/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:45:52 by namenega          #+#    #+#             */
/*   Updated: 2021/02/13 17:56:52 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_malloc_sprite(t_map *map)
{
	// map->spr_x = malloc(sizeof(int *) * map->numsprite + 1);
	// if (!map->spr_x)
	// 	ft_error_exit("Error\nMalloc spr_x failed.\nExit Program");
	// map->spr_y = malloc(sizeof(int *) * map->numsprite + 1);
	// if (!map->spr_y)
	// 	ft_error_exit("Error\nMalloc spr_y failed.\nExit Program");
	map->spr_x = ft_calloc(sizeof(int*), (map->numsprite + 1));
	map->spr_y = ft_calloc(sizeof(int*), (map->numsprite + 1));
}

void		ft_draw_stripe(t_spr *spr, t_data *data, t_pos *pos)
{
	spr->texx = (int)((spr->stripe - (-spr->spr_w / 2 + spr->spr_screenx)) *
		TXW / spr->spr_w);
	// printf("trans.f = [%f]\n", spr->transform.y);
	// printf("zbuf[stripe] = [%f]\n", data->zbuff[spr->stripe]);
	// printf("spr->stripe= [%d]\n", spr->stripe);
	// printf("data->width = [%d]\n", data->width);
	if (spr->transform.y > 0 && spr->stripe > 0 && spr->stripe < data->width &&
		spr->transform.y < data->zbuff[spr->stripe])
	{
		// printf("test_2\n\n");
		spr->y = spr->dwstart.y;
		while (spr->y < spr->dwend.y)
		{
			spr->d = (spr->y - spr->vmovesc) * 256 - data->height * 128 +
				spr->spr_h * 128;
			spr->texy = ((spr->d * data->sprite.h) / spr->spr_h) / 256;
			pos->color = data->sprite.addr[data->sprite.w * spr->texy + spr->texx];
			ft_mlx_pxl_put(data, pos->x, pos->y, pos->color);
			spr->y++;
		}
	}
}
/*params->sv->transformy = params->sv->invdet * (-params->player->planey
			* spritex + params->player->planex * spritey);*/

void		ft_init_sprite(t_spr *spr, t_map *map, t_global *glb, int i)
{
	spr->spr.x = map->spr_x[i] - map->x;
	spr->spr.y = map->spr_y[i] - map->y;
	spr->invdir = 1.0 / (glb->pos->plane_cam.x * glb->pos->dir.y -
		glb->pos->dir.x * glb->pos->plane_cam.y);
	spr->transform.x = spr->invdir * (glb->pos->dir.y * spr->spr.x -
		glb->pos->dir.x * spr->spr.y);
	spr->transform.y = spr->invdir * (-glb->pos->plane_cam.y * spr->spr.x +
		glb->pos->plane_cam.x * spr->spr.y);
	printf("trans.y = [%f]\n", spr->transform.y);
	spr->spr_screenx = (int)((glb->data->width / 2) * (1 + spr->transform.x /
		spr->transform.y));
	spr->vmovesc = (94 / spr->transform.y);
	spr->spr_h = abs((int)(glb->data->height / spr->transform.y));
	spr->dwstart.y = -spr->spr_h / 2 + glb->data->height / 2 + spr->vmovesc;
	if (spr->dwstart.y < 0)
		spr->dwstart.y = 0;
	spr->dwend.y = spr->spr_h / 2 + glb->data->height / 2 + spr->vmovesc;
	if (spr->dwend.y >= spr->spr_h)
		spr->dwend.y = spr->spr_h - 1;
	spr->spr_w = abs((int)(glb->data->height / spr->transform.y));
	spr->dwstart.x = -spr->spr_w / 2 + spr->spr_screenx;
	if (spr->dwstart.x < 0)
		spr->dwstart.x = 0;
	spr->dwend.x = spr->spr_w / 2 + spr->spr_screenx;
	if (spr->dwend.x > glb->data->width)
		spr->dwend.x = glb->data->width - 1;
}

void		tmp(t_map *map, int i, int j, char coord)
{
	double		swap;
	
	if (coord == 'x')
	{
		swap = map->spr_x[i];
		map->spr_x[i] = map->spr_x[j];
		map->spr_x[j] = swap;
	}
	else
	{
		swap = map->spr_y[i];
		map->spr_y[i] = map->spr_y[j];
		map->spr_y[j] = swap;
	}
}

/*
** Sorting sprite from far to close
*/

void		ft_sort_sprite(t_spr *spr, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->numsprite - 1)
	{
		spr->sp_order = ft_calloc(sizeof(int), map->numsprite);
		spr->sp_dist = ft_calloc(sizeof(double), map->numsprite);
		spr->sp_order[i] = i;
		spr->sp_dist[i] = ((map->x - map->spr_x[i]) *
			(map->x - map->spr_x[i]) +
			(map->y - map->spr_y[i]) *
			(map->y - map->spr_y[i]));
		j = i + 1;
		while (j < map->numsprite)
		{
			if (((map->x - map->spr_x[j]) *
			(map->x - map->spr_x[j]) +
			(map->y - map->spr_y[j]) *
			(map->y - map->spr_y[j])) > (int)spr->sp_dist)
			{
				tmp(map, i, j, 'x');
				tmp(map, i, j, 'y');
			}
			j++;
		}
		i++;
	}
}

void		ft_img_sprite(t_map *map, t_global *glb)
{
	int		i;
	
	i = 0;
	glb->spr = ft_calloc_2(sizeof(t_spr));
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
}
