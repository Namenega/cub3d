/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/30 16:10:21 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pxl_tofill(t_move *move, t_ray *ray, t_data *data, t_map *map)
{
	//calc the distance projected on camera direction (w/o fisheye effect)
	if (move->side == 0)
		move->perp_wall_dist = (move->map.x - map->x + (1 - move->step.x) / 2) / ray->dir.x;
	else
		move->perp_wall_dist = (move->map.y - map->y + (1 - move->step.y) / 2) / ray->dir.y;
	//calc height of line to draw on screen
	move->line_h = (int)(data->height / move->perp_wall_dist);
	//calc lowest and highest pixel to fill in current stripe
	move->draw_start = -move->line_h / 2 + data->height / 2;
	if (move->draw_start < 0)
		move->draw_start = 0;
	move->draw_end = move->line_h / 2 + data->height / 2;
	if (move->draw_end >= data->height)
		move->draw_end = data->height - 1;
}

/*
** Jumping to next square (or x/y direction)
*/

void		ft_move_square(t_move *move, t_map *map)
{
	move->side = 0;

	//perform DDA
	while (move->hit == 0)
	{
		//jump next map square (x/y direction)
		if (move->side_dist.x < move->side_dist.y)
		{
			move->side_dist.x += move->d_dist.x;
			move->map.x += move->step.x;
			move->side = 0;
		}
		else
		{
			move->side_dist.y += move->d_dist.y;
			move->map.y += move->step.y;
			move->side = 1;
		}
		//check if ray has hit a wall
		if (map->real_map[(int)move->map.x][(int)move->map.y] == 1)
			move->hit = 1;
	}
}

/*
** Calculate step and initial side_dist
*/

void		ft_condition_ray(t_ray *ray, t_move *move, t_map *map)
{
	if (ray->dir.x < 0)
	{
		move->step.x = -1;
		move->side_dist.x = ((double)map->x - move->map.x) * move->d_dist.x;
	}
	else
	{
		move->step.x = 1;
		move->side_dist.x = (move->map.x + 1.0 - (double)map->x) * move->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		move->step.y = -1;
		move->side_dist.y = ((double)map->y - move->map.y) * move->d_dist.y;
	}
	else
	{
		move->step.y = 1;
		move->side_dist.y = (move->map.y + 1.0 - (double)map->y) * move->d_dist.y;
	}
}

void		ft_start_position(t_ray *ray, t_map *map, t_move *move, t_data *data, t_pos *pos)
{
	ft_init_struct(move, ray, map);
	ft_condition_ray(ray, move, map);
	ft_move_square(move, map);
	ft_pxl_tofill(move, ray, data, map);
	ft_color_asign(map, move);
	if (move->side == 1)
	{
		map->color.r /= 2;
		map->color.g /= 2;
		map->color.b /= 2;
	}
	ft_verline(data, move, pos, map);	
}

int			ft_affichage(t_map *map, t_data *data, t_pos *pos)
{
	t_ray		*ray;
	t_move		*move;

	move = ft_calloc_2(sizeof(t_move));
	ray = ft_calloc_2(sizeof(t_ray));
	while (pos->x < data->width)
	{
		// calculate ray position & direction
		pos->camera.x = 2 * (double)pos->x / (double)data->width - 1; //x coordinate in camera space
		ray->dir.x = pos->dir.x + pos->plane_cam.x * pos->camera.x;
		ray->dir.y = pos->dir.y + pos->plane_cam.y * pos->camera.x;
		ft_start_position(ray, map, move, data, pos);
		pos->x++;
	}
	//printf("VALEUR  = [%f]\n\n", ray->dir.y);
	return (1);
}
