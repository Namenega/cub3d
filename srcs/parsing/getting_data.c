/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:39:16 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 18:05:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_resolution(t_data *data, char *line)
{
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
