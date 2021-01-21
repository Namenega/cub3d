/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:18:13 by namenega          #+#    #+#             */
/*   Updated: 2021/01/21 19:12:41 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_condition_ray(t_ray *ray, t_move *move, t_pos *posi)
{
	if (ray->dir.x < 0)
	{
		move->step.x = -1;
		move->side_dist.x = (posi->pos.x - move->map.x) * move->d_dist.x;
	}
	else
	{
		move->step.x = 1;
		move->side_dist.x = (move->map.x + 1.0 - posi->pos.x) * move->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		move->step.y = -1;
		move->side_dist.y = (posi->pos.y - move->map.y) * move->d_dist.y;
	}
	else
	{
		move->step.y = 1;
		move->side_dist.y = (move->map.y + 1.0 - posi->pos.y) * move->d_dist.y;
	}
}

void		ft_start_position(t_pos *posi, t_ray *ray, t_map *map)
{
	t_move		*move;

	move = malloc(sizeof(move));
	if (!move)
		return (NULL);
	move->map.x = (int)posi->pos.x;
	move->map.y = (int)posi->pos.y;
	move->d_dist.x = abs(1 / ray->dir.x);
	move->d_dist.y = abs(1 / ray->dir.y);
	move->hit = 0;
	ft_condition_ray(ray, move, posi);
	// if (ray->dir.x < 0)
	// {
	// 	move->step.x = -1;
	// 	move->side_dist.x = (posi->pos.x - move->map.x) * move->d_dist.x;
	// }
	// else
	// {
	// 	move->step.x = 1;
	// 	move->side_dist.x = (move->map.x + 1.0 - posi->pos.x) * move->d_dist.x;
	// }
	// if (ray->dir.y < 0)
	// {
	// 	move->step.y = -1;
	// 	move->side_dist.y = (posi->pos.y - move->map.y) * move->d_dist.y;
	// }
	// else
	// {
	// 	move->step.y = 1;
	// 	move->side_dist.y = (move->map.y + 1.0 - posi->pos.y) * move->d_dist.y;
	// }
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
	if (map->real_map[(int)move->map.x][(int)move->map.y] > 0)
		move->hit = 1;
}

void		ft_init_pos_vec(t_pos *posi)
{
	posi->pos.x = 22;
	posi->pos.y = 12;
	posi->dir.x = -1;
	posi->dir.y = 0;
	posi->plane_cam.x = 0;
	posi->plane_cam.y = 0.66;
}

int			ft_affichage(t_data *data, t_map *map)
{
	int			i;
	t_pos		*posi;
	t_ray		*ray;

	i = 0;
	printf("test print\n");
	posi = (t_pos*)malloc(sizeof(t_pos));
	ray = (t_ray*)malloc(sizeof(t_ray));
	ft_init_pos_vec(posi);
	while (i < data->width)
	{
		posi->camera.x = 2 * (double)i / (double)data->width - 1;
		ray->dir.x = posi->dir.x + (posi->plane_cam.x * posi->camera.x);
		ray->dir.y = posi->dir.y + (posi->plane_cam.y * posi->camera.y);
		i++;
	}
	printf("----------\nvaleur = [%f]\n----------\n", posi->dir.x);
	printf("test print_2\n");
	ft_start_position(posi, ray, map);
	return (1);
}
