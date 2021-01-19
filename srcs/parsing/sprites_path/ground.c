/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:07 by namenega          #+#    #+#             */
/*   Updated: 2021/01/19 17:50:45 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_error_skyground_5(t_data *data)
{
	if (data->r_sky > 255 || data->r_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->g_sky > 255 || data->g_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->b_sky > 255 || data->b_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->r_ground > 255 || data->r_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
	if (data->g_ground > 255 || data->g_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
	if (data->b_ground > 255 || data->b_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
}

t_data		*ft_error_ground(t_data *data)
{
	if (data->r_ground_verif != 0 || data->g_ground_verif != 0 ||
data->b_ground_verif != 0)
		ft_error_exit("Error\nThis data (F) exists twice or more\n\
Exit Program");
	data->r_ground_verif++;
	data->g_ground_verif++;
	data->b_ground_verif++;
	return (data);
}

/*
** We get RGB of the Floor
*/

int			ft_color_ground(t_data *data, char *line)
{
	ft_error_skyground_1(line);
	ft_error_ground(data);
	data->r_ground = ft_atoi_2(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->g_ground = ft_atoi_2(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_3(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->b_ground = ft_atoi_2(line);
	line += ft_next_arg_2(line);
	ft_error_skyground_4(line);
	if (!data->r_ground || !data->g_ground || !data->b_ground)
		return (0);
	return (1);
}
