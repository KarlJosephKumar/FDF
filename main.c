/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:48:18 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/01 21:48:22 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	open_win(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (0);
	fdf->win = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (fdf->win == NULL)
	{
		free(fdf);
		return (0);
	}
	initialize_image(fdf);
	init_hooks(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	
	if (argc != 2)
	{
		ft_printf("Number of arguments is wrong.\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Invalid file");
		return (-1);
	}
	if (!get_map(&fdf, argv, fd))
	{
		ft_printf("Invalid map");
		return (-1);
	}
	open_win(&fdf);
	return (0);
}
