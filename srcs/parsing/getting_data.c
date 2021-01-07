/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:39:16 by namenega          #+#    #+#             */
/*   Updated: 2021/01/07 17:34:34 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_resolution(t_data *data, char *line)
{
	//printf("\n\nline = [%s]\n\n\n", line);
	
	data->width = ft_atoi(line);
	if (data->width > 3200)
		data->width = 3200;
	line += ft_next_arg(line);
	data->height = ft_atoi(line);
	if (data->height > 1800)
		data->height = 1800;

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
	data->sprite = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	while (line[i] >= 33 && line[i] <= 126)
		data->sprite[j++] = line[i++];
	data->sprite[j] = '\0';
	
	if (data->sprite == NULL)
		return (0);
	else
		return (1);
}


//printf("\n\nline = [%s]\n\n\n", line);
//printf("\n\ndata->width = [%d]\n\n\n", data->width);
//printf("\n\ndata->height = [%d]\n\n\n", data->height);
//printf("data->sprite_loop[i] = [%c]\n", data->sprite[i]);
//printf("data->sprite_loop = [%s]\n\n\n", data->sprite);