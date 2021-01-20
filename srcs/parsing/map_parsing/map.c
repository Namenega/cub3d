/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:42:01 by namenega          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:27 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_map		*ft_map_data(t_map *map, int **real_map)
{
	map->i = 0;
	// map->j = 0;
	while (map->parse->content)
	{
		while (((char *)map->parse->content)[map->i])
		{
			if (((char *)map->parse->content)[map->i] == ' ')
				real_map[map->i][map->j] = -1;
			else if (((char *)map->parse->content)[map->i] == '0')
				real_map[map->i][map->j] = 7;
			else if (((char *)map->parse->content)[map->i] == '1')
				real_map[map->i][map->j] = 1;
			else if (((char *)map->parse->content)[map->i] == '2')
				real_map[map->i][map->j] = 2;
			else if (((char *)map->parse->content)[map->i] == 'N')
				real_map[map->i][map->j] = 3;
			else if (((char *)map->parse->content)[map->i] == 'S')
				real_map[map->i][map->j] = 4;
			else if (((char *)map->parse->content)[map->i] == 'E')
				real_map[map->i][map->j] = 5;
			else if (((char *)map->parse->content)[map->i] == 'W')
				real_map[map->i][map->j] = 6;
			else
				real_map[map->i][map->j] = 8;
			map->j++;
		}
		map->parse = map->parse->next;
		map->i++;
	}
	return (map);
}

t_map		*ft_get_map_hw(t_map *map, t_list *el)
{
	map->height = 0;
	while (el->content && el->next)
	{
		map->height++;
		map->i = 0;
		while (((char *)el->content)[map->i])
		{
			printf("%c", ((char *)el->content)[map->i]);
			map->i++;
		}
		printf("\n");
		if (map->i > map->width)
			map->width = map->i;
		el = el->next;
	}
	map->i = 0;
	return (map);
}

int			ft_map(t_list *el)
{
	t_map	*map;
	int		**real_map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map = ft_get_map_hw(map, el);
	real_map = (int**)malloc(sizeof(int*) * map->height);
	if (!real_map)
		return (0);
	while (map->i < map->height)
	{
		real_map[map->i] = malloc(sizeof(int) * map->width);
		if (!real_map[map->i])
			return (0);
		map->i++;
	}
	map->parse = el;
	map = ft_map_data(map, real_map);
	return (1);
}
