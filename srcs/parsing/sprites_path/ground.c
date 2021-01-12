/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:07 by namenega          #+#    #+#             */
/*   Updated: 2021/01/12 17:44:30 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_color_ground(t_data *data, char *line)
{
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	data->r_ground = ft_atoi(line);
	line += ft_next_arg_2(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->g_ground = ft_atoi(line);
	line += ft_next_arg_2(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->b_ground = ft_atoi(line);

	// printf("r_ground = [%d]\n\n\n", data->r_ground);
	// printf("g_ground = [%d]\n\n\n", data->g_ground);
	// printf("b_ground = [%d]\n\n\n", data->b_ground);
	if (!data->r_ground || !data->g_ground || !data->b_ground)
		return (0);
	return (1);
}