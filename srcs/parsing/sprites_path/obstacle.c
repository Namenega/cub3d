/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:57 by namenega          #+#    #+#             */
/*   Updated: 2021/02/12 16:13:45 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
** path parsing (sprite) to usefull data
*/

void		ft_sprite2(t_data *data)
{
	printf("sprite = [%s]\n", data->path_sprite);
	if (!(data->sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, data->path_sprite,
		&data->sprite.w, &data->sprite.h)))
		ft_error_exit("Error\nError in texture path (S)\nExit Program.");
	data->sprite.addr = (int *)mlx_get_data_addr(data->sprite.img, &data->sprite.bit,
		&data->sprite.line_length, &data->sprite.endian);
}

/*
** We get here the string of obstacle_sprite's path
*/

int			ft_sprite(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->parsed++;
	if (data->path_sprite_verif != 0)
		ft_error_exit("Error\nThis data (S) exists twice or more\n\
Exit Program");
	data->path_sprite_verif++;
	data->path_sprite = ft_strtrim(line, " \t\v\r\f");
	while (data->path_sprite[i])
	{
		if (ft_isspace(data->path_sprite[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (i < 1)
		ft_error_exit("Error\nMissing path(S).\nExit Program");
	ft_sprite2(data);
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}
