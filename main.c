/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:48:18 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/06 14:34:51 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		return (shutdown_int("Number of arguments is wrong"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (shutdown_int("Invalid file"));
	fdf.i = 0;
	get_map(&fdf, argv, fd);
	get_z_values(&fdf);
	open_win(&fdf);
	return (0);
}
