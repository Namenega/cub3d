/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:06:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/08 16:44:24 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_north(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path[j++] = line[i++];
	data->path[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path == NULL)
		return (0);
	else
		return (1);
}

int		ft_south(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path[j++] = line[i++];
	data->path[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path == NULL)
		return (0);
	else
		return (1);
}

int		ft_west(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path[j++] = line[i++];
	data->path[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path == NULL)
		return (0);
	else
		return (1);
}

int		ft_east(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path[j++] = line[i++];
	data->path[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	if (data->path == NULL)
		return (0);
	else
		return (1);
}

	// printf("data->path_north = [%s]\n\n\n", data->path);
	// printf("data->path_south = [%s]\n\n\n", data->path);
	// printf("data->path_west = [%s]\n\n\n", data->path);
	// printf("data->path_east = [%s]\n\n\n", data->path);
