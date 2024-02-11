/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:59:48 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 06:39:29 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	is_in_set(t_frac *frac)
{
	t_complex	z;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < frac->max_iter)
	{
		complex_mult(z, z, &z);
		complex_add(z, frac->c, &z);
		if (z.real < frac->x_start || z.real > frac->x_end
			|| z.imag < frac->y_end || z.imag > frac->y_start)
		{
			return (i);
		}
		++i;
	}
	return (frac->max_iter);
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
	x = 0;
	while (x < frac->scr_w)
	{
		y = 0;
		while (y < frac->scr_h)
		{
			frac->c.real = frac->x_start + (x * frac->x_step);
			frac->c.imag = frac->y_start + (y * frac->y_step);
			if (is_in_set(frac) >= frac->max_iter)
				col = color(0xFF, 0xFF, 0xFF, 0xFF);
			else
				col = color(0x00, 0x00, 0x00, 0xFF);
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

	frac->max_iter = 1000;
	default_min_x_range = MANDEL_DEFAULT_X_END - MANDEL_DEFAULT_X_START;
	default_min_y_range = -(MANDEL_DEFAULT_Y_END - MANDEL_DEFAULT_Y_START);
	mandelbrot_adjust_coords(frac, (double) frac->scr_w / frac->scr_h, \
	default_min_x_range, default_min_y_range);
	frac->x_step = (frac->x_end - frac->x_start) / frac->scr_w;
	frac->y_step = (frac->y_end - frac->y_start) / frac->scr_h;
}
