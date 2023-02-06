/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:26:06 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/03 17:43:58 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *mapy, int *z)
{
	int	z1;
	int	y1;

	z1 = *z;
	y1 = *mapy;
	*mapy = y1 * cos(0.6) - z1 * sin(0.6);
	*z = y1 * sin(0.6) + z1 * cos(0.6);
}

void	rotate_y(int *mapx, int *z)
{
	int	x1;
	int	z1;

	x1 = *mapx;
	z1 = *z;
	*mapx = x1 * cos(-0.7) + z1 * sin(-0.7);
	*z = x1 * -sin(-0.7) + z1 * cos(-0.7);
}

void	rotate_z(int *mapx, int *mapy)
{
	int	x1;
	int	y1;

	x1 = *mapx;
	y1 = *mapy;
	*mapx = x1 * cos(0.6) - y1 * sin(0.6);
	*mapy = x1 * sin(0.6) + y1 * cos(0.6);
}

void	rotate(int *mapx, int *mapy, int *z)
{
	rotate_x(mapy, z);
	rotate_y(mapx, z);
	rotate_z(mapx, mapy);
}
