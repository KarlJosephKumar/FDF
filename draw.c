/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:49:34 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/06 11:08:03 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

void my_mlx_line_put(t_fdf *fdf, int color)
{
	int err;
	int	e2;

	fdf->map.absx = abs(fdf->map.x2 - fdf->map.x1);
	fdf->map.absy = abs(fdf->map.y2 - fdf->map.y1);
	fdf->map.sx = get_sx(fdf);
	fdf->map.sy = get_sy(fdf);
	err = fdf->map.absx - fdf->map.absy;
	while(1)
	{
		my_mlx_pixel_put(fdf, fdf->map.x1, fdf->map.y1, color);
		if(fdf->map.x1 == fdf->map.x2 && fdf->map.y1 == fdf->map.y2)
			break;
		e2 = 2 * err;
		if (e2 > -fdf->map.absy)
		{
			err -= fdf->map.absy;
			fdf->map.x1 += fdf->map.sx;
		}
		if (e2 < fdf->map.absx)
		{
			err += fdf->map.absx;
			fdf->map.y1 += fdf->map.sy;
		}
	}
}

void draw_hor_line(t_fdf *fdf)
{
	int	len;
	int i;
	int j;

	i = 0;
	len = 18;
	fdf->map.x0 = (WINDOW_HEIGHT / 2.5) - (fdf->map.rows /2 * len);
	fdf->map.y0 = (WINDOW_WIDTH / 2.2) - (fdf->map.cols /2 * len);
	while(i < fdf->map.cols +1)
	{
		j = 0;
		while(j < fdf->map.rows)
		{
			if(j+1 == fdf->map.rows)
				break;
			fdf->map.x1 = fdf->map.x0 + len * (j - i);
			fdf->map.y1 = fdf->map.y0 + len * (j - i) /2;
			fdf->map.x2 = fdf->map.x0 + len * (j - i + 1);
			fdf->map.y2 = fdf->map.y0 + len * (j - i + 1) /2;
			my_mlx_line_put(fdf, 0xFFFFFF);
			j++;
		}
		fdf->map.x0 += len*2;
		i++;
	}
}

void draw_vert_line(t_fdf *fdf)
{
	int	len;
	int i;
	int j;

	i = 0;
	len = 18;
	draw_hor_line(fdf);
	fdf->map.x0 = (WINDOW_HEIGHT / 2.5) - (fdf->map.rows /2 * len) + len;
	fdf->map.y0 = (WINDOW_WIDTH / 2.2) - (fdf->map.cols /2 * len) - (len/2);
	while(i < fdf->map.cols)
	{
		j = 0;
		while(j < fdf->map.rows)
		{
			fdf->map.x1 = fdf->map.x0 + len * (j - i);
			fdf->map.y1 = fdf->map.y0 + len * (j - i) /2;
			fdf->map.x2 = fdf->map.x0 + len * (j - i -1);
			fdf->map.y2 = fdf->map.y0 + len * (j - i + 1) /2;
			my_mlx_line_put(fdf, 0xFFFFFF);
			j++;
		}
		fdf->map.x0 += len*2;
		i++;
	}
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