/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:45:14 by tunsal            #+#    #+#             */
/*   Updated: 2024/03/08 09:54:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int	check_string_arr_len(char **string_arr)
{
	int		len;

	len = 0;
	while (string_arr[len] != NULL)
	{
		len++;
	}
	return (len);
}

static int	is_sign_char(char c)
{
	return (c == '+' || c == '-');
}

static void	validate_number(char **num_parts)
{
	if (check_string_arr_len(num_parts) > 2)
		exit_error("Error: Invalid floating number. Multiple radix points.", \
		EXIT_SUCCESS, TRUE);
	if (ft_strlen(num_parts[0]) > 1 && !str_is_numeric(num_parts[0]))
		exit_error("Error: Invalid floating number. Integer part is not \
numeric.", EXIT_SUCCESS, TRUE);
	if (ft_strlen(num_parts[0]) == 1 && \
	(!is_sign_char(num_parts[0][0]) && !ft_isdigit(num_parts[0][0])))
		exit_error("Error: Invalid floating number. Integer part is not \
numeric.", EXIT_SUCCESS, TRUE);
	if (num_parts[1] != NULL && !str_is_numeric(num_parts[1]))
		exit_error("Error: Invalid floating number. Floating part is not \
numeric.", EXIT_SUCCESS, TRUE);
	if (num_parts[1] != NULL && !ft_isdigit(num_parts[1][0]))
		exit_error("Error: Invalid floating number. Floating part has sign.", \
		EXIT_SUCCESS, TRUE);
}

/* Parse string `s` into a double. Exit with error if `s` is invalid. */
double	parse_double(char *s)
{
	double	result;
	char	**num_parts;
	int		digit_count_after_radix;
	int		num_after_radix;

	if (ft_strlen(s) == 0)
		exit_error("Error: Invalid floating number. Number length is 0.", \
		EXIT_SUCCESS, TRUE);
	num_parts = ft_split_e(s, '.');
	validate_number(num_parts);
	result = (double) ft_atoi(num_parts[0]);
	if (num_parts[1] == NULL)
		return (result);
	num_after_radix = ft_atoi(num_parts[1]);
	digit_count_after_radix = ft_strlen(num_parts[1]);
	if (num_parts[0][0] == '-')
		result -= num_after_radix / pow(10, digit_count_after_radix);
	else
		result += num_after_radix / pow(10, digit_count_after_radix);
	return (result);
}

/*
	// Unit test for parse_double()
	int main()
	{
		printf("%lf\n", parse_double("+3.14"));
		printf("%lf\n", parse_double("-3.14"));
		printf("%lf\n", parse_double("3.14"));
		printf("%lf\n", parse_double("3"));
		printf("%lf\n", parse_double("-3"));
		printf("%lf\n", parse_double(".14"));
		printf("%lf\n", parse_double("-.14"));
		printf("%lf\n", parse_double("+.14"));
		printf("%lf\n", parse_double("...14"));
	}
*/
