
#include "fractol.h"

int		key_funct(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int mouse_c(int x, int y, t_ftol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	f->tmp_z_i = ((double)(y - 512)) / 512;
	f->tmp_z_r = ((double)(x - 512)) / 512;
	print_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return(0);
}

int mouse_cg(int x, int y, t_ftol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	f->tmp_c_i = ((double)(y - 512)) / 512;
	f->tmp_c_r = ((double)(x - 512)) / 512;
	print_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return(0);
}
