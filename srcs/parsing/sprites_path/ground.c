/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:07 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 18:20:12 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_color_ground(t_data *data, char *line)
{
	ft_error_skyground_1(line);
	data->r_ground = ft_atoi(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->g_ground = ft_atoi(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->b_ground = ft_atoi(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_4(line);
	if (!data->r_ground || !data->g_ground || !data->b_ground)
		return (0);
	return (1);
}