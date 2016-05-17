
#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>

# include <stdio.h>

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*mdf;
	int 	bit;
	int		deca_bit;
	int		size;
	int		endian;
	double	y;
	double 	x;
	double	x1;
	double	x2;
	double 	y1;
	double	y2;
	double 	zoom_x;
	double 	zoom_y;
	int 	it_max;
	double 	im_x;
	double 	im_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp_z_r;
	double	tmp_z_i;
	int		i;
	double	tmp;
}				t_ftol;

void 	ft_error(void);
void 	ft_check(char *str);
void 	ft_julia(void);
void 	print_julia(t_ftol *f);
int		key_funct(int keycode);
void 	put_pti(t_ftol *f, int x, int y);
int 	mouse_c(int x, int y, t_ftol *f);

#endif
