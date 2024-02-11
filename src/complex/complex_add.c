/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:17:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/04 03:19:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	complex_add(t_complex a, t_complex b, t_complex *result)
{
	result->real = a.real + b.real;
	result->imag = a.imag + b.imag;
}
