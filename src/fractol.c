/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 05:24:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// void	draw_rectangle(void *param)
// {
// 	t_frac *frac;
// 	static int color_state = 0;

// 	frac = (t_frac *) param;
// 	for (int x = 0; x < 30; ++x) {
// 		for (int y = 0; y < 60; ++y) {
// 			int col = color(0xFF, 0x00, 0xFF, 0xFF);
// 			if (color_state > 2)
// 				color_state = 0;
// 			if (color_state == 0)
// 				col = color(0xFF, 0x80, 0x00, 0xFF);
// 			else if (color_state == 1)
// 				col = color(0x00, 0xFF, 0x00, 0xFF);
// 			else if (color_state == 2)
// 				col = color(0x00, 0x00, 0xFF, 0xFF);
// 			++color_state;
// 			mlx_put_pixel(frac->img, x, y, col);
// 		}
// 	}
// }

// TODO: y ekseninin fraktal space'inin koordinatlarina dikkat et!
// alta dogru artiyor, ama fraktal space'te artidan baslayip alta dogru azaliyor falan bi bokluk cikacak
// fonksiyonlar arasi reference frame'in kararli olmasi lazim!
int	is_in_set(t_mandel *vars)
{
	t_complex	z;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	for (; i < vars->max_iter; ++i) {
		complex_mult(z, z, &z);
		complex_add(z, vars->c, &z);
		if (z.real < vars->start_x || z.real > vars->end_x || z.imag < vars->end_y || z.imag > vars->start_y) {
			return (i);
		}
	}
	return (vars->max_iter);
}

void	draw_mandelbrot(void	*param)
{
	t_frac *frac;
	frac = (t_frac *) param;

	// printf("x_start = %lf, x_end = %lf, y_start = %lf, y_end = %lf\n", frac->x_start, frac->x_end, frac->y_start, frac->y_end);
	t_mandel args;
	args.max_iter = 1000;
	args.start_x = frac->x_start;
	args.end_x = frac->x_end;
	args.start_y = frac->y_start;
	args.end_y = frac->y_end;

	for (unsigned int x = 0; x < frac->scr_w; ++x) {
		for (unsigned int y = 0; y < frac->scr_h; ++y) {
			args.c.real = frac->x_start + (x * frac->x_step);
			args.c.imag = frac->y_start + (y * frac->y_step);

			int curr_iter = is_in_set(&args);
			int col;
			if (curr_iter >= args.max_iter) {
				col = color(0xFF, 0xFF, 0xFF, 0xFF);
			} else {
				col = color(0x00, 0x00, 0x00, 0xFF);
			}
			mlx_put_pixel(frac->img, x, y, col);
		}
	}
}

// void	move_rectangle(void *param)
// {
// 	t_frac *frac;

// 	frac = (t_frac *) param;
// 	if (mlx_is_key_down(frac->window, MLX_KEY_ESCAPE))
// 		mlx_close_window(frac->window);
// 	if (mlx_is_key_down(frac->window, MLX_KEY_UP))
// 		frac->img->instances[0].y -= 5;
// 	if (mlx_is_key_down(frac->window, MLX_KEY_DOWN))
// 		frac->img->instances[0].y += 5;
// 	if (mlx_is_key_down(frac->window, MLX_KEY_LEFT))
// 		frac->img->instances[0].x -= 5;
// 	if (mlx_is_key_down(frac->window, MLX_KEY_RIGHT))
// 		frac->img->instances[0].x += 5;
// }

void	init(t_frac *frac)
{
	double new_x_range;
	double new_y_range;

	// Default ranges coming from default values
	double default_min_x_range = MANDEL_DEFAULT_X_END - MANDEL_DEFAULT_X_START;
	double default_min_y_range = -(MANDEL_DEFAULT_Y_END - MANDEL_DEFAULT_Y_START);

	// Screen resolution (will be user defined)
	frac->scr_h = 500; 
	frac->scr_w = 1000;

	// Determine new x and y ranges
	double aspect_ratio = (double) frac->scr_w / frac->scr_h;
	if (aspect_ratio > (default_min_x_range / default_min_y_range)) {
		new_y_range = default_min_y_range;
		new_x_range = aspect_ratio * new_y_range;
	} else {
		new_x_range = default_min_x_range;
		new_y_range = new_x_range / aspect_ratio;
	}

	// Set x values after shifting
	double x_shift_start_multiplier = MANDEL_DEFAULT_X_START / default_min_x_range;
	double x_shift_end_multiplier = MANDEL_DEFAULT_X_END / default_min_x_range;
	frac->x_start = new_x_range * x_shift_start_multiplier;
	frac->x_end = new_x_range * x_shift_end_multiplier;

	// Set y values
	frac->y_start = new_y_range / 2;
	frac->y_end = -new_y_range / 2;

	// Calculate incrementing steps
	frac->x_step = (frac->x_end - frac->x_start) / frac->scr_w;
	frac->y_step = (frac->y_end - frac->y_start) / frac->scr_h;
}

int	main()
{
	t_frac	frac;

	init(&frac);
	frac.window = mlx_init(frac.scr_w, frac.scr_h, "fract-ol", true);
	if (frac.window == NULL)
		exit_error(&frac, mlx_strerror(mlx_errno)); // TODO: check if ure able to print msgs upon error exit
	frac.img = mlx_new_image(frac.window, frac.scr_w, frac.scr_h);
	if (frac.img == NULL)
		exit_error(&frac, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(frac.window, frac.img, 0, 0) == -1)
		exit_error(&frac, mlx_strerror(mlx_errno));
	//mlx_loop_hook(frac.window, draw_rectangle, &frac);
	mlx_loop_hook(frac.window, draw_mandelbrot, &frac);
	//mlx_loop_hook(frac.window, move_rectangle, &frac);
	mlx_loop(frac.window);
	mlx_terminate(frac.window);
	return (0);
}
