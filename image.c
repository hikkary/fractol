/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 00:06:57 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/05/22 00:07:00 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pti(t_ftol *f, int x, int y)
{
	int		i;

	i = (x * f->deca_bit) + (y * f->size);
	if (f->i != f->it_max)
	{
		f->mdf[i] = 0;
		f->mdf[i + 1] = 0;
		f->mdf[i + 2] = (f->i * 255) / f->it_max;
	}
	else
	{
		f->mdf[i] = 0;
		f->mdf[i + 1] = 0;
		f->mdf[i + 2] = 0;
	}
}

void	put_ptig(t_ftol *f, int x, int y)
{
	int		i;

	i = (x * f->deca_bit) + (y * f->size);
	if (f->i != f->it_max)
	{
		f->mdf[i] = 0;
		f->mdf[i + 1] = (f->i * 255) / f->it_max;
		f->mdf[i + 2] = 0;
	}
	else
	{
		f->mdf[i] = 0;
		f->mdf[i + 1] = 0;
		f->mdf[i + 2] = 0;
	}
}

void	put_ptiy(t_ftol *f, int x, int y)
{
	int		i;

	i = (x * f->deca_bit) + (y * f->size);
	if (f->i != f->it_max)
	{
		f->mdf[i] = (f->i * 255) / f->it_max;
		f->mdf[i + 1] = (f->i * 255) / f->it_max;
		f->mdf[i + 2] = 0;
	}
	else
	{
		f->mdf[i] = 0;
		f->mdf[i + 1] = (f->i * 230) / f->it_max;
		f->mdf[i + 2] = 0;
	}
}
