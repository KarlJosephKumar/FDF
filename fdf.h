/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:41 by kakumar           #+#    #+#             */
/*   Updated: 2023/01/06 11:26:18 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1220
# define WINDOW_WIDTH 860

# include <stdlib.h>
# include "mlx.h"
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

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
	double	delta_y;
	double	delta_x;
}	t_draw;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	***map;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		absx;
	int		absy;
	int		sx;
	int		sy;
}	t_map;

typedef struct s_fdf
{
	t_map	map;
	t_img	img;
	void	*mlx_ptr;
	void	*win;
}	t_fdf;

int		main(int argc, char **argv);
void	draw_vert_line(t_fdf *fdf);
void	initialize_image(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	my_mlx_line_put(t_fdf *fdf, int color);
int		exit_hook(void *param);
void	init_hooks(t_fdf *fdf);
char	***get_map(t_fdf *fdf, char **argv);
int		get_sx(t_fdf *fdf);
int		get_sy(t_fdf *fdf);
#endif