/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/09 16:38:59 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_all(/*t_fdf *fdf*/)
{
	// int i;
	// int j;
	// int k;
	
	// i = 0;
	// j = 0;
	// k = 0;
	// mlx_destroy_image(fdf->mlx_ptr, fdf->win);
	// free(fdf->win);
	// free(fdf->mlx_ptr);
	// while(fdf->map.map[i])
	// {
	// 	while(fdf->map.map[i][j])
	// 	{
	// 		k = 0;
	// 		free(fdf->map.map[i][j]);
	// 		j++;
	// 	}
	// 	free(fdf->map.map[i]);
	// 	i++;
	// }
	// free(fdf->map.map);
	exit (0);
}

void init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, close_all, fdf);
}