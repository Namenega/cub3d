/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/01/04 18:26:36 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsing_data(char *line, t_data *data)
{
	//t_list		*lst;

	if (!line)
		return (0);
	if (line[0] == 0)
		return (1);
	if (line[0] == 'R' && ft_isspace(line[1]))
		return ();
	if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
		return ();
	if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return ();
	if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
		return ();
	if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
		return ();
}

int		ft_get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nTask - Reading File : Fail!", 1);
		return (0);
	}
	while (get_net_line(fd, &line))
	{
		ft_parsing_data(line, data);
		free(line);
	}
	free(line);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}