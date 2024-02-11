/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:08:30 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/10 22:09:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	complex_mult(t_complex a, t_complex b, t_complex *result)
{
	result->real = a.real * b.real - a.imag * b.imag;
	result->imag = a.real * b.imag + a.imag * b.real;
}
