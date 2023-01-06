/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:05:43 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/04 10:09:46 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sx(t_fdf *fdf)
{
	int	sx;

	if(fdf->map.x1 < fdf->map.x2)
		sx = 1;
	else
		sx = -1;
	return (sx);		
}

int	get_sy(t_fdf *fdf)
{
	int	sy;

	if(fdf->map.y1 < fdf->map.y2)
		sy = 1;
	else
		sy = -1;
	return (sy);		
}