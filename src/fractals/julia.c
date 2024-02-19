/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 07:48:47 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/16 15:36:34 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static t_iter_escape	is_in_julia_set(t_frac *frac, t_complex z)
{
	int				i;
	t_iter_escape	result;

	i = 0;
	while (i < frac->max_iter)
	{
		complex_mult(z, z, &z);
		complex_add(z, frac->c, &z);
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break;
		++i;
	}
	result.abs_z = z.real * z.real + z.imag * z.imag;
	result.iter = i;
	return (result);
}

// printf("x_start = %lf, x_end = %lf, y_start = %lf, y_end = %lf\n", 
// frac->x_start, frac->x_end, frac->y_start, frac->y_end);
void	julia_draw(void *param)
{
	t_frac			*frac;
	unsigned int	x;
	unsigned int	y;
	int				col;
	t_complex		z_initial;

	frac = (t_frac *) param;
	x = 0;
	while (x < frac->scr_w)
	{
		y = 0;
		while (y < frac->scr_h)
		{
			z_initial.real = frac->x_start + (x * frac->x_step);
			z_initial.imag = frac->y_start + (y * frac->y_step);
			col = frac_color(is_in_julia_set(frac, z_initial), frac);
			mlx_put_pixel(frac->img, x, y, col);
			++y;
		}
		++x;
	}
}

// static void	julia_adjust_coords(t_frac *frac, double aspect_ratio, \
// double default_min_x_range, double default_min_y_range)
// {
// 	// TODO: later
// }

void	julia_init(t_frac *frac)
{
	frac->x_start = JULIA_DEFAULT_X_START;
	frac->x_end = JULIA_DEFAULT_X_END;

	frac->y_start = JULIA_DEFAULT_Y_START;
	frac->y_end = JULIA_DEFAULT_Y_END;
	
	frac->x_step = (frac->x_end - frac->x_start) / frac->scr_w;
	frac->y_step = (frac->y_end -frac->y_start) / frac->scr_h;

	frac->max_iter = 100;
	// frac->c.real = -0.7;
	// frac->c.imag = 0.27015;

	// frac->c.real = -0.54;
	// frac->c.imag = 0.54;

	// frac->c.real = 0;
	// frac->c.imag = 0.8;

	frac->c.real = -0.835;
	frac->c.imag = -0.321;
}
