/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:10:06 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:10:10 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fs(t_ftol *f)
{
	f->y = 0;
	f->x = 0;
	f->x1 = f->x1_tmp;
	f->x2 = f->x2_tmp;
	f->y1 = f->y1_tmp;
	f->y2 = f->y2_tmp;
}

void	init_tmp_fs(t_ftol *f)
{
	f->x1_tmp = -1.5;
	f->x2_tmp = 1.5;
	f->y1_tmp = -1;
	f->y2_tmp = 1;
	f->im_x = 800;
	f->im_y = 800;
	f->zoom_x = f->im_x / (f->x2_tmp - f->x1_tmp);
	f->zoom_y = f->im_y / (f->y2_tmp - f->y1_tmp);
	f->it_max = 50;
}

void	boucle_y_f(t_ftol *f)
{
	f->c_r = f->x / f->zoom_x + f->x1;
	f->c_i = f->y / f->zoom_y + f->y1;
	f->z_r = f->tmp_z_r;
	f->z_i = f->tmp_z_i;
	f->i = 0;
}

void	print_fs(t_ftol *f)
{
	init_fs(f);
	while (f->x < f->im_x)
	{
		while (f->y < f->im_y)
		{
			boucle_y_f(f);
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->it_max)
			{
				f->tmp = fabs(f->z_r * f->z_i);
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = f->tmp + f->tmp + f->c_i;
				f->i++;
			}
			put_ptiy(f, f->x, f->y);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
}

void	ft_fs(void)
{
	t_ftol	*f;

	f = (t_ftol *)ft_memalloc(sizeof(t_ftol));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 800, 800, "Burningship");
	f->img = mlx_new_image(f->mlx, 800, 800);
	f->mdf = mlx_get_data_addr(f->img, &f->bit, &f->size, &f->endian);
	f->deca_bit = f->bit >> 3;
	init_tmp_fs(f);
	print_fs(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_key_hook(f->win, key_funct, 0);
	mlx_mouse_hook(f->win, zoom_fs, f);
	mlx_loop(f->mlx);
	return ;
}
