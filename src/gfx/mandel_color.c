/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:07:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/12 04:51:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/* Build 32-bit (4-byte) color integer from rgba. */
int32_t	mandel_color(int iter, t_frac *frac)
{
	// Map [0, maxiter] to [0, 255]
	// int brightness = mapi(iter, 0, frac->max_iter, 0, 255);
	// return (color(brightness, brightness, brightness, 255));

	// Logarithmic scaling
	double normalized = mapf(iter, 0, (double) frac->max_iter, 0, 0.17);
	normalized = sqrt(normalized);
	int brightness = (int) mapf(normalized, 0, 1, 0, 255);
	return (color(brightness, brightness, brightness, 255));
}
