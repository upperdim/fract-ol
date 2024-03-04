/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_cos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:49:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/04 17:53:14 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_complex	complex_cos(t_complex c)
{
	t_complex	result;

	result.real = cos(c.real) * cosh(c.imag);
	result.imag = -sin(c.real) * sinh(c.imag);
	return (result);
}
