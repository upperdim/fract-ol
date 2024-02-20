/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:44:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/20 23:24:17 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	extra_param_check(int argc, int max_allowed_arg_count)
{
	if (argc > max_allowed_arg_count)
		exit_error("Error: extra parameters detected.", EXIT_SUCCESS, TRUE);
}

static void	args_handle_mandelbrot(int argc, char *argv[], t_frac *frac)
{
	extra_param_check(argc, 2);
	frac->type = FRAC_MANDEL;
}

/* Either no params, or just 2 params. */
static void	args_handle_julia(int argc, char *argv[], t_frac *frac)
{
	frac->type = FRAC_JULIA;
	if (argc == 2)
	{
		frac->c.real = -0.835;
		frac->c.imag = -0.321;
	}
	else if (argc == 4)
	{
		frac->c.real = parse_double(argv[2]);
		frac->c.imag = parse_double(argv[3]);
	}
	else
		exit_error("Error: extra parameters detected.", EXIT_SUCCESS, TRUE);
}

static void	args_handle_burningship(int argc, char *argv[], t_frac *frac)
{
	extra_param_check(argc, 2);
	frac->type = FRAC_BURN;
}

void	parse_args(int argc, char *argv[], t_frac *frac)
{
	if (argc < 2)
		exit_error(NULL, EXIT_SUCCESS, TRUE);
	if (ft_strncmp(argv[1], "m", ft_strlen(argv[1])) == 0)
		args_handle_mandelbrot(argc, argv, frac);
	else if (ft_strncmp(argv[1], "j", ft_strlen(argv[1])) == 0)
		args_handle_julia(argc, argv, frac);
	else if (ft_strncmp(argv[1], "b", ft_strlen(argv[1])) == 0)
		args_handle_burningship(argc, argv, frac);
	else
		exit_error("Error: invalid parameters.", EXIT_SUCCESS, TRUE);
}
