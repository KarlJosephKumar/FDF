/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:21:27 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/06 14:40:40 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_cols(t_fdf *fdf, char *tmp)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(tmp, ' ');
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	fdf->map.cols = i;
}

int	get_rows(t_fdf *fdf, char **argv)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (shutdown_int("Error opening the file in get_rows"));
	fdf->map.rows = 0;
	tmp = get_next_line(fd);
	if (tmp != NULL)
	{
		get_cols(fdf, tmp);
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

void	fill_cols(t_fdf *fdf, int fd)
{	
	char	*tmp;
	char	**split;

	fdf->j = 0;
	tmp = get_next_line(fd);
	split = ft_split(tmp, ' ');
	if (!split)
		return (shutdown("Split failed in get_map"));
	free(tmp);
	fdf->map.map[fdf->i] = (int *) malloc (sizeof(int) * fdf->map.cols);
	if (!fdf->map.map[fdf->i])
		return (shutdown("Error mallocing: fdf->map.map columns"));
	while (fdf->j < fdf->map.cols)
	{
		fdf->map.map[fdf->i][fdf->j] = ft_atoi(split[fdf->j]);
		free(split[fdf->j]);
		fdf->j++;
	}
	free(split[fdf->j]);
	free(split);
	fdf->i++;
}

void	get_map(t_fdf *fdf, char **argv, int fd)
{
	fdf->i = 0;
	fdf->map.rows = get_rows(fdf, argv);
	fdf->map.map = (int **) malloc (sizeof(int *) * fdf->map.rows);
	if (!fdf->map.map)
		return (shutdown("Error mallocing: fdf->map.map"));
	while (fdf->map.rows > fdf->i)
		fill_cols(fdf, fd);
}
