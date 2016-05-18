
#include "fractol.h"

void init_mandelbrot(t_ftol *f)
{
	f->y = 0;
	f->x = 0;
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->im_x = 1024;//(f->x2 - f->x1) * f->zoom;
	f->im_y = 1024;//(f->y2 - f->y1) * f->zoom;
	f->zoom_x = f->im_x / (f->x2 - f->x1);
	f->zoom_y = f->im_y / (f->y2 - f->y1);
	f->it_max = 50;
}

void boucle_y2(t_ftol *f)
{
	f->c_r = f->x /f->zoom_x + f->x1;
	f->c_i = f->y /f->zoom_y + f->x1;
	f->z_r = f->tmp_c_r;
	f->z_i = f->tmp_c_i;
	f->i = 0;
}

void print_mandelbrot(t_ftol *f)
{
	init_mandelbrot(f);
	while (f->x < f->im_x)
	{
		while (f->y < f->im_y)
		{
			boucle_y2(f);
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->it_max)
			{
				f->tmp = f->z_r;
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->z_i * f->tmp + f->c_i;
				f->i++;
			}
			put_ptig(f, f->x, f->y);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
}

void ft_mandelbrot(void)
{
	t_ftol	*f;

	f =	(t_ftol *)ft_memalloc(sizeof(t_ftol));
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1024, 1024, "Julia");
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	f->mdf = mlx_get_data_addr(f->img, &f->bit, &f->size, &f->endian);
	f->deca_bit = f->bit >> 3;
	print_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_key_hook(f->win, key_funct, 0);
	mlx_hook(f->win, 6, 0, mouse_cg, f);
	mlx_loop(f->mlx);
	return;
}
