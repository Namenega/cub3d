/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:46:40 by namenega          #+#    #+#             */
/*   Updated: 2021/01/21 17:55:28 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vec		ft_multvec(t_vec v)
{
	t_vec	new;

	new.x = v.x * v.x;
	new.y = v.y * v.y;
	return (new);
}

t_vec		ft_divvec(t_vec v)
{
	t_vec	new;

	new.x = v.x / v.x;
	new.y = v.y / v.y;
	return (new);
}
