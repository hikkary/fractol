
#include "fractol.h"

void ft_check(char *str)
{
	if (ft_strcmp("Mandelbrot",str) == 0)
		ft_mandelbrot();
	else if (ft_strcmp("Julia",str) == 0)
		ft_julia();
	else if (ft_strcmp("Fireship",str) == 0)
			ft_fs();
	else
		ft_error();
}
