
#include "fractol.h"

int zoom(int button, int x, int y, t_ftol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_clear_window(f->mlx, f->win);
	f->img = mlx_new_image(f->mlx, 1024, 1024);
	x = 0;
	y = 0;
	if(button == 1)
	{
		// f->zoom_x_tmp *= 2;
		// f->zoom_y_tmp *= 2;
		f->x1_tmp += 0.1;
		f->x2_tmp -= 0.1;
		f->y1_tmp += 0.1;
		f->y2_tmp -= 0.1;
	}
	print_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
