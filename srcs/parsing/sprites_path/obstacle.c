/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:57 by namenega          #+#    #+#             */
/*   Updated: 2021/01/13 18:39:01 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_error_sprite_2(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line)
		ft_error_exit("Error\nToo many arguments(S).\nExit Program");
}

int			ft_next_arg_sprite(char *l)
{
	int	i;

	i = 0;
	while (l && ft_isspace(l[i]))
		i++;
	while (l && (!ft_isspace(l[i])))
		i++;
	return (i);
}

void		ft_error_sprite_1(char *line)
{
	printf("line[0] = [%c]\n\n", line[0]);
	while (ft_isspace(*line))
		line++;
	if (*line != '.')
		ft_error_exit("Error\n1st argument is wrong(S).\nExit Program");
}

int			ft_sprite(t_data *data, char *line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sprite_1(line);
	data->path_sprite = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->path_sprite[j++] = line[i++];
	data->path_sprite[j] = '\0';
	/*
	** il faut open(../../sprites/pillar.png, O_RDONLY)
	*/
	printf("data->path_sprite = [%s]\n\n\n", data->path_sprite);
	line += ft_next_arg_sprite(line);
	printf("-----------\n\n*line = [%s]\n\n\n", line);
	ft_error_sprite_2(line);
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}
