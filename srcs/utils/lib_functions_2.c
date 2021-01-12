/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:46:58 by namenega          #+#    #+#             */
/*   Updated: 2021/01/12 17:08:08 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int			ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

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

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (!(tab = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
