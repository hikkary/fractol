
#include "fractol.h"

void init_julia(t_ftol *f)
{
	f->y = 0;
	f->x = 0;
	f->x1 = f->x1_tmp;
	f->x2 = f->x2_tmp;
	f->y1 = f->y1_tmp;
	f->y2 = f->y2_tmp;
	f->im_x = 1024;//(f->x2 - f->x1) * f->zoom;
	f->im_y = 1024;//(f->y2 - f->y1) * f->zoom;
	f->zoom_x = f->im_x / (f->x2 - f->x1);
	f->zoom_y = f->im_y / (f->y2 - f->y1);
	f->it_max = 50;
}

void init_tmp(t_ftol *f)
{
	f->x1_tmp = -1;
	f->x2_tmp = 1;
	f->y1_tmp = -1.2;
	f->y2_tmp = 1.2;
}

void boucle_y(t_ftol *f)
{
	f->c_r = f->tmp_z_r;
	f->c_i = f->tmp_z_i;
	f->z_r = f->x / f->zoom_x + f->x1;
	f->z_i = f->y / f->zoom_y + f->y1;
	f->i = 0;
}

void print_julia(t_ftol *f)
{
	init_julia(f);
	while (f->x < f->im_x)
	{
		while (f->y < f->im_y)
		{
			boucle_y(f);
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->it_max)
			{
				f->tmp = f->z_r;
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->z_i * f->tmp + f->c_i;
				f->i++;
			}
			put_pti(f, f->x, f->y);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
}

void ft_julia(void)
{
	t_ftol	*f;

	f =	(t_ftol *)ft_memalloc(sizeof(t_ftol));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1024, 1024, "Julia");
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	f->mdf = mlx_get_data_addr(f->img, &f->bit, &f->size, &f->endian);
	f->deca_bit = f->bit >> 3;
	init_tmp(f);
	print_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_key_hook(f->win, key_funct, 0);
	mlx_hook(f->win, 6, 0, mouse_c, f);
	mlx_mouse_hook(f->win, zoom,f);
	mlx_loop(f->mlx);
	return;
}
