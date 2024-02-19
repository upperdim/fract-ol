/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:01:16 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/19 15:04:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

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
