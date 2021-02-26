/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:41:39 by namenega          #+#    #+#             */
/*   Updated: 2021/02/26 12:15:12 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libraries/cub3d.h"

/*
** parsing each character of the line until map
*/

int		ft_parsing_data(t_list *el, t_data *data, t_map *map, t_pos *pos)
{
	char	*line;
	int		i;

	line = (char *)(el->content);
	if (!(line))
		return (0);
	else if (!el->next && data->parsed < 8)
		ft_error_exit("Error\nMissing arguments or map\nExit Program");
	else if ((line)[0] == 0)
		el = el->next;
	if ((i = ft_parsing_begin(line, data)))
		return (i);
	ft_data_parsed(data, pos, map, el);
	return (1);
}

/*
** parsing each line
*/

void	ft_loop_parse(t_list *each_line, t_data *data, t_map *map, t_pos *pos)
{
	while (each_line)
	{
		ft_parsing_data(each_line, data, map, pos);
		each_line = each_line->next;
	}
}

/*
** get_next_line -> line in t_list
*/

int		ft_gnl(int fd, t_data *data, t_map *map, t_pos *pos)
{
	int		res;
	char	*line;
	t_list	*tmp;
	t_list	*each_line;

	res = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			return (0);
		ft_lstadd_back(&data->lst_line, tmp);
		res = 1;
	}
	tmp = ft_lstnew(line);
	if (!tmp)
		return (0);
	ft_lstadd_back(&data->lst_line, tmp);
	each_line = data->lst_line;
	ft_loop_parse(each_line, data, map, pos);
	return (res);
}

/*
** opening .cub
*/

int		ft_get_data(t_data *data, char *file, t_map *map, t_pos *pos)
{
	int		fd;
	int		res;

	res = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Error\nWrong File.\nExit Program");
	res = ft_gnl(fd, data, map, pos);
	close(fd);
	if (fd > 0 && res)
		return (1);
	else
		return (0);
}

/*
** mlx_init
*/

t_data	*ft_data(char *file, int ac, t_map *map, t_pos *pos)
{
	t_data	*data;

	ac = 1;
	data = ft_calloc_2(sizeof(t_data));
	if (!data)
		ft_error_exit("Error\nMalloc fail\nExit Program");
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if (!(ft_get_data(data, file, map, pos)))
		ft_free_data(data, "Error\nTask - parsing : Fail_2 !");
	ft_img(data);
	return (data);
}
