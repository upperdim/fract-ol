/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:44:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/11 07:43:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	extra_param_check(int argc, int max_allowed_arg_count)
{
	if (argc > max_allowed_arg_count)
	{
		ft_printf("Error: extra parameters detected.\n");
		print_usage();
		exit(EXIT_SUCCESS);
	}
}

static void	args_handle_mandelbrot(int argc, char *argv[], t_frac *frac)
{
	extra_param_check(argc, 2);
	frac->type = FRAC_MANDEL;
}

static void	args_handle_julia(int argc, char *argv[], t_frac *frac)
{
	extra_param_check(argc, 4);
	frac->type = FRAC_JULIA;
}

static void	args_handle_burningship(int argc, char *argv[], t_frac *frac)
{
	extra_param_check(argc, 2);
	frac->type = FRAC_BURN;
}

void	parse_args(int argc, char *argv[], t_frac *frac)
{
	if (argc < 2)
	{
		print_usage();
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "m", ft_strlen(argv[1])) == 0)
		args_handle_mandelbrot(argc, argv, frac);
	else if (ft_strncmp(argv[1], "j", ft_strlen(argv[1])) == 0)
		args_handle_julia(argc, argv, frac);
	else if (ft_strncmp(argv[1], "b", ft_strlen(argv[1])) == 0)
		args_handle_burningship(argc, argv, frac);
	else
	{
		ft_printf("Error: invalid parameters.\n");
		print_usage();
		exit(EXIT_SUCCESS);
	}
}
