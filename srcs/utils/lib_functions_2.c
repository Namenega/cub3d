/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:04:46 by namenega          #+#    #+#             */
/*   Updated: 2021/02/24 18:14:46 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

/*
** atoi for overflow and 0
*/

int			ft_atoi_3(const char *s)
{
	int					i;
	int					compteur;
	unsigned long int	result;

	i = 0;
	compteur = 1;
	result = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\f' ||
			s[i] == '\r' || s[i] == ' ' || s[i] == '\v')
		i++;
	result = ft_uli_error(s + i);
	if (result > 2147483647 || result < 1)
	{
		if (compteur == -1)
			return (0);
		else
			ft_error_exit("Error\nNumber too big/too low(R).\n\
Maximum is 2147483647");
	}
	return (result * compteur);
}
