/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:39:16 by namenega          #+#    #+#             */
/*   Updated: 2021/01/08 18:27:17 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		ft_resolution(t_data *data, char *line)
{
	int		x;
	int		y;

	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	data->width = ft_atoi(line);
	if (data->width > x)
		data->width = x;
	line += ft_next_arg(line);
	data->height = ft_atoi(line);
	if (data->height > y)
		data->height = y;
	if (!data->height || !data->width)
		return (0);
	return (1);
}

int		ft_sprite(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	data->path_sprite = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_sprite[j++] = line[i++];
	data->path_sprite[j] = '\0';
	/*
	** il faut open(../../sprites/pillar.png, O_RDONLY)
	*/
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}

int		ft_color_groundsky(t_data *data, char *line)
{
	int i;

	i = 0;

	data->r = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->g = ft_atoi(line);
	while (*line == ft_isspace(*line) || *line == ',')
		line++;
	data->b = ft_atoi(line);
	if (!data->r || !data->g || !data->b)
		return (0);
	return (1);
}

	/*
	** printf("\n\nline = [%s]\n\n\n", line);
	** printf("data->width = [%d]\n\n\n", data->width);
	** printf("data->height = [%d]\n\n\n", data->height);
	** printf("data->path_sprite = [%s]\n\n\n", data->path_sprite);
	** printf("data->r = [%d]\n\n\n", data->r);
	** printf("data->g = [%d]\n\n\n", data->g);
	** printf("data->b = [%d]\n\n\n", data->b);
	*/
