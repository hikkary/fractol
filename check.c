/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:06:03 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:06:07 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check(char *str)
{
	if (ft_strcmp("Mandelbrot", str) == 0)
		ft_mandelbrot();
	else if (ft_strcmp("Julia", str) == 0)
		ft_julia();
	else if (ft_strcmp("Fireship", str) == 0)
		ft_fs();
	else
		ft_error();
}
