/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/01/07 16:52:41 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_parsing_data(char *line, t_data *data)
{
	//t_list		*lst;

	if (!line)
		return (0);
	if (line[0] == 0)
		return (1);
	if (line[0] == 'R' && ft_isspace(line[1]))
		return (ft_resolution(data, &line[1]));
	// if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
	// 	return (ft_north(data, &line[2]));
	// if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
	// 	return (ft_south(data, &line[2]));
	// if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
	// 	return (ft_west(data, &line[2]));
	// if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
	// 	return (ft_east(data, &line[2]));
	if (line[0] == 'S' && ft_isspace(line[1]))
		return (ft_sprite(data, &line[1]));
	// if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
	// 	return (ft_color_groundsky(data, &line[1]));
	return (1);
}

int		ft_get_data(t_data *data, char *file)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	// printf("no error here (2)\n");
	if (fd < 0)
	{
		ft_putstr_fd("Error\nTask - Reading File : Fail_4!", 1);
		return (0);
	}
	// printf("no error here (3)\n");
	while (get_next_line(fd, &line))
	{
		ft_parsing_data(line, data);
		free(line);
	}
	// printf("no error here (4)\n");
	free(line);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}

t_data	*ft_data(char *file, int ac)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_bzero(data, sizeof(t_data));
	if (ac == 1)
		if ((data->mlx_ptr = mlx_init()) == NULL)
			return (0);
	// printf("no error here (1)\n");
	if (!(ft_get_data(data, file)))
	{
		// printf("no error here (5)\n");
		ft_free_data(data, "Error\nTask - parsing : Fail_1 !");
		// printf("no error here (6)\n");
	}
	if (ac == 1)
		if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
			data->height, file)) == NULL)
		{
			printf("no error here (7)\n");
			ft_free_data(data, "Error\nTask - parsing : Fail_2 !");
			printf("no error here (8)\n");
		}
	printf("no error here (9)\n");
	return (data);
}
