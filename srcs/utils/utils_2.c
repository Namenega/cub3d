/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:39:23 by namenega          #+#    #+#             */
/*   Updated: 2021/02/12 14:18:52 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Centering spawn position
*/

void		ft_position_asign(int c, t_map *map, t_pos *pos)
{
	map->real_map[map->j][map->i] = c;
	map->stock_c = c;
	map->x = map->j + 0.5;
	map->y = map->i + 0.5;
	ft_dir_to_vec(c, pos);
	map->real_map[map->j][map->i] = 7;
	map->position++;
}

/*
** Pixel's color
*/

void		ft_mlx_pxl_put(t_data *data, int x, int y, u_int32_t color)
{
	(void)color;
	(data->addr)[y * (data->pxl_line) + x] = color;
}

/*
** Drawing Walls (top-bottom)
*/

void		ft_verline(t_data *data, t_move *move, t_pos *pos, t_map *map)
{
	int		i;

	i = -1;
	while (++i < move->draw_start)
		ft_mlx_pxl_put(data, pos->x, i, map->colorc);
	ft_texture(pos, map, move, data);
	i = pos->y - 1;
	while (++i < data->height)
		ft_mlx_pxl_put(data, pos->x, i, map->colorf);
}

/*
** Calloc without length
*/

void		*ft_calloc_2(size_t nmemb)
{
	void	*tab;

	tab = malloc(nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb);
	return (tab);
}

/*
** Mlx settings
*/

void		ft_mlx_data(t_data *data)
{
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
		data->height, "CUB3D")) == NULL)
		ft_free_data(data, "Error\nTask - parsing : Fail_3 !");
	if ((data->img = mlx_new_image(data->mlx_ptr, data->width,
		data->height)) == NULL)
		return ;
	if ((data->addr = (int *)mlx_get_data_addr(data->img,
		&data->bits_per_pxl, &data->line_length, &data->endian)) == NULL)
		return ;
	data->pxl_line = data->line_length / (data->bits_per_pxl / 8);
}
