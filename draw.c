/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:49:34 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/06 14:27:43 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_line(t_fdf *fdf)
{
	init_draw(fdf);
	if (fdf->map.x1 == fdf->map.x2)
	{
		while (fdf->map.y1 != fdf->map.y2)
		{
			my_mlx_pixel_put(fdf, fdf->map.x1, fdf->map.y1, fdf->draw.color);
			fdf->map.y1 += fdf->draw.draw_y;
		}
	}
	while (fdf->map.x1 != fdf->map.x2)
	{
		while (fdf->draw.draw_start >= 1)
		{
			my_mlx_pixel_put(fdf, fdf->map.x1, fdf->map.y1, fdf->draw.color);
			fdf->draw.draw_start--;
			fdf->map.y1 += fdf->draw.draw_y;
		}
		my_mlx_pixel_put(fdf, fdf->map.x1, fdf->map.y1, fdf->draw.color);
		fdf->draw.draw_start += fdf->draw.amount_to_draw;
		fdf->map.x1 += fdf->draw.draw_x;
	}
}

void	calculate_vert(t_fdf *fdf, int curr_x, int curr_y)
{
	fdf->map.x1 = 1200 + curr_x * GRID_WIDTH / fdf->map.cols;
	fdf->map.y1 = curr_y * GRID_WIDTH / fdf->map.cols - 400;
	fdf->map.x2 = 1200 + (curr_x) * GRID_WIDTH / fdf->map.cols;
	fdf->map.y2 = (curr_y + 1) * GRID_WIDTH / fdf->map.cols - 400;
	fdf->map.z1 = fdf->map.map[curr_y][curr_x];
	fdf->map.z2 = fdf->map.map[curr_y + 1][curr_x];
	calculate_colors(fdf);
	rotate(&fdf->map.x1, &fdf->map.y1, &fdf->map.z1);
	rotate(&fdf->map.x2, &fdf->map.y2, &fdf->map.z2);
}

int	draw_vert_line(t_fdf *fdf)
{
	static int	curr_x = 0;
	static int	curr_y = 0;

	if (curr_y == fdf->map.rows - 1)
	{
		if (curr_x == fdf->map.cols)
		{
			curr_x = 0;
			curr_y = 0;
			return (0);
		}
		curr_y = 0;
		curr_x++;
	}
	if (curr_x < fdf->map.cols)
	{
		calculate_vert(fdf, curr_x, curr_y);
		curr_y++;
		return (1);
	}
	else
		return (0);
}

void	calculate_hor(t_fdf *fdf, int curr_x, int curr_y)
{
	fdf->map.mult = 1;
	fdf->map.x1 = 1200 + curr_x * GRID_WIDTH / fdf->map.cols;
	fdf->map.y1 = curr_y * GRID_WIDTH / fdf->map.cols - 400;
	fdf->map.x2 = 1200 + (curr_x + 1) * GRID_WIDTH / fdf->map.cols;
	fdf->map.y2 = (curr_y) * GRID_WIDTH / fdf->map.cols - 400;
	fdf->map.z1 = fdf->map.map[curr_y][curr_x];
	fdf->map.z2 = fdf->map.map[curr_y][curr_x + 1];
	calculate_colors(fdf);
	rotate(&fdf->map.x1, &fdf->map.y1, &fdf->map.z1);
	rotate(&fdf->map.x2, &fdf->map.y2, &fdf->map.z2);
}

int	draw_hor_line(t_fdf *fdf)
{
	static int	curr_x = 0;
	static int	curr_y = 0;

	if (curr_x == fdf->map.cols - 1)
	{
		if (curr_y == fdf->map.rows)
		{
			curr_x = 0;
			curr_y = 0;
			return (0);
		}
		curr_x = 0;
		curr_y++;
	}
	if (curr_y < fdf->map.rows)
	{
		calculate_hor(fdf, curr_x, curr_y);
		curr_x++;
		return (1);
	}
	else
		return (0);
}
