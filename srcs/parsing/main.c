/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/01/18 17:31:56 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int		main(int ac, char const **av)
{
	t_data		*data;

	if (!(ac == 2 || ac == 3))
		return (ft_error_msg("Error\nTask - arguments : Wrong Number !"));
	if (!(data = ft_data((char*)av[1], (ac == 2))))
		return (ft_error_msg("Error\nTask - parsing : Fail_4 !"));
	if (ac == 2)
	{
		ft_affichage(data);
		ft_event(data);
		ft_free_data(data, "End Of Program");
	}
	/*if (ac == 3 && !ft_strncmp((char*)av[2], "-save", 6))
		ft_save(data, (char*)av[1]);*/
	return (0);
}
