/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:07:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/21 22:47:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double max(double a, double b)
{
	if (a > b)
		return a;
	return b;
}

/* Build 32-bit (4-byte) color integer from rgba. */
int32_t	frac_color(t_iter_escape result, t_frac *frac)
{
	if (result.iter >= frac->max_iter)
		return(color(0, 0, 0, 255));

	// Map [0, maxiter] to [0, 255]
	int brightness = mapi(result.iter, 0, frac->max_iter, 0, 255);
	return (color(brightness, brightness, brightness, 255));

	// Logarithmic scaling
	// double normalized = mapf(iter, 0, (double) frac->max_iter, 0, 0.17);
	// normalized = sqrt(normalized);
	// int brightness = (int) mapf(normalized, 0, 1, 0, 255);
	// return (color(brightness, brightness, brightness, 255));

	// Wikipedia
	// int brigthness = result.iter + 1 - log(log(result.abs_z))/log(2);
	// return (color(brigthness, brigthness, brigthness, 255));

	// Wiki method compliant way of logarithmic scaling
	// double normalized = mapf(result.iter, 0, (double) frac->max_iter, 0, 0.17);
	// normalized = sqrt(normalized);
	// int brightness = (int) mapf(normalized, 0, 1, 0, 255);
	// return (color(brightness, brightness, brightness, 255));

	// Youtube
	// double mod = sqrt(result.abs_z);
	// double smooth_iter = (double) result.iter - log2(max(1, log2(mod)));
	// return (color(smooth_iter, smooth_iter, smooth_iter, 255));
}

int	collatz_color(t_iter_escape result, t_frac *frac)
{
	if (result.iter >= frac->max_iter)
		return(color(0, 0, 0, 255));

	int x = pow((double) result.iter / (double) frac->max_iter, 0.5);
	int brightness = (int) -2650 * x * x / 21 + 6955 * x / 21 + 50;
	return (color(brightness, brightness, brightness, 255));
}
