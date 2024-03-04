/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hsb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 07:24:03 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/04 17:59:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

// Stupidest code I've ever written
// thanks norminette https://github.com/42School/norminette
static void	place_vars2(t_hsb_colorspace_vars *cs)
{
	if (cs->h >= 3 && cs->h < 4)
	{
		cs->r_tmp = 0;
		cs->g_tmp = cs->x;
		cs->b_tmp = cs->chroma;
	}
	else if (cs->h >= 4 && cs->h < 5)
	{
		cs->r_tmp = cs->x;
		cs->g_tmp = 0;
		cs->b_tmp = cs->chroma;
	}
	else
	{
		cs->r_tmp = cs->chroma;
		cs->g_tmp = 0;
		cs->b_tmp = cs->x;
	}
}

static void	place_vars(t_hsb_colorspace_vars *cs)
{
	if (cs->h >= 0 && cs->h < 1)
	{
		cs->r_tmp = cs->chroma;
		cs->g_tmp = cs->x;
		cs->b_tmp = 0;
	}
	else if (cs->h >= 1 && cs->h < 2)
	{
		cs->r_tmp = cs->x;
		cs->g_tmp = cs->chroma;
		cs->b_tmp = 0;
	}
	else if (cs->h >= 2 && cs->h < 3)
	{
		cs->r_tmp = 0;
		cs->g_tmp = cs->chroma;
		cs->b_tmp = cs->x;
	}
	else
		place_vars2(cs);
}

/* Takes an HSB color value, returns the RGB color for MLX */
int32_t	color_hsb(int hue, int sat, int bri)
{
	t_hsb_colorspace_vars	cs;

	cs.h = (float)hue / 360.0;
	cs.s = (float)sat / 100.0;
	cs.b = (float)bri / 100.0;
	cs.h = (float)hue / 60.0f;
	cs.chroma = cs.b * cs.s;
	cs.x = cs.chroma * (1.0f - fabsf(fmodf(cs.h, 2.0f) - 1.0f));
	place_vars(&cs);
	cs.m = cs.b - cs.chroma;
	return (color((int)((cs.r_tmp + cs.m) * 255), \
	(int)((cs.g_tmp + cs.m) * 255), (int)((cs.b_tmp + cs.m) * 255), 255));
}
