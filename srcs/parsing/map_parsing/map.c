/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:42:01 by namenega          #+#    #+#             */
/*   Updated: 2021/01/21 14:26:46 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_map		*ft_map_data(t_map *map, int **real_map)
{
	map->i = 0;
	map->j = 0;
	while (map->parse->content)
	{
		while (((char *)map->parse->content)[map->j])
		{
			if (((char *)map->parse->content)[map->j] == ' ')
				real_map[map->i][map->j] = -1;
			else if (((char *)map->parse->content)[map->j] == '0')
				real_map[map->i][map->j] = 7;
			else if (((char *)map->parse->content)[map->j] == '1')
				real_map[map->i][map->j] = 1;
			else if (((char *)map->parse->content)[map->j] == '2')
				real_map[map->i][map->j] = 2;
			else if (((char *)map->parse->content)[map->j] == 'N')
				real_map[map->i][map->j] = 3;
			else if (((char *)map->parse->content)[map->j] == 'S')
				real_map[map->i][map->j] = 4;
			else if (((char *)map->parse->content)[map->j] == 'E')
				real_map[map->i][map->j] = 5;
			else if (((char *)map->parse->content)[map->j] == 'W')
				real_map[map->i][map->j] = 6;
			else
				real_map[map->i][map->j] = 8;
			printf("=== map->j = %d ===\n", real_map[map->i][map->j]);
			map->j++;
		}
		map->i++;
		map->parse = map->parse->next;
		// map->parse = map->parse->next;
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
	int		**real_map;

	data->parsed = 9;
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map = ft_get_map_hw(map, el, data);
	real_map = (int**)malloc(sizeof(int*) * map->height);
	if (!real_map)
		return (0);
	while (map->i < map->height)
	{
		real_map[map->i] = (int *)malloc(sizeof(int) * map->width);
		if (!real_map[map->i])
			return (0);
		map->i++;
	}
	map->parse = el;
	map = ft_map_data(map, real_map);
	return (1);
}