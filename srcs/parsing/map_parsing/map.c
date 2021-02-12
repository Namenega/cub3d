/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:42:01 by namenega          #+#    #+#             */
/*   Updated: 2021/02/11 18:38:39 by namenega         ###   ########.fr       */
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
		map->real_map[map->j][map->i] = 2;
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
	if (i < map->height3)
		ft_error_exit("Error\ntoo many maps.\nExit Program.");
	return (map);
}

/*
** Parsing each line of map
*/

t_map		*ft_map_data(t_map *map, t_list *el, t_pos *pos)
{
	map->i = 0;
	map->j = 0;
	map->position = 0;
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
	map->height = 0;
	while (el->content && el->next)
	{
		map->height++;
		map->i = ft_strlen(el->content);
		if (map->i > map->width)
			map->width = map->i;
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
		ft_error_exit("Error\nToo many/few positions\nExit Program");
	ft_verif_map(map);
	return (1);
}
