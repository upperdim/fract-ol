/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:59:48 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/04 17:57:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static t_iter_escape	is_in_set(t_frac *frac)
{
	t_complex		z;
	int				i;
	t_iter_escape	result;

	z = complex_zero();
	i = 0;
	while (i < frac->max_iter)
	{
		z = complex_mult(z, z);
		z = complex_add(z, frac->c);
		if ((z.real * z.real + z.imag * z.imag) > MANDEL_DEFAULT_DIVERGE_DIST)
			break ;
		++i;
	}
	result.abs_z = z.real * z.real + z.imag * z.imag;
	result.iter = i;
	return (result);
}

// printf("x_start = %lf, x_end = %lf, y_start = %lf, y_end = %lf\n", 
// frac->x_start, frac->x_end, frac->y_start, frac->y_end);
void	mandelbrot_draw(void *param)
{
	t_frac			*frac;
	unsigned int	x;
	unsigned int	y;
	int				col;

	frac = (t_frac *) param;
	frac->x_step = (frac->x_end - frac->x_start) / frac->scr_w;
	frac->y_step = (frac->y_end - frac->y_start) / frac->scr_h;
	x = 0;
	while (x < frac->scr_w)
	{
		y = 0;
		while (y < frac->scr_h)
		{
			frac->c.real = frac->x_start + (x * frac->x_step);
			frac->c.imag = frac->y_start + (y * frac->y_step);
			col = frac_color(is_in_set(frac), frac);
			mlx_put_pixel(frac->img, x, y, col);
			++y;
		}
		++x;
	}
}

static void	mandelbrot_adjust_coords(t_frac *frac, double aspect_ratio, \
double default_min_x_range, double default_min_y_range)
{
	double	new_x_range;
	double	new_y_range;
	double	x_shift_start_multiplier;
	double	x_shift_end_multiplier;

	if (aspect_ratio > (default_min_x_range / default_min_y_range))
	{
		new_y_range = default_min_y_range;
		new_x_range = aspect_ratio * new_y_range;
	}
	else
	{
		new_x_range = default_min_x_range;
		new_y_range = new_x_range / aspect_ratio;
	}
	x_shift_start_multiplier = MANDEL_DEFAULT_X_START / default_min_x_range;
	x_shift_end_multiplier = MANDEL_DEFAULT_X_END / default_min_x_range;
	frac->x_start = new_x_range * x_shift_start_multiplier;
	frac->x_end = new_x_range * x_shift_end_multiplier;
	frac->y_start = new_y_range / 2;
	frac->y_end = -new_y_range / 2;
}

void	mandelbrot_init(t_frac *frac)
{
	double	default_min_x_range;
	double	default_min_y_range;

	frac->max_iter = MANDEL_DEFAULT_MAXITER;
	default_min_x_range = MANDEL_DEFAULT_X_END - MANDEL_DEFAULT_X_START;
	default_min_y_range = -(MANDEL_DEFAULT_Y_END - MANDEL_DEFAULT_Y_START);
	mandelbrot_adjust_coords(frac, (double) frac->scr_w / frac->scr_h, \
	default_min_x_range, default_min_y_range);
	frac->x_step = (frac->x_end - frac->x_start) / frac->scr_w;
	frac->y_step = (frac->y_end - frac->y_start) / frac->scr_h;
}
