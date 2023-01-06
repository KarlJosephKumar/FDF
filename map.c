/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/04 09:57:33 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_columns(t_fdf *fdf, char **argv)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	fdf->map.cols = 0;
	while (get_next_line(fd) != NULL)
		fdf->map.cols++;
	close(fd);
	return (fdf->map.cols);
}

int	get_rows(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(fdf->map.map[i][j])
		j++;
	fdf->map.rows = j;
	return(fdf->map.rows);
}

char ***get_map(t_fdf *fdf, char **argv)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->map.cols = get_columns(fdf, argv);
	fdf->map.map = (char ***) malloc (sizeof(char **) * fdf->map.cols);
	if (!fdf->map.map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	while (fdf->map.cols > i)
	{
		fdf->map.map[i] = ft_split(get_next_line(fd), ' ');
		if (!fdf->map.map[i])
			return (NULL);
		i++;
	}
	fdf->map.rows = get_rows(fdf);
	return (fdf->map.map);
}
