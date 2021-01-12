/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:42:59 by namenega          #+#    #+#             */
/*   Updated: 2021/01/12 18:56:11 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_error_resolution_3(char *line)
{
	int	i;

	i = 0;
	if (line[i])
	{
		while (line[i])
		{
			if (!ft_isspace(line[i]))
				ft_error_exit("Error\nTask - Resolution parsing : too many arguments !\nExit Program");
			i++;
		}

	}
}

void	ft_error_resolution_2(char *line)
{
	if (!(*line))
	  	ft_error_exit("Error\nTask - Resolution parsing : missing an argument !\nExit Program");
}

void	ft_error_resolution_1(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
			ft_error_exit("Error\nTask - Resolution parsing : Letters not allowed !\nExit Program");
		i++;
	}
}

int		ft_resolution(t_data *data, char *line)
{
	int		x;
	int		y;
	
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	ft_error_resolution_1(line);
	data->width = ft_atoi(line);
	if (data->width > x)
		data->width = x;
	printf("data->width = [%d]\n\n\n", data->width);
	line += ft_next_arg(line);
	ft_error_resolution_2(line);
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	
	data->height = ft_atoi(line);
	if (data->height > y)
		data->height = y;
	printf("data->height = [%d]\n\n\n", data->height);
	line += ft_next_arg(line);
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_resolution_3(line);
	if (!data->height || !data->width)
		return (0);
	return (1);
}
