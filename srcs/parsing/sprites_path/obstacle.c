/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathan <Nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:57 by namenega          #+#    #+#             */
/*   Updated: 2021/01/14 15:48:14 by Nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			ft_sprite(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->path_sprite = ft_strtrim(line, " \t\v\r\f");
	/*
	** il faut open(../../sprites/pillar.png, O_RDONLY)
	*/
	while (data->path_sprite[i])
	{
		if (ft_isspace(data->path_sprite[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}
