/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:49:34 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/01 11:48:04 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

// int	draw_grid(void *mlx_ptr, void *window, t_fdf *fdf)
// {
// 	t_draw *draw;
// }

// void draw_other_line(t_fdf *fdf)
// {
// 	int pixels;
// 	t_draw draw;
// 	double	pixel_x;
// 	double 	pixel_y;
	
// 	draw.begin_x = (WINDOW_HEIGHT/ 2) - (fdf->rows * 4);
// 	draw.begin_y = (WINDOW_WIDTH / 2) - (fdf->cols * 3);
// 	draw.end_x = (WINDOW_HEIGHT / 2) - (fdf->rows * 4 *2);
// 	draw.end_y = (WINDOW_WIDTH / 2) - (fdf->cols * 3 *2);
// 	draw.delta_x = draw.end_x - draw.begin_x;
// 	draw.delta_y = draw.end_y - draw.begin_y;
// 	pixels = 2 * draw.delta_y - draw.delta_x;
// 	pixel_x = draw.begin_x;
// 	pixel_y = draw.begin_y;
// 	while(pixel_x < draw.end_x)
// 	{
// 		if (pixels >= 0)
// 		{
// 		my_mlx_pixel_put(fdf, pixel_x, pixel_y, 0xFFFFFF);
// 		pixel_y += 1;
// 		pixels = pixels + 2 * draw.delta_y - 2 * draw.delta_x;
// 		}
// 		else
// 		{
// 		my_mlx_pixel_put(fdf, pixel_x, pixel_y, 0xFFFFFF);
// 		pixels = pixels + 2 * draw.delta_y;
// 		}
// 		pixel_x += 1;
// 	}
// }
void my_mlx_line_put(void *fdf, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;

	dx = abs(x2-x1);
	dy = abs(y2-y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	err = dx - dy;

	while(1)
	{
		my_mlx_pixel_put(fdf, x1, y1, color);
		if(x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -=dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void draw_line(t_fdf *fdf)
{
	int	len;
	int	x0;
	int y0;
	int x;
	int y;
	int i;
	int j;
	int x2;
	int y2;

	i = 0;
	j = 0;
	len = 10;
	x0 = (WINDOW_HEIGHT / 2) - (fdf->rows /2 * len);
	y0 = (WINDOW_WIDTH / 2) - (fdf->cols /2 * len);
	while(i < fdf->rows)
	{
		while(j < fdf->cols)
		{
			x = x0 + len * (j - i);
			y = y0 + len * (j - i) /2;
			x2 = x0 + len * (j - i -1);
			y2 = y0 + len * (j - i + 1) /2;
			my_mlx_line_put(fdf, x, y, x2, y2, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

// 	int pixels;
// 	t_draw draw;
// 	double	pixel_x;
// 	double 	pixel_y;
	
// 	draw_other_line(fdf);
// 	draw.begin_x = (WINDOW_HEIGHT/ 2) - (fdf->rows * 4);
// 	draw.begin_y = (WINDOW_WIDTH / 2) - (fdf->cols * 3);
// 	draw.end_x = (WINDOW_HEIGHT / 2) + (fdf->rows * 4);
// 	draw.end_y = (WINDOW_WIDTH / 2) + (fdf->cols * 3);
// 	draw.delta_x = draw.begin_x - draw.end_x;
// 	draw.delta_y = draw.begin_y - draw.end_y;
// 	pixels = 2 * draw.delta_y - draw.delta_x;
// 	pixel_x = draw.begin_x;
// 	pixel_y = draw.begin_y;
// 	while(pixel_x < draw.end_x)
// 	{
// 		if (pixels >= 0)
// 		{
// 		my_mlx_pixel_put(fdf, pixel_x, pixel_y, 0xFFFFFF);
// 		pixel_y += 1;
// 		pixels = pixels + 2 * draw.delta_y - 2 * draw.delta_x;
// 		}
// 		else
// 		{
// 		my_mlx_pixel_put(fdf, pixel_x, pixel_y, 0xFFFFFF);
// 		pixels = pixels + 2 * draw.delta_y;
// 		}
// 		pixel_x += 1;
// 	}