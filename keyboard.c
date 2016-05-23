/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:09:11 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:09:48 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_funct(int keycode, t_ftol *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 1)
	{
		if (f->check == 1)
			f->check = 0;
		else
		 	f->check = 1;
	}
	return (0);
}

int		mouse_c(int x, int y, t_ftol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	if (f->check != 1)
	{
		f->tmp_z_i = ((double)(y - 512)) / 512;
		f->tmp_z_r = ((double)(x - 512)) / 512;
	}
	print_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int		mouse_cg(int x, int y, t_ftol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	if (f->check != 1)
	{
		f->tmp_z_i = ((double)(y - 512)) / 512;
		f->tmp_z_r = ((double)(x - 512)) / 512;
	}
	print_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
