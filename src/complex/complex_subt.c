/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_subt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/21 17:05:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_complex	complex_subt(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}
