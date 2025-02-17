/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:03:40 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 06:55:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	frac_init(t_frac *frac)
{
	if (frac->type == FRAC_MANDEL)
	{
		mandelbrot_init(frac);
	}
	else if (frac->type == FRAC_JULIA || frac->type == FRAC_JULIA_INT)
	{
		julia_init(frac);
	}
	else if (frac->type == FRAC_COLLATZ)
	{
		collatz_init(frac);
	}
	frac->color_state = COLOR_STATE_A;
}
