/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:02 by tunsal            #+#    #+#             */
/*   Updated: 2023/12/19 16:46:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	exit_error(const char *err_msg)
{
	if (err_msg != NULL)
	{
		ft_putstr_fd((char *) err_msg, FD_STDERR);
		ft_putchar_fd('\n', FD_STDERR);
	}
	exit (EXIT_FAILURE);
}