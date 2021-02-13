/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:25:37 by namenega          #+#    #+#             */
/*   Updated: 2021/02/13 16:35:15 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** path parsing (NO/SO/EA/WE) to usefull data
*/

void		ft_img(t_data *data)
{
	if (!(data->north.img = mlx_xpm_file_to_image(data->mlx_ptr, data->path_north,
		&data->north.w, &data->north.h)))
		ft_error_exit("Error\nError in texture path (NO)\nExit Program.");
	if (!(data->south.img = mlx_xpm_file_to_image(data->mlx_ptr, data->path_south,
		&data->south.w, &data->south.h)))
		ft_error_exit("Error\nError in texture path (SO)\nExit Program.");
	if (!(data->west.img = mlx_xpm_file_to_image(data->mlx_ptr, data->path_west,
		&data->west.w, &data->west.h)))
		ft_error_exit("Error\nError in texture path (WE)\nExit Program.");;
	if (!(data->east.img = mlx_xpm_file_to_image(data->mlx_ptr, data->path_east,
		&data->east.w, &data->east.h)))
		ft_error_exit("Error\nError in texture path (EA)\nExit Program.");
	data->north.addr = (int *)mlx_get_data_addr(data->north.img, &data->north.bit,
		&data->north.line_length, &data->north.endian);
	data->south.addr = (int *)mlx_get_data_addr(data->south.img, &data->south.bit,
		&data->south.line_length, &data->south.endian);
	data->west.addr = (int *)mlx_get_data_addr(data->west.img, &data->west.bit,
		&data->west.line_length, &data->west.endian);
	data->east.addr = (int *)mlx_get_data_addr(data->east.img, &data->east.bit,
		&data->east.line_length, &data->east.endian);
}

/*
** calculate value of wallX (exactly where the wall was hit)
*/

void		ft_wallx_texx(t_move *move, t_pos *pos, t_map *map, t_tex tex)
{
	if (move->side == 0)
		pos->wall.x = map->y + (move->perp_wall_dist * move->dir.y);
	else
		pos->wall.x = map->x + (move->perp_wall_dist * move->dir.x);
	pos->wall.x -= floor(pos->wall.x);
	pos->tex.x = (int)(pos->wall.x * (double)tex.w);
	if (move->side == 0 && move->dir.x > 0)
		pos->tex.x = tex.w - pos->tex.x - 1;
	if (move->side == 1 && move->dir.y < 0)
		pos->tex.x = tex.w - pos->tex.x - 1;
}

/*
** Wall texture
*/

void		ft_texture(t_pos *pos, t_map *map, t_move *move, t_data *data)
{
	t_tex	tex;

	if (move->side == 1 && move->dir.y < 0)
		tex = data->north;
	if (move->side == 1 && move->dir.y > 0)
		tex = data->south;
	if (move->side == 0 && move->dir.x < 0)
		tex = data->west;
	if (move->side == 0 && move->dir.x > 0)
		tex = data->east;
	ft_wallx_texx(move, pos, map, tex);
	pos->stept = (double)tex.h / (double)move->line_h;
	pos->texpos = (move->draw_start - data->height / 2 + move->line_h / 2)
		* pos->stept;
	pos->y = move->draw_start;
	pos->tex.y = (int)pos->texpos & (tex.h - 1);
	while (pos->y < move->draw_end)
	{
		pos->color = tex.addr[data->east.w * (int)pos->tex.y + (int)pos->tex.x];
		ft_mlx_pxl_put(data, pos->x, pos->y, pos->color);
		pos->tex.y += pos->stept;
		pos->y++;
	}
}
