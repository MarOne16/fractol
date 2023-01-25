/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:57:10 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/25 12:01:16 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//bitch u hv no idea hw mch i care
void	mandelbrot(t_data *maro)
{
	int iteration = 0;
	int max_iteration = 50;
	float	temp;
	maro->y0 = -1;
	while (++maro->y0 < HEIGHT)
	{
		maro->x0 = -1;
		while (++maro->x0 < WIDTH)
		{
			maro->x = 0;
			maro->y = 0;
			iteration = 0;
			while ((maro->x * maro->x) + (maro->y * maro->y) <= (4) && ++iteration < max_iteration)
			{
				temp = (maro->x * maro->x) - (maro->y * maro->y) + map(maro->x0, WIDTH, maro->xr, maro->yr);
				maro->y = 2 * maro->x * maro->y + map(maro->y0,HEIGHT, maro->xi, maro->yi);
				maro->x = temp;
			}
			if ((maro->x * maro->x) + (maro->y * maro->y) <= (2 * 2))
				my_mlx_pixel_put(maro, maro->x0, maro->y0, 0x00000000);
			else
				my_mlx_pixel_put(maro, maro->x0, maro->y0, coloors(iteration % 5));
		}
	}
    mlx_put_image_to_window(maro->mlx,maro->mlx_win,maro->img,0 ,0);
}
void update(t_data *maro)
{
	mandelbrot(maro);
}

int mousemov(int x, int y, t_data *fk)
{
	if (fk->mod == 0)
	{
		fk->xr = map(x, WIDTH, fk->xr, fk->yr);
		fk->y = map(y, HEIGHT, fk->xi, fk->yi);
		update(fk);
	}
	else if (fk->mod == 1)
		update(fk);
	return (0);
}

void key4(t_data *maro,int x,int y)
{
		maro->xr = maro->xr * 0.95;
		maro->yr = maro->yr * 0.95;
		maro->xi = maro->xi * 0.95;
		maro->yi = maro->yi * 0.95;
		maro->ax = map (x,WIDTH, maro->xr, maro->yr);
		maro->ay = map (y,HEIGHT, maro->xi, maro->yi);
		maro->xr += (maro->bx - maro->ax);
		maro->yr += (maro->bx - maro->ax);
		maro->xi += (maro->by - maro->ay);
		maro->yi += (maro->by - maro->ay);
}

int	mousekeys(int key, int x, int y, t_data *maro)
{
	maro->bx = map(x,WIDTH, maro->xr, maro->yr);
	maro->by = map(y,HEIGHT, maro->xi, maro->yi);
	if (key == 4)
		key4(maro, x, y);
	else if (key == 5)
	{
		maro->xr = maro->xr / 0.95;
		maro->yr = maro->yr / 0.95;
		maro->xi = maro->xi / 0.95;
		maro->yi = maro->yi / 0.95;
		maro->ax = map(x, WIDTH, maro->xr, maro->yr);
		maro->ay = map(y, HEIGHT, maro->xi, maro->yi);
		maro->xr += (maro->bx - maro->ax);
		maro->yr += (maro->bx - maro->ax);
		maro->xi += (maro->by - maro->ay);
		maro->yi += (maro->by - maro->ay);
	}
	update(maro);
	return (0);
}

int main()
{
    t_data  maro;

	maro.xr = -2;
	maro.yr = 2;
	maro.xi = -2;
	maro.yi = 2;
    maro.mlx = mlx_init();
    maro.mlx_win = mlx_new_window(maro.mlx,WIDTH , HEIGHT , "mandelbrot");
    maro.img = mlx_new_image(maro.mlx , WIDTH , HEIGHT);
    maro.addr = mlx_get_data_addr(maro.img, &maro.bit_per_pixel, &maro.line_lenght , &maro.endian);
	mandelbrot(&maro);
	mlx_hook(maro.mlx_win, 4, 0, mousekeys, &maro);
	mlx_loop(maro.mlx);
	return (0);
}