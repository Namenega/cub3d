/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:42:01 by namenega          #+#    #+#             */
/*   Updated: 2021/02/24 14:59:29 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
** Asigning char to int
*/

void		ft_char_to_int(t_pos *pos, t_map *map, t_list *el)
{
	if (((char *)el->content)[map->i] == ' ')
		map->real_map[map->j][map->i] = -1;
	else if (((char *)el->content)[map->i] == '0')
		map->real_map[map->j][map->i] = 7;
	else if (((char *)el->content)[map->i] == '1')
		map->real_map[map->j][map->i] = 1;
	else if (((char *)el->content)[map->i] == '2')
	{
		map->real_map[map->j][map->i] = 2;
		map->spr_x[map->numsprite] = (double)map->i + 0.5;
		map->spr_y[map->numsprite] = (double)map->j + 0.5;
		map->numsprite++;
	}
	else if (((char *)el->content)[map->i] == 'N')
		ft_position_asign(3, map, pos);
	else if (((char *)el->content)[map->i] == 'S')
		ft_position_asign(4, map, pos);
	else if (((char *)el->content)[map->i] == 'E')
		ft_position_asign(5, map, pos);
	else if (((char *)el->content)[map->i] == 'W')
		ft_position_asign(6, map, pos);
	else
		map->real_map[map->j][map->i] = 8;
}

/*
** Get characters's value of map's line
*/

t_map		*ft_map_asign(t_list *el, t_map *map, t_pos *pos)
{
	int		i;

	i = 0;
	while (((char *)el->content)[map->i])
	{
		ft_char_to_int(pos, map, el);
		map->i++;
		i++;
	}
	return (map);
}

/*
** Parsing each line of map
*/

t_map		*ft_map_data(t_map *map, t_list *el, t_pos *pos)
{
	int		i;
	t_list	*spr;

	map->position = 0;
	spr = el;
	while (spr->content && spr->next)
	{
		i = 0;
		while (((char*)spr->content)[i])
		{
			if (((char*)spr->content)[i] == '2')
				map->numsprite++;
			i++;
		}
		spr = spr->next;
	}
	ft_malloc_sprite(map);
	map->i = 0;
	map->j = 0;
	while (el->content && map->height > 0)
	{
		map = ft_map_asign(el, map, pos);
		el = el->next;
		map->i = 0;
		map->height--;
		map->j++;
	}
	return (map);
}

/*
** Get width and height's map
*/

t_map		*ft_get_map_hw(t_map *map, t_list *el, t_data *data)
{
	int		i;

	map->height = 0;
	while (el && !((char*)el->content)[0])
		el = el->next;
	while (el->content && el->next && ((char*)el->content)[0] != 0)
	{
		map->height++;
		map->i = ft_strlen(el->content);
		if (map->i > map->width)
			map->width = map->i;
		el = el->next;
	}
	while (el && !((char*)el->content)[0] && el->next)
		el = el->next;
	if (el->content && el->next && ((char*)el->content)[0] != 0)
	{
		i = 0;
		while (ft_isspace(((char*)el->content)[i]))
			i++;
		if (((char*)el->content)[i])
			ft_error_exit("Error\nToo many maps or \
a line is wrong.\nExit Program.");
		el = el->next;
	}
	el = data->first_token;
	map->height_tmp = map->height;
	map->height3 = map->height;
	map->i = 0;
	return (map);
}

/*
** Starting map parsing
*/

int			ft_map(t_list *el, t_data *data, t_map *map, t_pos *pos)
{
	data->parsed = 9;
	map = ft_get_map_hw(map, el, data);
	map->real_map = (int**)malloc(sizeof(int*) * map->height);
	if (!map->real_map)
		return (0);
	while (map->i < map->height)
	{
		map->real_map[map->i] = (int *)malloc(sizeof(int) * map->width);
		if (!map->real_map[map->i])
			return (0);
		ft_memset(map->real_map[map->i], -1, map->width * sizeof(int));
		map->i++;
	}
	map = ft_map_data(map, el, pos);
	if (map->position != 1)
		ft_error_exit("Error\nToo many/few positions or\nWhitespaces around map \
not allowed\nExit Program");
	ft_verif_map(map);
	return (1);
}
