/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:02:00 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 06:55:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	frac_draw(t_frac *frac)
{
	mlx_delete_image(frac->window, frac->img);
	frac->img = mlx_new_image(frac->window, frac->scr_w, frac->scr_h);
	mlx_image_to_window(frac->window, frac->img, 0, 0);
	if (frac->type == FRAC_MANDEL)
	{
		mandelbrot_draw(frac);
	}
	else if (frac->type == FRAC_JULIA || frac->type == FRAC_JULIA_INT)
	{
		julia_draw(frac);
	}
	else if (frac->type == FRAC_COLLATZ)
	{
		collatz_draw(frac);
	}
}
