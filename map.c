/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/20 13:46:33 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_columns(t_fdf *fdf, char **argv)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	fdf->cols = 0;
	while (get_next_line(fd) != NULL)
		fdf->cols++;
	close(fd);
	return (fdf->cols);
}

int	get_rows(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(fdf->map[i][j])
		j++;
	fdf->rows = j;
	return(fdf->rows);
}

char ***get_map(t_fdf *fdf, char **argv)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->cols = get_columns(fdf, argv);
	fdf->map = (char ***) malloc (sizeof(char **) * fdf->cols);
	if (!fdf->map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	while (fdf->cols > i)
	{
		fdf->map[i] = ft_split(get_next_line(fd), ' ');
		if (!fdf->map[i])
			return (NULL);
		i++;
	}
	fdf->rows = get_rows(fdf);
	return (fdf->map);
}
