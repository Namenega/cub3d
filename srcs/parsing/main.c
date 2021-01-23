/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/01/23 16:03:04 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	// free(data);
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
	t_map		*map;
	// int i = 0;
	// int j = 0;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	if (!(ac == 2 || ac == 3))
		return (ft_error_msg("Error\nTask - arguments : Wrong Number !"));
	if (!(data = ft_data((char*)av[1], (ac == 2))))
		return (ft_error_msg("Error\nTask - parsing : Fail_4 !"));

	printf("data->width = [%d]\n----------\n", data->width);
	printf("data->height = [%d]\n----------\n", data->height);

	printf("data->r_sky = [%d]\n----------\n", data->r_sky);
	printf("data->g_sky = [%d]\n----------\n", data->g_sky);
	printf("data->b_sky = [%d]\n----------\n", data->b_sky);

	printf("data->r_ground = [%d]\n----------\n", data->r_ground);
	printf("data->g_ground = [%d]\n----------\n", data->g_ground);
	printf("data->b_ground = [%d]\n----------\n", data->b_ground);

	printf("data->path_sprite = [%s]\n----------\n", data->path_sprite);
	printf("data->path_north = [%s]\n----------\n", data->path_north);
	printf("data->path_south = [%s]\n----------\n", data->path_south);
	printf("data->path_west = [%s]\n----------\n", data->path_west);
	printf("data->path_east = [%s]\n----------\n", data->path_east);

	printf("[%d]", map->real_map[0][0]);
	// while (map->real_map[j])
	// {
	// 	i = 0;
	// 	while (map->real_map[j][i])
	// 	{
	// 		printf("%d",map->real_map[j][i]);
	// 		map->i++;
	// 	}
	// 	printf("\n");
	// 	j++;
	// }




	if (ac == 2)
	{
		ft_affichage(data, map);
		ft_event(data);
		ft_free_data(data, "End Of Program");
	}
	/*if (ac == 3 && !ft_strncmp((char*)av[2], "-save", 6))
		ft_save(data, (char*)av[1]);*/
	return (0);
}
