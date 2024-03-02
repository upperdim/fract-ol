/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mult_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:58:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/23 16:24:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/* Multiply complex number `c` buy a scalar. */
t_complex	complex_mult_s(t_complex c, double scalar)
{
	t_complex	result;

	result.real = c.real * scalar;
	result.imag = c.imag * scalar;
	return (result);
}
