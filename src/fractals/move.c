/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:54:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/19 14:07:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	move(t_frac *frac, int direction)
{
	double	range_x;
	double	delta_x;

	range_x = frac->x_end - frac->x_start;
	delta_x = frac->move_factor * range_x;
	if (direction == RIGHT)
	{
		frac->x_start += delta_x;
		frac->x_end += delta_x;
	}
	else if (direction == LEFT)
	{
		frac->x_start -= delta_x;
		frac->x_end -= delta_x;
	}
	else if (direction == UP)
	{
		frac->y_start += delta_x;
		frac->y_end += delta_x;
	}
	else if (direction == DOWN)
	{
		frac->y_start -= delta_x;
		frac->y_end -= delta_x;
	}
}
