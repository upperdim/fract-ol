/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:24:13 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/20 14:29:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	exit_error(char *err_msg, int exit_code, int print_usage_too)
{
	if (err_msg != NULL)
		ft_printf("%s\n", err_msg);
	if (print_usage_too)
		print_usage();
	exit(exit_code);
}
