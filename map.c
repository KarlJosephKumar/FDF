/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/03 16:26:12 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_rows(t_fdf *fdf, char **argv)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	fdf->map.rows = 0;
	tmp = get_next_line(fd);
	if (tmp != NULL)
	{
		free(tmp);
		fdf->map.rows++;
	}
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			free(tmp);
			fdf->map.rows++;
		}
	}
	close(fd);
	return (fdf->map.rows);
}

int	get_cols(t_fdf *fdf, char ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	fdf->map.cols = j;
	return (fdf->map.cols);
}

void	convert_to_int(t_fdf *fdf, char ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->map.map = (int **) malloc (sizeof(int *) * fdf->map.rows);
	if (!fdf->map.map)
		return ;
	while (i < fdf->map.rows)
	{
		j = 0;
		fdf->map.map[i] = (int *) malloc (sizeof(int) * fdf->map.cols);
		if (!fdf->map.map[i])
			return ;
		while (j < fdf->map.cols)
		{
			fdf->map.map[i][j] = ft_atoi(map[i][j]);
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
	get_z_values(fdf);
}

int	**get_map(t_fdf *fdf, char **argv, int fd)
{
	int		i;
	char	*tmp;
	char	***map;

	i = 0;
	fdf->map.rows = get_rows(fdf, argv);
	map = (char ***) malloc (sizeof(char **) * fdf->map.rows);
	if (!map)
		return (NULL);
	while (fdf->map.rows > i)
	{
		tmp = get_next_line(fd);
		map[i] = ft_split(tmp, ' ');
		free(tmp);
		if (!map[i])
			return (NULL);
		i++;
	}
	fdf->map.cols = get_cols(fdf, map);
	convert_to_int(fdf, map);
	return (fdf->map.map);
}
// make get map and conv to int into 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!