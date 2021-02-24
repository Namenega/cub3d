/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:34:37 by namenega          #+#    #+#             */
/*   Updated: 2021/02/24 18:12:09 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

void	ft_free_data(t_data *data, char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	free(data);
}
