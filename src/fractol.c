/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/02 20:40:40 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(int argc, char *argv[], t_frac *frac)
{
	parse_args(argc, argv, frac);
	frac->scr_w = DEFAULT_SCREEN_WIDTH;
	frac->scr_h = DEFAULT_SCREEN_HEIGHT;
	frac->window = mlx_init(frac->scr_w, frac->scr_h, "fract-ol", false);
	if (frac->window == NULL)
		exit_error_mlx(frac, mlx_strerror(mlx_errno)); // TODO: check if ure able to print msgs upon error exit
	frac->img = mlx_new_image(frac->window, frac->scr_w, frac->scr_h);
	if (frac->img == NULL)
		exit_error_mlx(frac, mlx_strerror(mlx_errno));
	if (mlx_image_to_window(frac->window, frac->img, 0, 0) == -1)
		exit_error_mlx(frac, mlx_strerror(mlx_errno));
	frac->zoom_factor = DEFAULT_ZOOM_FACTOR;
	frac->move_factor = DEFAULT_MOVE_FACTOR;
	frac_init(frac);
}

int	main(int argc, char *argv[])
{
	t_frac	frac;

	init(argc, argv, &frac);
	frac_draw(&frac);
	mlx_scroll_hook(frac.window, &handler_mouse, &frac);
	mlx_key_hook(frac.window, &handler_keyboard, &frac);
	mlx_loop(frac.window);
	mlx_terminate(frac.window);
	return (0);
}
