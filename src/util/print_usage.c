/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:36:15 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 11:08:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	print_usage(void)
{
	ft_printf \
	("usage:\t./fract-ol <fractal type> [julia value 1] [julia value 2]\n");
	ft_printf("\t\t(julia values must be between -2 and 2)\n");
	ft_printf("fractal types: m = mandelbrot, j = julia, c = collatz \
conjecture, i = interactive julia\n");
}
