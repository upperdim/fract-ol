/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 05:20:13 by tunsal           ###   ########.fr       */
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

# define FD_STDERR 2

# define MANDEL_DEFAULT_X_START -2.0
# define MANDEL_DEFAULT_X_END 0.8
# define MANDEL_DEFAULT_Y_START 1.0
# define MANDEL_DEFAULT_Y_END -1.0

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_mandel
{
	int			max_iter;
	t_complex	c;
	double		start_x;
	double		end_x;
	double		start_y;
	double		end_y;
}	t_mandel;

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
}	t_frac;

/* TODO: Remove me */
int32_t	example(void);

/* Graphics */
int32_t	color(int32_t r, int32_t g, int32_t b, int32_t a);

/* Utility */
void	exit_error(t_frac *frac, const char *err_msg);

/*  */
void	complex_mult(t_complex a, t_complex b, t_complex *result);
void	complex_add(t_complex a, t_complex b, t_complex *result);

#endif