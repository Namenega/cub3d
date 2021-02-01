/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:28:35 by namenega          #+#    #+#             */
/*   Updated: 2021/02/01 17:32:51 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_keypress_hook(int key, t_pos *pos)
{
	if(key == KEYCODE_ESC)
		ft_error_exit("merci monsieur\n");
	if(key == KEYCODE_RIGHTARROW)
		ft_rotate_right(pos);
	if(key == KEYCODE_LEFTARROW)
		ft_rotate_left(pos);
	return (0);
}

int		ft_exit_hook(void *x)
{
	ft_free_data(((t_data*)x), "Close Window !\n");
	ft_error_exit("Merci pour les services.");
	return (0);
}

// int		ft_key(int key, void *p)
// {
// 	if (key == 8)
// 	{
// 		if (!((t_data*)p))
// 	}
// }

int		ft_event(t_data *data, t_pos *pos)
{
	// mlx_hook(data->mlx_win, 17, 0, ft_exit_hook, (void*)data);
	// mlx_key_hook(data->mlx_win, ft_key, (void*)data);

	// mlx_loop_hook(game->display->mlx_ptr, &hook_loop, (void *)game);
	mlx_hook(data->mlx_win, XEVENT_KEYPRESS, 0, &ft_keypress_hook, (void *)pos);
	// mlx_hook(data->mlx_win, XEVENT_KEYRELEASE, 0, &hook_keyrelease, (void *)game);
	mlx_hook(data->mlx_win, XEVENT_EXIT, 0, &ft_exit_hook, (void *)data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
