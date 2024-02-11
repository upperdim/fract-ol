/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:56:57 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 07:55:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/* Build 32-bit (4-byte) color integer from rgba. */
int32_t color(int32_t r, int32_t g, int32_t b, int32_t alpha)
{
    return (r << 24 | g << 16 | b << 8 | alpha);
}