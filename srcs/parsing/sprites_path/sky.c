/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:41:43 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 18:52:07 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void		ft_error_skyground_4(char *line)
// {
// 	int	i;

// 	i = 0;
// 	if (line[i])
// 	{
// 		while (line[i])
// 		{
// 			if (!ft_isspace(line[i]))
// 				ft_error_exit("Error\nToo many arguments(F/C).\nExit Program");
// 			i++;
// 		}
// 	}
// }

// void		ft_error_skyground_3(char *line)
// {
// 	if (!(*line))
// 		ft_error_exit("Error\nMissing an argument(F/C).\nExit Program");
// 	while (ft_isspace(*line) || *line == ',')
// 		line++;
// 	if (!ft_isdigit(*line))
// 		ft_error_exit("Error\nMissing an argument(F/C).\nExit Program");
// }

t_data		*ft_error_sky_2(t_data *data)
{
	if (data->r_sky_verif != 0 || data->g_sky_verif != 0 ||
data->b_sky_verif != 0)
		ft_error_exit("Error\nThis data (C) exists twice or more\n\
Exit Program");
	data->r_sky_verif++;
	data->g_sky_verif++;
	data->b_sky_verif++;
	return (data);
}

void		ft_error_skyground_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			ft_error_exit("Error\nOnly digits & whitespaces allowed(C).\n\
Exit Program");
		i++;
	}
}

/*
** We get RGB of the Cellar
*/

int			ft_color_sky(t_data *data, char *line)
{
	char	**strs;

	data->parsed++;
	ft_error_skyground_1(line);
	ft_error_sky_2(data);
	strs = split_rgb_ground(line);
	ft_error_skyground_6(strs);
	data->r_sky = ft_atoi_2(strs[0]);
	// ft_error_skyground_3(line);
	data->g_sky = ft_atoi_2(strs[1]);
	// ft_error_skyground_4(line);
	data->b_sky = ft_atoi_2(strs[2]);
	// printf("-----\ndata->r_sky = [%d]\n", data->r_sky);
	// printf("-----\ndata->g_sky = [%d]\n", data->g_sky);
	// printf("-----\ndata->b_sky = [%d]\n", data->b_sky);
	return (1);
}
