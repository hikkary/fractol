
#include "fractol.h"

void ft_check(char *str)
{
	if (ft_strcmp("Mandelbrot",str) == 0)
		ft_putstr("Mandelbroute");
	else if (ft_strcmp("Julia",str) == 0)
		ft_julia();
	else
		ft_error();
}