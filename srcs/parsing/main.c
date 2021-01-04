/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/01/04 18:18:11 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	ft_get_data();
	mlx_win = mlx_new_window(mlx, 1920 /*[width]*/, 1080/*[height]*/, "Hello World!");
	mlx_loop(mlx);
	return (0);
}
