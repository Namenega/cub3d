/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:06:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/18 15:35:37 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_north(t_data *data, char *line)
{
	int		i;

	i = 0;
	if (data->path_north_verif != 0)
		ft_error_exit("Error\nThis data (NO) exists twice or more\n\
Exit Program");
	data->path_north_verif++;
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
	if (data->path_south_verif != 0)
		ft_error_exit("Error\nThis data (SO) exists twice or more\n\
Exit Program");
	data->path_south_verif++;
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
	if (data->path_west_verif != 0)
		ft_error_exit("Error\nThis data (WE) exists twice or more\n\
Exit Program");
	data->path_west_verif++;
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
	if (data->path_east_verif != 0)
		ft_error_exit("Error\nThis data (EA) exists twice or more\n\
Exit Program");
	data->path_east_verif++;
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
