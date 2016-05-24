/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:07:55 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:08:15 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr("Liste des Fractales supporte : \n");
	ft_putstr("- Julia \n");
	ft_putstr("- Mandelbrot \n");
	ft_putstr("- Fireship\n");
	exit(1);
}
