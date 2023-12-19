/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:10:29 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/19 17:04:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main()
{
	display 
	mlx_t*	window;

	example();
	return 0;
	window = mlx_init(SCR_W, SCR_H, "MLX42", true);
	if (window == NULL)
		exit_error(mlx_strerror(mlx_errno));
}
