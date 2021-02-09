/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:40:42 by namenega          #+#    #+#             */
/*   Updated: 2021/02/09 18:27:20 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//-----------------------------

static void	bmp_data(t_global *glb, int fd)
{
	int			i;
	int			j;
	uint32_t	pxl;

	i = 0;
	while (i < glb->data->height)
	{
		j = 0;
		while (j < glb->data->width)
		{
			pxl = glb->data->addr[i * glb->data->line_length / 4 + j];
			if ((write(fd, &pxl, 4)) != 4)
				ft_error_exit("BMP_3");
			j++;
		}
		i++;
	}
}

static void	bmp_header(t_global *glb, int imgsize, int fd)
{
	uint8_t		header[54];
	int			filesize;

	filesize = imgsize + 54;
	ft_bzero(header, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &filesize, 4);
	ft_memcpy(header + 10, &(int){54}, 4);
	ft_memcpy(header + 14, &(int){40}, 4);
	ft_memcpy(header + 18, &glb->data->width, 4);
	ft_memcpy(header + 22, &glb->data->height, 4);
	ft_memcpy(header + 26, &(int){1}, 2);
	ft_memcpy(header + 28, &(int){32}, 2);
	ft_memcpy(header + 34, &imgsize, 4);
	if ((write(fd, header, 54)) != 54)
		ft_error_exit("bmp");
}

void		ft_save(t_global *glb)
{
	int			fd;
	int			imgsize;

	imgsize = glb->data->height * glb->data->width * 4;
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU)) < 0)
		ft_error_exit("BMP");
	bmp_header(glb, imgsize, fd);
	bmp_data(glb, fd);
	close(fd);
	fd = -1;
}
