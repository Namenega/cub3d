/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/23 17:21:22 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Jumping to next square (or x/y direction)
*/

void		ft_move_square(t_move *move)
{
	while (move->hit == 0)
	{
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
	}
}

/*
** Calculate step and initial side_dist
*/

// void		ft_condition_ray(t_ray *ray, t_move *move, t_pos *posi)
// {
// 	if (ray->dir.x < 0)
// 	{
// 		move->step.x = -1;
// 		move->side_dist.x = (posi->pos.x - move->map.x) * move->d_dist.x;
// 	}
// 	else
// 	{
// 		move->step.x = 1;
// 		move->side_dist.x = (move->map.x + 1.0 - posi->pos.x) * move->d_dist.x;
// 	}
// 	if (ray->dir.y < 0)
// 	{
// 		move->step.y = -1;
// 		move->side_dist.y = (posi->pos.y - move->map.y) * move->d_dist.y;
// 	}
// 	else
// 	{
// 		move->step.y = 1;
// 		move->side_dist.y = (move->map.y + 1.0 - posi->pos.y) * move->d_dist.y;
// 	}
// }

// void		ft_start_position(t_pos *posi, t_ray *ray, t_map *map, t_data *data)
// {
// 	t_move		*move;

// 	move = malloc(sizeof(t_move));
// 	if (!move)
// 		return ;
// 	ft_init_move(move, posi, ray);
// 	ft_condition_ray(ray, move, posi);
// 	ft_move_square(move);
// 	//check if ray has hit a wall
// 	if (map->real_map[(int)move->map.x][(int)move->map.y] > 0)
// 		move->hit = 1;
// 	//calc the distance projected on camera direction (w/o fisheye effect)
// 	if (move->side == 0)
// 		move->perp_wall_dist = (move->map.x - posi->pos.x + (1 - move->step.x) / 2) /
// 			ray->dir.x;
// 	else
// 		move->perp_wall_dist = (move->map.y - posi->pos.y + (1 - move->step.y) / 2) /
// 			ray->dir.y;
// 	//calc height of line to draw on screen
// 	move->line_h = (int)(data->height / move->perp_wall_dist);
// 	//calc lowest and highest pixel to fill in current stripe
// 	move->draw_start = (-move->line_h / 2) + (data->height / 2);
// 	if (move->draw_start < 0)
// 		move->draw_start = 0;
// 	move->draw_end = (move->line_h / 2) + (data->height / 2);
// 	if (move->draw_end >= data->height)
// 		move->draw_end = data->height - 1;
// 	//choose wall color
	
// }

int			ft_affichage(t_data *data, t_map *map)
{
	int			i;
	t_pos		*posi;
	t_ray		*ray;

	i = 0;
	printf("----------\ntest_1\n----------\n");
	posi = (t_pos*)malloc(sizeof(t_pos));
	if (!posi)
		return (0);
	ray = (t_ray*)malloc(sizeof(t_ray));
	if (!ray)
		return (0);
	ft_init_pos_vec(posi);
	printf("----------\nmap->y = [%d]\n----------\n", map->y);
	printf("----------\nmap->x = [%d]\n----------\n", map->x);
	while (i < map->width)
	{
		posi->camera.x = 2 * (double)i / (double)map->width - 1;
		ray->dir.x = posi->dir.x + (posi->plane_cam.x * posi->camera.x);
		ray->dir.y = posi->dir.y + (posi->plane_cam.y * posi->camera.y);
		i++;
	}
	// printf("----------\nvaleur = [%f]\n----------\n", posi->dir.x);
	printf("----------\ntest_2\n----------\n");
	// ft_start_position(posi, ray, map, data);
	return (1);
}
