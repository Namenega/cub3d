/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:41:43 by namenega          #+#    #+#             */
/*   Updated: 2021/01/12 17:48:30 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"



int		ft_color_sky(t_data *data, char *line)
{
	int	i;

	i = 0;
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			ft_error_exit("Error\nTask - Sky parsing : Not Correct\nExit Program");
		i++;
	}
	i = 0;
	data->r_sky = ft_atoi(line);
	line += ft_next_arg_2(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->g_sky = ft_atoi(line);
	line += ft_next_arg_2(line);
	while ((*line == ft_isspace(*line)) || *line == ',')
		line++;
	data->b_sky = ft_atoi(line);

	// printf("r_sky = [%d]\n\n\n", data->r_sky);
	// printf("g_sky = [%d]\n\n\n", data->g_sky);
	// printf("b_sky = [%d]\n\n\n", data->b_sky);
	if (!data->r_sky || !data->g_sky || !data->b_sky)
		return (0);
	return (1);
}
