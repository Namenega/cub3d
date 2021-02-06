/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:40:42 by namenega          #+#    #+#             */
/*   Updated: 2021/02/06 17:44:16 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_puttab_fd(t_global *glb, int width, int height, int fd)
{
	int		i;
	int		j;

	j = height;
	while (j--)
	{
		i = -1;
		while (++i < width)
			ft_putbuf_fd((mlx_pxl_put(glb->data, i, j, glb->map->color)), 3, fd);
	}
}

void		ft_putbuf(unsigned int nb, int max, int fd)
{
	int		i;

	i = 0;
	while (i < max)
		ft_putchar_fd(nb >> (i++ * 8), fd);
}

char		*ft_save_name(char *file)
{
	char	*name;
	char	*tmp;
	int		i;

	i = 0;
	name = ft_strdup(file);
	while (strchr(name, '/'))
	{
		tmp = ft_strdup(ft_strchr(name, '/') + 1);
		free(name);
		name = tmp;
	}
	while (name[i] && name[i] != '.')
		i++;
	tmp= ft_substr(name, 0, i);
	free(name);
	name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	tmp = ft_strjoin("bmps/", name);
	free(name);
	return (tmp);
}

int			ft_save(t_data *data, char *file, t_global *glb)
{
	int		fd;
	char	*name;

	ft_affichage(glb);
	name = ft_save_name(file);
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		free(name);
		ft_free_data(data, "Error/nOpening file in WR mode failed.");
	}
	free(name);
	ft_putstr_fd("BM", fd);
	ft_putbuf(3 * data->width * data->height + 54, 8, fd);
	ft_putbuf_fd(26, 4, fd);
	ft_putbuf_fd(12, 4, fd);
	ft_putbuf_fd(data->width + (data->height << 16), 4, fd);
	ft_putbuf_fd(1 + ((8 * 3) << 16), 4, fd);
	ft_puttab_fd(glb, data->width, data->height, fd);
	close(fd);
	ft_free_data(data, "Save Succed");
	return (0);
}