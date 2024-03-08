/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:01:16 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 07:36:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	julia_update_c_imag(t_frac *frac, int mouse_y)
{
	frac->c.imag = frac->y_start - (((frac->y_start - frac->y_end) * mouse_y) \
	/ frac->scr_h);
}

static void	julia_update_c_real(t_frac *frac, int mouse_x)
{
	frac->c.real = frac->x_start + (((frac->x_end - frac->x_start) * mouse_x) \
	/ frac->scr_w);
}

void	handler_mouse_move(double xpos, double ypos, void *param)
{
	if (((t_frac *)param)->type == FRAC_JULIA_INT)
	{
		julia_update_c_real(((t_frac *)param), (int)xpos);
		julia_update_c_imag(((t_frac *)param), (int)ypos);
	}
	frac_draw(((t_frac *)param));
}

void	handler_mouse(double xdelta, double ydelta, void *param)
{
	t_frac	*frac;
	int32_t	mouse_x;
	int32_t	mouse_y;

	(void) xdelta;
	frac = (t_frac *) param;
	mlx_get_mouse_pos(frac->window, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(frac, 1 / frac->zoom_factor, mouse_x, mouse_y);
	else if (ydelta > 0)
		zoom(frac, frac->zoom_factor, mouse_x, mouse_y);
	frac_draw(frac);
}
