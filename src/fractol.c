/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 06:47:50 by tunsal           ###   ########.fr       */
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

// void	move_rectangle(void *param)
// {
// 	t_frac *frac;
//
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

void	init(int argc, char *argv[], t_frac *frac)
{
	parse_args(argc, argv, frac);
	frac->scr_w = 1280;
	frac->scr_h = 720;
	mandelbrot_init(frac);
}

int	main(int argc, char *argv[])
{
	t_frac	frac;

	init(argc, argv, &frac);
	frac.window = mlx_init(frac.scr_w, frac.scr_h, "fract-ol", true);
	if (frac.window == NULL)
		exit_error(&frac, mlx_strerror(mlx_errno)); // TODO: check if ure able to print msgs upon error exit
	frac.img = mlx_new_image(frac.window, frac.scr_w, frac.scr_h);
	if (frac.img == NULL)
		exit_error(&frac, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(frac.window, frac.img, 0, 0) == -1)
		exit_error(&frac, mlx_strerror(mlx_errno));
	//mlx_loop_hook(frac.window, draw_rectangle, &frac);
	mlx_loop_hook(frac.window, mandelbrot_draw, &frac);
	//mlx_loop_hook(frac.window, move_rectangle, &frac);
	mlx_loop(frac.window);
	mlx_terminate(frac.window);
	return (0);
}
