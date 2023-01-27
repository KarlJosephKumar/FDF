/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:49:34 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/27 11:39:04 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

void my_mlx_line_put(t_fdf *fdf, int color, int z)
{
	int err;
	int	e2;

	fdf->map.absx = abs(fdf->map.x2 - fdf->map.x1);
	fdf->map.absy = abs(fdf->map.y2 - fdf->map.y1);
	fdf->map.sx = get_sx(fdf);
	fdf->map.sy = get_sy(fdf);
	err = fdf->map.absx - fdf->map.absy;
	z = 0;
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
	int z;

	i = 0;
	len = 18;
	fdf->map.x0 = (WINDOW_HEIGHT / 2.5) - (fdf->map.rows /2 * len);
	fdf->map.y0 = (WINDOW_WIDTH / 2.2) - (fdf->map.cols /2 * len);
	printf("|y0 : %i", fdf->map.y0);
	z = 0;
	while(i < fdf->map.cols +1)
	{
		j = 0;
		while(j < fdf->map.rows)
		{
			if(j+1 == fdf->map.rows)
				break;
			if (i < fdf->map.cols && j < fdf->map.rows)
				z = ft_atoi(fdf->map.map[i][j]);
			fdf->map.x1 = fdf->map.x0 + len * (j - i);
			fdf->map.y1 = fdf->map.y0 + len * (j - i) /2 - z;
			printf("|y1 : %i", fdf->map.y1);
			if (i < fdf->map.cols && j < fdf->map.rows)
			z = ft_atoi(fdf->map.map[i][j]);
			fdf->map.x2 = fdf->map.x0 + len * (j - i + 1);
			fdf->map.y2 = fdf->map.y0 + len * (j - i + 1) /2 - z;
			printf("|y2 : %i\n", fdf->map.y2);
			my_mlx_line_put(fdf, 0xFFFFFF, z);
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
	int z;
	
	i = 0;
	len = 18;
	draw_hor_line(fdf);
	fdf->map.x0 = (WINDOW_HEIGHT / 2.5) - (fdf->map.rows /2 * len) + len;
	fdf->map.y0 = (WINDOW_WIDTH / 2.2) - (fdf->map.cols /2 * len) - (len/2);
	z = 0;
	while(i < fdf->map.cols)
	{
		j = 0;
		while(j < fdf->map.rows)
		{
			z = ft_atoi(fdf->map.map[i][j]);
			fdf->map.x1 = fdf->map.x0 + len * (j - i);
			fdf->map.y1 = fdf->map.y0 + len * (j - i) /2 - z;
			if (fdf->map.map[i][j + 1])
			z = ft_atoi(fdf->map.map[i][j + 1]);
			fdf->map.x2 = fdf->map.x0 + len * (j - i -1);
			fdf->map.y2 = fdf->map.y0 + len * (j - i + 1) /2 - z;
			my_mlx_line_put(fdf, 0xFFFFFF, z);
			j++;
		}
		fdf->map.x0 += len*2;
		i++;
	}
}
