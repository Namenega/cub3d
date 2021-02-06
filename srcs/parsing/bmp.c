/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:40:42 by namenega          #+#    #+#             */
/*   Updated: 2021/02/06 15:44:31 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



int		ft_save(t_data *data, char *file, t_global *glb)
{
	int		fd;
	char	*name;

	ft_affichage(glb);
	name = ft_save_name(file);
	return (0);
}