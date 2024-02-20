/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:02 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/19 21:01:39 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	exit_error_mlx(t_frac *frac, const char *err_msg)
{
	if (frac->window != NULL)
	{
		mlx_close_window(frac->window);
	}
	if (err_msg != NULL)
	{
		ft_putstr_fd((char *) err_msg, FD_STDERR);
		ft_putchar_fd('\n', FD_STDERR);
	}
	exit(EXIT_FAILURE);
}
