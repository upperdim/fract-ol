/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 07:48:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(int argc, char *argv[], t_frac *frac)
{
	parse_args(argc, argv, frac);
	if (frac->type == FRAC_JULIA_INT)
	{
		frac->scr_w = 640;
		frac->scr_h = 480;
	}
	else
	{
		frac->scr_w = SCREEN_WIDTH;
		frac->scr_h = SCREEN_HEIGHT;
	}
	frac->window = mlx_init(frac->scr_w, frac->scr_h, "fract-ol", false);
	if (frac->window == NULL)
		exit_error_mlx(frac, mlx_strerror(mlx_errno));
	frac->img = mlx_new_image(frac->window, frac->scr_w, frac->scr_h);
	if (frac->img == NULL)
		exit_error_mlx(frac, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(frac->window, frac->img, 0, 0) == -1)
		exit_error_mlx(frac, mlx_strerror(mlx_errno));
	frac->zoom_factor = ZOOM_FACTOR;
	frac->move_factor = MOVE_FACTOR;
	frac_init(frac);
}

int	main(int argc, char *argv[])
{
	t_frac	frac;

	init(argc, argv, &frac);
	frac_draw(&frac);
	if (frac.type == FRAC_JULIA_INT)
		mlx_cursor_hook(frac.window, handler_mouse_move, &frac);
	else
		mlx_scroll_hook(frac.window, &handler_mouse, &frac);
	mlx_key_hook(frac.window, &handler_keyboard, &frac);
	mlx_loop(frac.window);
	mlx_terminate(frac.window);
	return (0);
}
