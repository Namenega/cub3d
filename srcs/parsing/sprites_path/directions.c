/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:06:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 16:49:59 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_north(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->path_north = ft_strtrim(line, " \t\v\r\f");
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	while (data->path_north[i])
	{
		if (ft_isspace(data->path_north[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_north == NULL)
		return (0);
	else
		return (1);
}

int		ft_south(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->path_south = ft_strtrim(line, " \t\v\r\f");
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	while (data->path_south[i])
	{
		if (ft_isspace(data->path_south[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_south == NULL)
		return (0);
	else
		return (1);
}

int		ft_west(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->path_west = ft_strtrim(line, " \t\v\r\f");
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	while (data->path_west[i])
	{
		if (ft_isspace(data->path_west[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_west == NULL)
		return (0);
	else
		return (1);
}

int		ft_east(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->path_east = ft_strtrim(line, " \t\v\r\f");
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	while (data->path_east[i])
	{
		if (ft_isspace(data->path_east[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_east == NULL)
		return (0);
	else
		return (1);
}
