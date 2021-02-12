/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:45:52 by namenega          #+#    #+#             */
/*   Updated: 2021/02/12 19:04:56 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void		ft_malloc_sprite(t_map *map)
{
	map->spr_x = malloc(sizeof(int *) * map->numsprite + 1);
	if (!map->spr_x)
		ft_error_exit("Error\nMalloc spr_x failed.\nExit Program");
	map->spr_y = malloc(sizeof(int *) * map->numsprite + 1);
	if (!map->spr_y)
		ft_error_exit("Error\nMalloc spr_y failed.\nExit Program");
}

void		ft_init_sprite(t_spr *spr, t_map *map, t_global *glb, int i)
{
	//translate sprite pos to relative camera;
	spr->spr.x = map->spr_x[i] - map->x;
	spr->spr.y = map->spr_y[i] - map->y;
	// required for correct matrix multiplication
	spr->invdir = 1.0 / (glb->pos->plane_cam.x * glb->pos->dir.y -
		glb->pos->dir.x * glb->pos->plane_cam.y);
	// depth inside the screen
	spr->transform.x = spr->invdir * (glb->pos->dir.y * spr->spr.x -
		glb->pos->dir.x * spr->spr.y);
	spr->transform.y = spr->invdir * (-glb->pos->plane_cam.y * spr->spr.x +
		glb->pos->plane_cam.x * spr->spr.y);
	spr->spr_screenx = (int)((glb->data->width / 2) * (1 + spr->transform.x /
		spr->transform.y));
	spr->vmovesc = (94 / spr->transform.y);
	//height of sprite on screen
	spr->spr_h = fabs((glb->data->height / (int)spr->transform.y)) / VDIV;
	//calculate highest & lowest pxl to fill in current stripe
	spr->dwstart.y = -spr->spr_h / 2 + glb->data->height / 2 + spr->vmovesc;
	if (spr->dwstart.y < 0)
		spr->dwstart.y = 0;
	spr->dwend.y = spr->spr_h / 2 + glb->data->height / 2 + spr->vmovesc;
	if (spr->dwend.y >= spr->spr_h)
		spr->dwend.y = spr->spr_h - 1;
}

void		ft_img_sprite(t_map *map, t_data *data, t_global *glb)
{
	int		i;
	
	i = 0;
	glb->spr = ft_calloc_2(sizeof(t_spr));
	ft_sort_sprite(glb->spr, map);
	while (i < map->numsprite)
	{
		ft_init_sprite(glb->spr, map, glb, i);
	}
}
