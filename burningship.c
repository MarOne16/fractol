/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:44:27 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/30 22:47:30 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	keys(int key, t_data *maro)
{
	if (key == 126)
	{
		maro->xi += 0.5;
		maro->yi += 0.5;
	}
	else if (key == 125)
	{
		maro->xi -= 0.5;
		maro->yi -= 0.5;
	}
	else if (key == 124)
	{
		maro->xr -= 0.5;
		maro->yr -= 0.5;
	}
	else if (key == 123)
	{
		maro->xr += 0.5;
		maro->yr += 0.5;
	}
	else if (key == 53)
		destroy(maro);
	updateb(maro);
	return (0);
}

int	burningshipspl(t_data *maro)
{
	float	temp;

	while ((maro->x * maro->x) + (maro->y * maro->y) <= (4)
		&& ++maro->iteration < maro->max_iteration)
	{
		temp = fabs((maro->x * maro->x) - (maro->y * maro->y)
				+ map(maro->x0, WIDTH, maro->xr, maro->yr));
		maro->y = fabs(2 * maro->x * maro->y
				+ map(maro->y0, HEIGHT, maro->xi, maro->yi));
		maro->x = temp;
	}
	if (maro->iteration == maro->max_iteration)
		return (1);
	else
		return (0);
}

void	burningship(t_data *maro)
{
	maro->y0 = -1;
	while (++maro->y0 < HEIGHT)
	{
		maro->x0 = -1;
		while (++maro->x0 < WIDTH)
		{
			maro->x = 0;
			maro->y = 0;
			maro->iteration = 0;
			if (burningshipspl(maro) == 1)
				my_mlx_pixel_put(maro, maro->x0, maro->y0, 0x00000000);
			else
				my_mlx_pixel_put(maro, maro->x0, maro->y0,
					coloors(maro->iteration % 5));
		}
	}
	mlx_put_image_to_window(maro->mlx, maro->mlx_win, maro->img, 0, 0);
}

void	updateb(t_data *maro)
{
	mlx_clear_window(maro->mlx, maro->mlx_win);
	burningship(maro);
}

void	burningshipexe(void)
{
	t_data	maro;

	maro.xr = -2;
	maro.yr = 2;
	maro.xi = -2;
	maro.yi = 2;
	maro.movex = 0;
	maro.movey = 0;
	maro.function = 3;
	maro.max_iteration = 100;
	maro.mlx = mlx_init();
	maro.mlx_win = mlx_new_window(maro.mlx, WIDTH, HEIGHT, "burningship");
	maro.img = mlx_new_image(maro.mlx, WIDTH, HEIGHT);
	maro.addr = mlx_get_data_addr(maro.img, &maro.bit_per_pixel,
			&maro.line_lenght, &maro.endian);
	burningship(&maro);
	mlx_hook(maro.mlx_win, 4, 0, mousekeys, &maro);
	mlx_hook(maro.mlx_win, 2, 0, keys, &maro);
	mlx_hook(maro.mlx_win, 17, 0, destroy, &maro);
	mlx_loop(maro.mlx);
}
