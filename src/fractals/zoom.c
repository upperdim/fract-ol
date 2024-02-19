/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:54:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/19 19:38:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*
	printf("---------\n");
	printf("zoom-factor = %lf\n", zoom_factor);
	printf("mouse y = %d\n", mouse_y);
	printf("y_range = %lf\n", y_range);
	printf("h = %u\n", frac->scr_h);
	printf("yl = %lf\n", yl);
	printf("mfy = %lf\n", mfy);
	printf("new_x_range = %lf\n", new_y_range);
	printf("ys' = %lf\n", frac->y_start);
	printf("ye' = %lf\n", frac->y_end);
	printf("---------\n");
*/
static void	update_y(t_frac *frac, double zoom_factor, int mouse_y)
{
	double	yl;
	double	mfy;
	double	y_range;
	double	new_y_range;

	y_range = frac->y_end - frac->y_start;
	yl = (y_range * mouse_y) / frac->scr_h;
	mfy = frac->y_start + yl;
	new_y_range = y_range * (1 / zoom_factor);
	frac->y_start = mfy - (new_y_range / 2);
	frac->y_end = mfy + (new_y_range / 2);
}

/*
	printf("zoom-factor = %lf\n", zoom_factor);
	printf("mouse x = %d\n", mouse_x);
	printf("x_range = %lf\n", x_range);
	printf("w = %u\n", frac->scr_w);
	printf("xl = %lf\n", xl);
	printf("mfx = %lf\n", mfx);
	printf("new_x_range = %lf\n", new_x_range);
	printf("xs' = %lf\n", frac->x_start);
	printf("xe' = %lf\n", frac->x_end);
*/
static void	update_x(t_frac *frac, double zoom_factor, int mouse_x)
{
	double	xl;
	double	mfx;
	double	x_range;
	double	new_x_range;

	x_range = frac->x_end - frac->x_start;
	xl = (x_range * mouse_x) / frac->scr_w;
	mfx = frac->x_start + xl;
	new_x_range = x_range * (1 / zoom_factor);
	frac->x_start = mfx - (new_x_range / 2);
	frac->x_end = mfx + (new_x_range / 2);
}

void	zoom(t_frac *frac, double zoom_factor, int mouse_x, int mouse_y)
{
	update_x(frac, zoom_factor, mouse_x);
	update_y(frac, zoom_factor, mouse_y);
}
