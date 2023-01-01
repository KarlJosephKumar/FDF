/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:11:41 by kakumar           #+#    #+#             */
/*   Updated: 2022/12/21 13:15:26 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_HEIGHT 1020
# define WINDOW_WIDTH 720

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

typedef struct s_fdf
{
	int		rows;
	int		cols;
	char	***map;
	t_img	img;
	void	*mlx_ptr;
	void	*win;
}				t_fdf;

int		main(int argc, char **argv);
void	draw_line(t_fdf *fdf);
void	initialize_image(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
// int		draw_grid(void *mlx_ptr, void *window, t_fdf *fdf);
int		exit_hook(void *param);
void	init_hooks(t_fdf *fdf);
int		rgb_to_int(double r, double g, double b);
char	***get_map(t_fdf *fdf, char **argv);
#endif