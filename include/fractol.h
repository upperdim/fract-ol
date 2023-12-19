/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:31 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/19 17:06:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define FD_STDERR 2

typedef struct s_frac
{
	/* Screen width */
	unsigned int	scr_w;
	/* Screen height */
	unsigned int	scr_h;
	/* Start coordinate of x */
	double			x_start;

	double			x_end;
	double			y_start;
	double			y_end;
	double			x_step;
	double			y_step;
}	t_frac;

/* TODO: Remove me */
int32_t	example();

/* Graphics */
int32_t color(int32_t r, int32_t g, int32_t b, int32_t a);

/* Utility */
void	exit_error(const char *err_msg);

#endif