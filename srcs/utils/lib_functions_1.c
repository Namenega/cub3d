/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:58:38 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 17:47:44 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int			ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

void		ft_bzero(void *b, size_t len)
{
	char *c;

	c = (char*)b;
	while (len > 0)
		c[--len] = 0;
}

int			ft_atoi(const char *s)
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
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			compteur *= -1;
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (result > 2147483648)
		return (compteur == -1 ? 0 : -1);
	return (result * compteur);
}
