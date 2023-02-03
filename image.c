/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:39:37 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/31 17:54:16 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < WINDOW_WIDTH && x >= 0 && y < WINDOW_HEIGHT && y >= 0)
	{
		dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	initialize_image(t_fdf *fdf)
{
	fdf->img.image = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.image, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	while (draw_hor_line(fdf) == 1)
		connect_line(fdf);
	while (draw_vert_line(fdf) == 1)
		connect_line(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win, fdf->img.image, 0, 0);
}
