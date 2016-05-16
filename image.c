
#include "fractol.h"

void put_pti(t_ftol *f, int x, int y)
{
	if (f->i != f->it_max)
	{
		f->mdf[(x * f->bit >> 3) + (y * f->size)] = 0;
		f->mdf[(x * f->bit >> 3) + (y * f->size) + 1] = 0;
		f->mdf[(x * f->bit >> 3) + (y * f->size) + 2] = (f->i * 255) / f->it_max;
	}
	else
	{
		f->mdf[(x * f->bit >> 3) + (y * f->size)] = 255;
		f->mdf[(x * f->bit >> 3) + (y * f->size) + 1] = 255;
		f->mdf[(x * f->bit >> 3) + (y * f->size) + 2] = 255;	
	}
}