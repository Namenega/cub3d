/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:56:51 by namenega          #+#    #+#             */
/*   Updated: 2021/02/11 16:20:43 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_init_floor_2(t_global *glb)
{
	//u_int32_t		buffer[data->height][data->width];
	// cell coord is got from the floor.x & floor.y
	glb->spr->cell.x = glb->spr->floor.x;
	glb->spr->cell.y = glb->spr->floor.y;
	// get the texture coordinate from the fractional part
	glb->spr->t.x = (TXW * (int)(glb->spr->floor.x - glb->spr->cell.x) & (TXW - 1));
	glb->spr->t.y = (TXH * (int)(glb->spr->floor.y - glb->spr->cell.y) & (TXH - 1));
	glb->spr->floor.x += glb->spr->floorstep.x;
	glb->spr->floor.y += glb->spr->floorstep.y;
	// choose txture et draw pxl
	glb->spr->checkbp = ((int)(glb->spr->cell.x + glb->spr->cell.y)) & 1;
	if (glb->spr->checkbp == 0)
		glb->spr->floor_tx = 3; //7?
	else
		glb->spr->floor_tx = 4;
	glb->spr->ceil_tx = 6;
	//glb->spr->color = truc["srcs/sprites/wood.xmp"][TXW * spr->t.y + spr->t.x];
	//buffer[pos->y][pos->x] = color;

	//glb->spr->color = truc["srcs/sprites/wood.xmp"][TXW * spr->t.y + spr->t.x];
	//buffer[data->height - pos->y - 1][pos->x] = color;
}

void		ft_init_floor(t_global *glb)
{
	//raydir for leftmost ray (x = 0) and rightmost ray (x = w)
	glb->spr->raydir0.x = glb->pos->dir.x - glb->pos->plane_cam.x;
	glb->spr->raydir0.y = glb->pos->dir.y - glb->pos->plane_cam.y;
	glb->spr->raydir1.x = glb->pos->dir.x + glb->pos->plane_cam.x;
	glb->spr->raydir1.y = glb->pos->dir.y + glb->pos->plane_cam.y;
	// curretn y position compared to the center of the screen (horizon)
	glb->spr->p = glb->pos->y - glb->data->height / 2;
	// vertical pos of camera
	glb->spr->posz = 0.5 * glb->data->height;
	// horizontal dist from the cam to the floor for current row
	glb->spr->rowdist = glb->spr->posz / glb->spr->p;
	// calculate the real world step vector we have to add for each x (parallel to camera plane)
	// adding step by step avoids multiplications with a weight in the inner loop
	glb->spr->floorstep.x = glb->spr->rowdist * (glb->spr->raydir1.x -
		glb->spr->raydir0.x) / glb->data->width;
	glb->spr->floorstep.y = glb->spr->rowdist * (glb->spr->raydir1.y -
		glb->spr->raydir0.y) / glb->data->width;
	// real world coordinates of the leftmost column. This will be updated as we step to the right.
	glb->spr->floor.x = glb->move->map.x + glb->spr->rowdist *
		glb->spr->raydir0.x;
	glb->spr->floor.y = glb->move->map.y + glb->spr->rowdist *
		glb->spr->raydir0.y;
}

void		ft_floorcast(t_global *glb)
{
	glb->spr = ft_calloc_2(sizeof(t_spr));
	glb->pos->y = glb->data->height / 2 + 1;
	//floor casting
	while (glb->pos->y < glb->data->height)
	{
		ft_init_floor(glb);
		glb->pos->x = 0;
		while (glb->pos->x < glb->data->width)
		{
			ft_init_floor_2(glb);
			glb->pos->x++;
		}
		glb->pos->y++;
	}
}