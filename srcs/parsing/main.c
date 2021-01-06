/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 17:28:25 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_error_msg(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char const **av)
{
	t_data	*data;

	if (!(ac == 2 || ac == 3))
		return (ft_error_msg("Error\nTask - arguments : Wrong Number !"));
	if (!(data = ft_data((char*)av[1], (ac == 2))))
		return (ft_error_msg("Error\nTask - parsing : Fail !"));
	/* if (ac == 2)
	{

	}
	if (ac == 3 && !ft_strncmp((char*)av[2], "-save", 6))
		ft_save(data, (char*)av[1]);*/
	return (0);
}
