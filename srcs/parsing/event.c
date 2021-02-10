/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:28:35 by namenega          #+#    #+#             */
/*   Updated: 2021/02/10 15:08:06 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** Releasing the key
*/

int		ft_keyrelease_hook(int key, t_global *glb)
{
	if (key == KEYCODE_ESC)
		ft_error_exit("Merci pour les services.");
	if (key == KEYCODE_W)
		ft_mvforward(glb->pos, glb->map);
	if (key == KEYCODE_S)
		ft_mvbackward(glb->pos, glb->map);
	if (key == KEYCODE_A)
		ft_mvleft(glb->pos, glb->map);
	if (key == KEYCODE_D)
		ft_mvright(glb->pos, glb->map);
	if (key == KEYCODE_RIGHTARROW)
		ft_rotate_right(glb->pos);
	if (key == KEYCODE_LEFTARROW)
		ft_rotate_left(glb->pos);
	return (0);
}

/*
** Presssing the key to move/exit
*/

int		ft_keypress_hook(int key, t_global *glb)
{
	if (key == KEYCODE_ESC)
		ft_error_exit("Merci pour les services.");
	if (key == KEYCODE_W)
		ft_mvforward(glb->pos, glb->map);
	if (key == KEYCODE_S)
		ft_mvbackward(glb->pos, glb->map);
	if (key == KEYCODE_A)
		ft_mvleft(glb->pos, glb->map);
	if (key == KEYCODE_D)
		ft_mvright(glb->pos, glb->map);
	if (key == KEYCODE_RIGHTARROW)
		ft_rotate_right(glb->pos);
	if (key == KEYCODE_LEFTARROW)
		ft_rotate_left(glb->pos);
	return (0);
}

/*
** Exit's code
*/

int		ft_exit_hook(void *x)
{
	ft_free_data(((t_data*)x), "Close Window !\n");
	ft_error_exit("Merci pour les services.");
	return (0);
}

/*
** Algo + key + img_to_window
*/

int		ft_test(t_global *glb)
{
	int key;

	key = 36;
	ft_keypress_hook(key, glb);
	ft_keyrelease_hook(key, glb);
	ft_affichage(glb);
	mlx_put_image_to_window(glb->data->mlx_ptr, glb->data->mlx_win,
		glb->data->img, 0, 0);
	return (1);
}

/*
** loop_hook & bmp
*/

int		hook_loop(t_global *glb, int ac)
{
	int		argc;

	argc = ac;
	if (argc == 2)
	{
		ft_mlx_data(glb->data);
		mlx_hook(glb->data->mlx_win, XEVENT_KEYPRESS, 0, &ft_keypress_hook,
			(void *)glb);
		mlx_hook(glb->data->mlx_win, XEVENT_KEYRELEASE, 0, &ft_keyrelease_hook,
			(void *)glb);
		mlx_hook(glb->data->mlx_win, XEVENT_EXIT, 0, &ft_exit_hook,
			(void *)glb);
		mlx_loop_hook(glb->data->mlx_ptr, &ft_test, (void *)glb);
		mlx_loop(glb->data->mlx_ptr);
	}
	if (argc == 3)
	{
		ft_mlx_data(glb->data);
		ft_affichage(glb);
		ft_save(glb);
	}
	return (1);
}
