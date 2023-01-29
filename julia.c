/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:57:10 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/28 21:08:20 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys(int key, t_data *maro)
{
	if (key == 126)
	{
		maro->y0 += 50;
		updatej(maro);
	}
	else if (key == 125)
	{
		maro->y0 -= 50;
		updatej(maro);
	}
	else if (key == 124)
	{
		maro->x += 50;
		updatej(maro);
	}
	else if (key == 123)
	{
		maro->x -= 50;
		updatej(maro);
	}
	else if (key == 53)
		destroy (maro);
	return (0);
}

int	juliaspl(t_data *maro)
{
	float	temp;

	while (maro->x * maro->x + maro->y * maro->y <= 4
		&& maro->iteration < maro->max_iteration)
	{
		temp = maro->x * maro->x - maro->y * maro->y + maro->x1;
		maro->y = 2 * maro->x * maro->y + maro->y1;
		maro->x = temp;
		maro->iteration++;
	}
	if (maro->iteration == maro->max_iteration)
		return (1);
	else
		return (0);
}

void	updatej(t_data *maro)
{
	mlx_clear_window(maro->mlx, maro->mlx_win);
	julia(maro);
}

void	julia(t_data *maro)
{
	maro->y0 = -1;
	while (++maro->y0 < WIDTH)
	{
		maro->x0 = -1;
		while (++maro->x0 < HEIGHT)
		{
			maro->x = map(maro->x0, WIDTH, maro->xr, maro->yr);
			maro->y = map(maro->y0, WIDTH, maro->xi, maro->yi);
			maro->iteration = 0;
			if (juliaspl(maro) == 1)
				my_mlx_pixel_put(maro, maro->x0, maro->y0, 0x000000);
			else
				my_mlx_pixel_put(maro, maro->x0, maro->y0,
					coloors(maro->iteration % 5));
		}
	}
	mlx_put_image_to_window(maro->mlx, maro->mlx_win, maro->img, 0, 0);
}

void	juliaexe(void)
{
	t_data	maro;

	maro.xr = -2;
	maro.yr = 2;
	maro.xi = -2;
	maro.yi = 2;
	maro.function = 1;
	maro.max_iteration = 100;
	maro.mlx = mlx_init();
	maro.mlx_win = mlx_new_window(maro.mlx, WIDTH, HEIGHT, "julia");
	maro.img = mlx_new_image(maro.mlx, WIDTH, HEIGHT);
	maro.addr = mlx_get_data_addr(maro.img, &maro.bit_per_pixel,
			&maro.line_lenght, &maro.endian);
	julia(&maro);
	mlx_hook(maro.mlx_win, 4, 0, mousekeys, &maro);
	mlx_hook(maro.mlx_win, 2, 0, esc, &maro);
	mlx_hook(maro.mlx_win, 17, 0, destroy, &maro);
	mlx_hook(maro.mlx_win, 2, 0, keys, &maro);
	mlx_hook(maro.mlx_win, 6, 0, mousemov, &maro);
	mlx_loop(maro.mlx);
}
