/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:59:07 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/21 13:15:05 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_hook(void *param)
{
	(void) param;
	exit (0);
}

void init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, exit_hook, fdf);
}