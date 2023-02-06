/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:41 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/03 17:19:13 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define GRID_WIDTH 650

# include <stdlib.h>
# include "mlx.h"
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <math.h>
# include <stdio.h>
typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_draw
{
	int		begin_y;
	int		begin_x;
	int		end_y;
	int 	end_x;
	int		color;
	int		draw_x;
	int		draw_y;
	float	amount_to_draw;
	float	draw_start;
}	t_draw;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		**map;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		z1;
	int		z2;
	int		lowest_z;
	int		highest_z;
	int		mult;
}	t_map;

typedef struct s_fdf
{
	t_draw	draw;
	t_map	map;
	t_img	img;
	void	*mlx_ptr;
	void	*win;
	int		i;
	int		j;
}	t_fdf;

int		main(int argc, char **argv);
int		draw_hor_line(t_fdf *fdf);
int		draw_vert_line(t_fdf *fdf);
void	initialize_image(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		exit_hook(void *param);
void	init_hooks(t_fdf *fdf);
void	get_map(t_fdf *fdf, char **argv, int fd);
void 	init_draw(t_fdf *fdf);
void 	connect_line(t_fdf *fdf);
void	get_z_values(t_fdf *fdf);
void	rotate(int *mapx, int *mapy, int *z);
void	calculate_colors(t_fdf *fdf);
void	shutdown(char *str);
int		shutdown_int(char *str);
#endif