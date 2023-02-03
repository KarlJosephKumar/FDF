/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/31 18:13:43 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_all(void)
{
	exit (0);
}
int	keyhooks(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 1L<<0, close_all, fdf);
	mlx_hook(fdf->win, 2, 1L<<0, keyhooks, fdf);
}
