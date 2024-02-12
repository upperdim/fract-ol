/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:08:14 by tunsal            #+#    #+#             */
/*   Updated: 2024/02/12 06:50:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	mapi(int val, int src_min, int src_max, int dest_min, int dest_max)
{
	return ((val - src_min) * (dest_max - dest_min)) / (src_max - src_min) + dest_min;
}

double	mapf(double val, double src_min, double src_max, double dest_min, double dest_max)
{
	return ((val - src_min) * (dest_max - dest_min)) / (src_max - src_min) + dest_min;
}
