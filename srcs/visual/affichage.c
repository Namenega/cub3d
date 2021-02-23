/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/02/23 14:29:19 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** calc the distance projected on camera direction (w/o fisheye effect)
** calc height of line to draw on screen
** calc lowest and highest pixel to fill in current stripe
*/

void		ft_pxl_tofill(t_move *move, t_data *data, t_map *map)
{
	if (move->side == 0)
		move->perp_wall_dist = (move->map.x - map->x + (1 - move->step.x) / 2)
			/ move->dir.x;
	else
		move->perp_wall_dist = (move->map.y - map->y + (1 - move->step.y) / 2)
			/ move->dir.y;
	move->line_h = (int)(data->height / move->perp_wall_dist);
	move->draw_start = -move->line_h / 2 + data->height / 2;
	if (move->draw_start < 0)
		move->draw_start = 0;
	move->draw_end = move->line_h / 2 + data->height / 2;
	if (move->draw_end >= data->height)
		move->draw_end = data->height - 1;
}

/*
** Perform DDA
** Jumping to next square (or x/y direction)
** Check if ray has hit a wall
*/

void		ft_move_square(t_move *move, t_map *map)
{
	move->side = 0;
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
		if (map->real_map[(int)move->map.x][(int)move->map.y] == 1)
			move->hit = 1;
	}
}

/*
** Calculate step and initial side_dist
*/

void		ft_condition_ray(t_move *move, t_map *map)
{
	if (move->dir.x < 0)
	{
		move->step.x = -1;
		move->side_dist.x = (map->x - move->map.x) * move->d_dist.x;
	}
	else
	{
		move->step.x = 1;
		move->side_dist.x = (move->map.x + 1.0 - map->x) *
			move->d_dist.x;
	}
	if (move->dir.y < 0)
	{
		move->step.y = -1;
		move->side_dist.y = (map->y - move->map.y) * move->d_dist.y;
	}
	else
	{
		move->step.y = 1;
		move->side_dist.y = (move->map.y + 1.0 - map->y) *
			move->d_dist.y;
	}
}

void		ft_s_p(t_map *map, t_move *move, t_data *data, t_pos *pos)
{
	ft_init_struct(move, map);
	ft_condition_ray(move, map);
	ft_move_square(move, map);
	ft_pxl_tofill(move, data, map);
	ft_color_asign(map, data);
	ft_verline(data, move, pos, map);
}

/*
** Main algorythm
** calculate ray position & direction
*/

int			ft_affichage(t_global *glb)
{
	glb->pos->x = 0;
	glb->data->zbuff = ft_calloc(sizeof(double), glb->data->width);
	while (glb->pos->x < glb->data->width)
	{
		glb->pos->camera.x = 2 * (double)glb->pos->x /
			(double)glb->data->width - 1;
		glb->move->dir.x = glb->pos->dir.x + glb->pos->plane_cam.x *
			glb->pos->camera.x;
		glb->move->dir.y = glb->pos->dir.y + glb->pos->plane_cam.y *
			glb->pos->camera.x;
		ft_s_p(glb->map, glb->move, glb->data, glb->pos);
		glb->data->zbuff[glb->pos->x] = glb->move->perp_wall_dist;
		glb->pos->x++;
	}
	ft_img_sprite(glb->map, glb);
	free(glb->data->zbuff);
	return (1);
}
