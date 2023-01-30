/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:47:03 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/30 16:03:39 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int	i;

	i = 0;
	i = i | t << 24;
	i = i | r << 16;
	i = i | g << 8;
	i = i | b;
	return (i);
}

int	coloors(int i)
{
	int	arr[5];

	arr[0] = trgb(0, 245, 218, 209);
	arr[1] = trgb(0, 175, 19, 19);
	arr[2] = trgb(0, 9, 9, 9);
	arr[3] = trgb(0, 40, 47, 63);
	arr[4] = trgb(0, 175, 19, 19);
	return (arr[i]);
}

int	mousemov(int x, int y, t_data *maro)
{
	maro->x1 = map(x, WIDTH, maro->xr, maro->yr);
	maro->y1 = map(y, HEIGHT, maro->xi, maro->yi);
	updatej(maro);
	return (0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + y * img->line_lenght + x * (img->bit_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

double	map(double x, double in_max, float xr, float yr)
{
	return (x * (yr - xr) / in_max + xr);
}
