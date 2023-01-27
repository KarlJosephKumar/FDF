/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/09 17:25:30 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_columns(t_fdf *fdf, char **argv)
{
	int	fd;
	char *tmp;
	
	fd = open(argv[1], O_RDONLY);
	fdf->map.cols = 0;
	tmp = get_next_line(fd);
	if (tmp != NULL)
	{
		free(tmp);
		fdf->map.cols++;
	}
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			free(tmp);
			fdf->map.cols++;
		}
	}
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
	char *tmp;

	i = 0;
	j = 0;
	fdf->map.cols = get_columns(fdf, argv);
	fdf->map.map = (char ***) malloc (sizeof(char **) * fdf->map.cols);
	if (!fdf->map.map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	while (fdf->map.cols > i)
	{
		tmp = get_next_line(fd);
		fdf->map.map[i] = ft_split(tmp, ' ');
		free(tmp);
		if (!fdf->map.map[i])
			return (NULL);
		i++;
	}
	fdf->map.rows = get_rows(fdf);
	return (fdf->map.map);
}
