/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:06:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/12 17:48:46 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_north(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	data->path_north = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_north[j++] = line[i++];
	data->path_north[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	// printf("data->path_north = [%s]\n\n\n", data->path_north);
	if (data->path_north == NULL)
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
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	data->path_south = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_south[j++] = line[i++];
	data->path_south[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	// printf("data->path_south = [%s]\n\n\n", data->path_south);
	if (data->path_south == NULL)
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
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	data->path_west = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_west[j++] = line[i++];
	data->path_west[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	// printf("data->path_west = [%s]\n\n\n", data->path_west);
	if (data->path_west == NULL)
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
	// printf("-----------\n\n*line = [%s]\n\n\n", line);
	data->path_east = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_east[j++] = line[i++];
	data->path_east[j] = '\0';
	/*
	** il faut open(../../sprites/eagle.png, O_RDONLY)
	*/
	// printf("data->path_east = [%s]\n\n\n", data->path_east);
	if (data->path_east == NULL)
		return (0);
	else
		return (1);
}

