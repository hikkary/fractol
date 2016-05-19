
#include "fractol.h"

void init_fs(t_ftol *f)
{
	f->y = 0;
	f->x = 0;
	f->x1 = -3;
	f->x2 = 3;
	f->y1 = -2;
	f->y2 = 2;
	f->im_x = 1024;//(f->x2 - f->x1) * f->zoom;
	f->im_y = 1024;//(f->y2 - f->y1) * f->zoom;
	f->zoom_x = f->im_x / (f->x2 - f->x1);
	f->zoom_y = f->im_y / (f->y2 - f->y1);
	f->it_max = 50;
}

void boucle_y_f(t_ftol *f)
{
	f->c_r = f->x /f->zoom_x + f->x1;
	f->c_i = f->y /f->zoom_y + f->x1;
	f->z_r = f->tmp_c_r;
	f->z_i = f->tmp_c_i;
	f->i = 0;
}

void print_fs(t_ftol *f)
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

void ft_fs(void)
{
	t_ftol	*f;

	f =	(t_ftol *)ft_memalloc(sizeof(t_ftol));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1024, 1024, "Fire Ship are meant to fly");
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	f->mdf = mlx_get_data_addr(f->img, &f->bit, &f->size, &f->endian);
	f->deca_bit = f->bit >> 3;
	print_fs(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_key_hook(f->win, key_funct, 0);
	mlx_hook(f->win, 6, 0, mouse_ct, f);
	mlx_loop(f->mlx);
	return;
}
