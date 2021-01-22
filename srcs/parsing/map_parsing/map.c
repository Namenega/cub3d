/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:42:01 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 15:05:22 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_map		*ft_map_asign(t_list *el, t_map *map)
{
	while (((char *)el->content)[map->j] && map->j <= map->width)
	{
		if (((char *)el->content)[map->j] == ' ')
			map->real_map[map->i][map->j] = -1;
		else if (((char *)el->content)[map->j] == '0')
			map->real_map[map->i][map->j] = 7;
		else if (((char *)el->content)[map->j] == '1')
			map->real_map[map->i][map->j] = 1;
		else if (((char *)el->content)[map->j] == '2')
			map->real_map[map->i][map->j] = 2;
		else if (((char *)el->content)[map->j] == 'N')
			map->real_map[map->i][map->j] = 3;
		else if (((char *)el->content)[map->j] == 'S')
			map->real_map[map->i][map->j] = 4;
		else if (((char *)el->content)[map->j] == 'E')
			map->real_map[map->i][map->j] = 5;
		else if (((char *)el->content)[map->j] == 'W')
			map->real_map[map->i][map->j] = 6;
		else
			map->real_map[map->i][map->j] = 8;
		map->j++;
	}
	return (map);
}

t_map		*ft_map_data(t_map *map, t_list *el)
{
	map->i = 0;
	map->j = 0;
	while (el->content && map->height > 0)
	{
		map = ft_map_asign(el, map);
		el = el->next;
		map->j = 0;
		map->height--;
		map->i++;
	}
	return (map);
}

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
	map->i = 0;
	return (map);
}

int			ft_map(t_list *el, t_data *data)
{
	t_map	*map;
	// int		**real_map;

	data->parsed = 9;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map = ft_get_map_hw(map, el, data);
	map->real_map = (int**)malloc(sizeof(int*) * map->height);
	if (!map->real_map)
		return (0);
	while (map->i < map->height)
	{
		map->real_map[map->i] = (int *)malloc(sizeof(int) * map->width);
		if (!map->real_map[map->i])
			return (0);
		map->i++;
	}
	map = ft_map_data(map, el);
	return (1);
}
