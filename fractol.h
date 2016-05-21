/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 23:51:36 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/21 23:51:39 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

# include <stdio.h>

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*mdf;
	int		bit;
	int		deca_bit;
	int		size;
	int		endian;
	double	y;
	double	x;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	x1_tmp;
	double	x2_tmp;
	double	y1_tmp;
	double	y2_tmp;
	int		check;
	double	zoom_x;
	double	zoom_y;
	double	zoom_x_tmp;
	double	zoom_y_tmp;
	int		it_max;
	double	im_x;
	double	im_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp_z_r;
	double	tmp_z_i;
	double	tmp_c_r;
	double	tmp_c_i;
	int		i;
	double	tmp;
}				t_ftol;

void			ft_error(void);
void			ft_check(char *str);
void			ft_julia(void);
void			print_julia(t_ftol *f);
int				key_funct(int keycode, t_ftol *f);
void			put_pti(t_ftol *f, int x, int y);
int				mouse_c(int x, int y, t_ftol *f);
void			ft_mandelbrot(void);
void			print_mandelbrot(t_ftol *f);
void			boucle_y2(t_ftol *f);
void			init_mandelbrot(t_ftol *f);
void			put_ptig(t_ftol *f, int x, int y);
int				mouse_cg(int x, int y, t_ftol *f);
int				zoom(int button, int x, int y, t_ftol *f);
void			init_tmp(t_ftol *f);
void			ft_fs(void);
void			print_fs(t_ftol *f);
int				mouse_ct(int x, int y, t_ftol *f);
void			put_ptiy(t_ftol *f, int x, int y);
int				zoom_m(int button, int x, int y, t_ftol *f);
int				zoom_fs(int button, int x, int y, t_ftol *f);
#endif
