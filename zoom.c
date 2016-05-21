/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:10:40 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:10:43 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom(int button, int x, int y, t_ftol *f)
{
	double	tz_x;
	double	tz_y;

	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	tz_x = f->zoom_x;
	tz_y = f->zoom_y;
	if (button == 5)
	{
		f->zoom_x = f->zoom_x * 2;
		f->zoom_y = f->zoom_y * 2;
		f->it_max += 10;
	}
	if (button == 4)
	{
		f->zoom_x = f->zoom_x / 2;
		f->zoom_y = f->zoom_y / 2;
		f->it_max -= 10;
	}
	f->x1_tmp += x / tz_x - (x / f->zoom_x);
	f->y1_tmp += y / tz_y - (y / f->zoom_y);
	print_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int		zoom_m(int button, int x, int y, t_ftol *f)
{
	double	tz_x;
	double	tz_y;

	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	tz_x = f->zoom_x;
	tz_y = f->zoom_y;
	if (button == 5)
	{
		f->zoom_x = f->zoom_x * 2;
		f->zoom_y = f->zoom_y * 2;
		f->it_max += 10;
	}
	if (button == 4)
	{
		f->zoom_x = f->zoom_x / 2;
		f->zoom_y = f->zoom_y / 2;
		f->it_max -= 10;
	}
	f->x1_tmp += x / tz_x - (x / f->zoom_x);
	f->y1_tmp += y / tz_y - (y / f->zoom_y);
	print_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int		zoom_fs(int button, int x, int y, t_ftol *f)
{
	double	tz_x;
	double	tz_y;

	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	tz_x = f->zoom_x;
	tz_y = f->zoom_y;
	if (button == 5)
	{
		f->zoom_x = f->zoom_x * 2;
		f->zoom_y = f->zoom_y * 2;
		f->it_max += 10;
	}
	if (button == 4)
	{
		f->zoom_x = f->zoom_x / 2;
		f->zoom_y = f->zoom_y / 2;
		f->it_max -= 10;
	}
	f->x1_tmp += x / tz_x - (x / f->zoom_x);
	f->y1_tmp += y / tz_y - (y / f->zoom_y);
	print_fs(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
