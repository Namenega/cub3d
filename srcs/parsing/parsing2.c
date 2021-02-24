/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:16:38 by namenega          #+#    #+#             */
/*   Updated: 2021/02/24 16:33:34 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Start parsing map
*/

int		ft_data_parsed(t_data *data, t_pos *pos, t_map *map, t_list *el)
{
	if (data->parsed == 8)
	{
		data->first_token = el;
		return (ft_map(el, data, map, pos));
	}
	return (1);
}

/*
** Start parsing data
*/

int		ft_parsing_begin(char *line, t_data *data)
{
	if ((line)[0] == 'R' && ft_isspace((line)[1]))
		return (ft_resolution(data, &(line)[1]));
	else if ((line)[0] == 'N' && (line)[1] == 'O' && ft_isspace((line)[2]))
		return (ft_north(data, &(line)[2]));
	else if ((line)[0] == 'S' && (line)[1] == 'O' && ft_isspace((line)[2]))
		return (ft_south(data, &(line)[2]));
	else if ((line)[0] == 'W' && (line)[1] == 'E' && ft_isspace((line)[2]))
		return (ft_west(data, &(line)[2]));
	else if ((line)[0] == 'E' && (line)[1] == 'A' && ft_isspace((line)[2]))
		return (ft_east(data, &(line)[2]));
	else if ((line)[0] == 'S' && ft_isspace((line)[1]))
		return (ft_sprite(data, &(line)[1]));
	else if (((line)[0] == 'F') && ft_isspace((line)[1]))
		return (ft_color_ground(data, &(line)[1]));
	else if (((line)[0] == 'C') && ft_isspace((line)[1]))
		return (ft_color_sky(data, &(line)[1]));
	else if ((line)[0] && data->parsed < 8)
		ft_error_exit("Error\nA line is wrong.\nExit Program");
	return (0);
}
