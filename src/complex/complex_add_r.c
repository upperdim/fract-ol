/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_add_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:31:18 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/02 20:40:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/* Add a real number to a complex number `c`. */
t_complex	complex_add_r(t_complex c, double r)
{
	t_complex	result;

	result.real = c.real + r;
	result.imag = c.imag;
	return (result);
}
