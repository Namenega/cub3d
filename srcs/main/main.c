/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/02/26 12:14:13 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

void	ft_malloc_protect(t_global *glb)
{
	glb->map = ft_calloc_2(sizeof(t_map));
	if (!glb->map)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	glb->pos = ft_calloc_2(sizeof(t_pos));
	if (!glb->pos)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	glb->move = ft_calloc_2(sizeof(t_move));
	if (!glb->move)
		ft_error_exit("Error\nMalloc fail\nExit Program");
}

/*
** Exit Function
** system("leaks cub3D");
*/

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
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
	if (!glb)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	ft_malloc_protect(glb);
	if (!(ac == 2 || ac == 3))
		ft_error_exit("Error\nToo many/few arguments.\nExit Program");
	if (!(glb->data = ft_data((char*)av[1], (ac == 2), glb->map, glb->pos)))
		ft_error_exit("Error\nParsing : Fail\nExit Program");
	if (ac == 2 || (ac == 3 && !ft_strncmp((char*)av[2], "--save", 7)))
	{
		hook_loop(glb, ac);
		ft_free_data(glb->data, "Merci pour les services.");
	}
	if (ac == 3 && ft_strncmp((char*)av[2], "--save", 7))
		ft_error_exit("Error\nargc[3] must be '--save'\nExit Program");
	return (0);
}
