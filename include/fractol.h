/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/20 23:36:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0

/* File descriptors */
# define FD_STDERR 2

# define DEFAULT_SCREEN_WIDTH 1000
# define DEFAULT_SCREEN_HEIGHT 1000

/* Fractal space coordinates */
# define MANDEL_DEFAULT_X_START -2.0
# define MANDEL_DEFAULT_X_END 0.8
# define MANDEL_DEFAULT_Y_START 1.0
# define MANDEL_DEFAULT_Y_END -1.0

# define JULIA_DEFAULT_X_START -2.0
# define JULIA_DEFAULT_X_END 2.0
# define JULIA_DEFAULT_Y_START 2.0
# define JULIA_DEFAULT_Y_END -2.0

# define DEFAULT_ZOOM_FACTOR 2
/* (delta_x / x_range) */
# define DEFAULT_MOVE_FACTOR 0.07

/* Direction types */
# define UP 201
# define DOWN 202
# define LEFT 203
# define RIGHT 204

/* Fractal types */
# define FRAC_MANDEL 101
# define FRAC_JULIA 102
# define FRAC_BURN 103

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_frac
{
	mlx_t			*window;
	mlx_image_t		*img;
	unsigned int	scr_w;
	unsigned int	scr_h;
	double			x_start;
	double			x_end;
	double			y_start;
	double			y_end;
	double			x_step;
	double			y_step;
	t_complex		c;
	int				max_iter;
	int				type;
	double			zoom_factor;
	double			move_factor;
}	t_frac;

typedef struct s_iter_escape
{
	double	abs_z;
	int		iter;
}	t_iter_escape;

/* TODO: Remove me */
int32_t	example(void);

/* Fractals */
void	frac_init(t_frac *frac);
void	frac_draw(t_frac *frac);
void	mandelbrot_init(t_frac *frac);
void	mandelbrot_draw(void *param);
void	julia_init(t_frac *frac);
void	julia_draw(void *param);
void	zoom(t_frac *frac, double zoom_factor, int mouse_x, int mouse_y);
void	move(t_frac *frac, int direction);

/* Graphics */
int32_t	color(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t	frac_color(t_iter_escape result, t_frac *frac);

/* Utility */
void	exit_error(char *err_msg, int exit_code, int print_usage_too);
void	exit_error_mlx(t_frac *frac, const char *err_msg);
void	parse_args(int argc, char *argv[], t_frac *frac);
double	parse_double(char *s);
char	**ft_split_e(char const *str, char separator);
void	print_usage(void);
int		str_is_numeric(char *s);
int		mapi(int val, int src_min, int src_max, int dest_min, int dest_max);
double	mapf(double val, double src_min, double src_max, double dest_min, double dest_max);

/* Controls */
void	handler_mouse(double xdelta, double ydelta, void *param);
void	handler_keyboard(mlx_key_data_t key, void *param);

/* Complex numbers */
void	complex_zero(t_complex *c);
void	complex_mult(t_complex a, t_complex b, t_complex *result);
void	complex_add(t_complex a, t_complex b, t_complex *result);

#endif