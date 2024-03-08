/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:07:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 07:50:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	change_color_state(t_frac *frac)
{
	if (frac->color_state == COLOR_STATE_A)
		frac->color_state = COLOR_STATE_B;
	else if (frac->color_state == COLOR_STATE_B)
		frac->color_state = COLOR_STATE_C;
	else if (frac->color_state == COLOR_STATE_C)
		frac->color_state = COLOR_STATE_A;
}

// static int32_t	julia_int_color(t_iter_escape result, t_frac *frac)
// {
// 	int	brightness;

// 	brightness = (255 * result.iter) / frac->max_iter;
// 	return (color(brightness, brightness, brightness, 255));
// }

int32_t	frac_color(t_iter_escape result, t_frac *frac)
{
	int		factor;
	float	hue;

	if (result.iter >= frac->max_iter)
		return (color(0, 0, 0, 255));
	if (frac->type == FRAC_JULIA_INT)
		factor = JULIA_INT_COLOR_FACTOR;
	else if (frac->type == FRAC_MANDEL)
		factor = MANDEL_COLOR_FACTOR;
	else if (frac->type == FRAC_JULIA)
		factor = JULIA_COLOR_FACTOR;
	else
		factor = COLLATZ_COLOR_FACTOR;
	hue = (int)(factor * (float) result.iter / frac->max_iter);
	if (frac->color_state == COLOR_STATE_A)
		hue = (int)(hue + 0) % 360;
	if (frac->color_state == COLOR_STATE_B)
		hue = (int)(hue + 90) % 360;
	else if (frac->color_state == COLOR_STATE_C)
		hue = (int)(hue + 250) % 360;
	return (color_hsb(hue, 100, 100));
}
