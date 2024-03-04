/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_keyboard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:01:14 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/04 17:40:14 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	handler_keyboard(mlx_key_data_t key, void *param)
{
	t_frac	*frac;

	frac = (t_frac *) param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(frac->window, frac->img);
		mlx_close_window(frac->window);
		mlx_terminate(frac->window);
		exit(EXIT_SUCCESS);
	}
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move(frac, UP);
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move(frac, DOWN);
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move(frac, LEFT);
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move(frac, RIGHT);
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		change_color_state(frac);
	frac_draw(frac);
}
