/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 07:48:47 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/12 07:08:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	is_in_julia_set(t_frac *frac, t_complex z)
{
	int			i;

	i = 0;
	while (i < frac->max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
		{
			return (0);
		}
		complex_mult(z, z, &z);
		complex_add(z, frac->c, &z);
		
		++i;
	}
	return (1);
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
			if (is_in_julia_set(frac, z_initial))
				col = color(0xFF, 0xFF, 0xFF, 0xFF);
			else
				col = color(0x00, 0x00, 0x00, 0xFF);
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
	frac->c.real = -0.7;
	frac->c.imag = 0.27015;
}
