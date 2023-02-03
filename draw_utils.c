/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:05:43 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/01 21:25:23 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_draw(t_fdf *fdf)
{
	fdf->draw.draw_x = 1;
	fdf->draw.draw_y = 1;
	if (fdf->map.x1 > fdf->map.x2)
		fdf->draw.draw_x = -1;
	if (fdf->map.y1 > fdf->map.y2)
		fdf->draw.draw_y = -1;
	fdf->draw.amount_to_draw = (float)(fdf->map.y2 - fdf->map.y1) /	(float)(fdf->map.x2 - fdf->map.x1);
	fdf->draw.amount_to_draw = fabsf(fdf->draw.amount_to_draw);
	fdf->draw.draw_start = fdf->draw.amount_to_draw;
}

void	get_z_values(t_fdf *fdf)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	fdf->map.lowest_z = 0;
	fdf->map.highest_z = 0;
	while (i < fdf->map.rows)
	{
		j = 0;
		while (j < fdf->map.cols)
		{
			if (fdf->map.map[i][j] < fdf->map.lowest_z)
				fdf->map.lowest_z = fdf->map.map[i][j];
			if (fdf->map.map[i][j] > fdf->map.highest_z)
				fdf->map.highest_z = fdf->map.map[i][j];
			j++;
		}
		i++;
	}
}

void	calculate_colors(t_fdf *fdf)
{
		int	highz;
		int	lowz;

		highz = fdf->map.highest_z * fdf->map.mult;
		lowz = fdf->map.lowest_z * fdf->map.mult;
		fdf->map.lowest_z *= fdf->map.mult;
		if (fdf->map.z1 > fdf->map.z2 || fdf->map.z1 < fdf->map.z2)
			fdf->draw.color = 0xFFFF00;
		else if (fdf->map.z1 == highz && fdf->map.z2 == highz)
		{	fdf->draw.color = 0xFF0000;
		}
		else if ((fdf->map.z1 < 0 &&  fdf->map.z2 < 0) || (fdf->map.z1 == 0 && fdf->map.z2 < fdf->map.z1) || \
		(fdf->map.z2 == 0 && fdf->map.z1 < fdf->map.z2))
			fdf->draw.color = 0x0000FF;
		else
			fdf->draw.color = 0xFFFFFF;
}