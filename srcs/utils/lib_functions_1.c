/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:58:38 by namenega          #+#    #+#             */
/*   Updated: 2021/02/10 17:56:42 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** all whitespaces
*/

int			ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

/*
** atoi for overflow
*/

int			ft_atoi_2(const char *s)
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
	if (result > 2147483647)
	{
		if (compteur == -1)
			return (0);
		else
			ft_error_exit("Error\nNumber too big(R).\n\
Maximum is 2147483647");
	}
	return (result * compteur);
}

int			ft_inset(int c, char *set)
{
	while (set && *set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
** Skip what is already done + whitespaces + ',.-'
*/

int			ft_next_arg(char *l)
{
	int	i;

	i = 0;
	while (l && ft_isspace(l[i]))
		i++;
	while (l && (ft_isdigit(l[i]) || ft_inset(l[i], ".,-")))
		i++;
	return (i);
}

/*
** Skip what is already done + whitespaces + '.-'
*/

int			ft_next_arg_2(char *l)
{
	int	i;

	i = 0;
	while (l && ft_isspace(l[i]))
		i++;
	while (l && (ft_isdigit(l[i]) || ft_inset(l[i], ".-")))
		i++;
	return (i);
}
