/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/25 20:53:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pxl_tofill(t_move *move, t_ray *ray, t_data *data, t_map *map)
{
	printf("----------\nside = [%d]\n", move->side);
	printf("----------\nmsx = [%f]\n", move->step.x);
	//calc the distance projected on camera direction (w/o fisheye effect)
	if (move->side == 0)
	{
		move->perp_wall_dist = (move->map.x - map->x + (1 - move->step.x) / 2) / ray->dir.x;
		// move->perp_wall_dist = move->side_dist.x / ray->dir.x;
	}
	else
	{
		move->perp_wall_dist = (move->map.y - map->y + (1 - move->step.y) / 2) / ray->dir.y;
		// move->perp_wall_dist = move->side_dist.y / ray->dir.y;
	}
	printf("----------\nperp_wall_dist = [%f]\n", move->perp_wall_dist);
	//calc height of line to draw on screen
	move->line_h = (int)(data->height / move->perp_wall_dist);
	//calc lowest and highest pixel to fill in current stripe
	move->draw_start = (-move->line_h / 2) + (data->height / 2);
	if (move->draw_start < 0)
		move->draw_start = 0;
	move->draw_end = (move->line_h / 2) + (data->height / 2);
	if (move->draw_end >= data->height)
		move->draw_end = data->height - 1;
}

/*
** Jumping to next square (or x/y direction)
*/

void		ft_move_square(t_move *move, t_map *map)
{
	// printf("----------\n[%d]\n----------\n", move->side);
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
		if (map->real_map[(int)move->map.y][(int)move->map.x] > 0)
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

void		ft_start_position(t_ray *ray, t_map *map, t_data *data, t_pos *pos)
{
	t_move		*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return ;
	ft_init_move(move, ray, map);
	ft_condition_ray(ray, move, map);
	ft_move_square(move, map);
	ft_pxl_tofill(move, ray, data, map);
	ft_color_asign(map, move);
	// give x/y side different brightness
	if (move->side == 1)
	{
		map->color_r /= 2;
		map->color_g /= 2;
		map->color_b /= 2;
	}
	// ft_verline(data, move, map);
	//Draw a vertical line from position x1, y to x2, y with given color.
	//It's a bit faster than using drawLine() if you need a vertical line.
	//A mettre dans srcs/utils/creer utils_2.c
	ft_time_diff(pos);
	
}

int			ft_affichage(t_map *map, t_data *data, t_pos *pos)
{
	// int			i;
	t_ray		*ray;

	// posi = 0;
	ray = (t_ray*)malloc(sizeof(t_ray));
	if (!ray)
		return (0);
	ft_init_pos_vec(pos);
	while (pos->i < data->width)
	{
		// calculate ray position & direction
		pos->camera.x = 2 * (double)pos->i / (double)data->width - 1;
		ray->dir.x = pos->dir.x + (pos->plane_cam.x * pos->camera.x);
		ray->dir.y = pos->dir.y + (pos->plane_cam.y * pos->camera.y);
		pos->i++;
	}
	printf("----------\ntest_2\n----------\n");
	ft_start_position(ray, map, data, pos);
	return (1);
}
