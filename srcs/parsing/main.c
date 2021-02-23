/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/02/23 15:12:38 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Exit Function
*/

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	// system("leaks cub3D");
	exit(0);
}

int		ft_error_msg(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	return (0);
}

/*
** Starting project
*/

int		main(int ac, char const **av)
{
	t_global	*glb;

	glb = ft_calloc_2(sizeof(t_global));
	glb->map = ft_calloc_2(sizeof(t_map));
	glb->pos = ft_calloc_2(sizeof(t_pos));
	glb->move = ft_calloc_2(sizeof(t_move));
	if (!(ac == 2 || ac == 3))
		ft_error_exit("Error\nToo many/few arguments.\nExit Program");
	if (!(glb->data = ft_data((char*)av[1], (ac == 2), glb->map, glb->pos)))
		ft_error_exit("Error\nParsing : Fail\nExit Program");
	if (av[2])
		glb->argv = av[2];
	if (ac == 2 || (ac == 3 && !ft_strncmp((char*)av[2], "--save", 7)))
	{
		hook_loop(glb, ac);
		ft_free_data(glb->data, "Merci pour les services.");
	}
	if (ac == 3 && ft_strncmp((char*)av[2], "--save", 7))
		ft_error_exit("Error\nargc[3] must be '--save'\nExit Program");
	return (0);
}
