/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:47:03 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/24 16:55:39 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int	i;

	i = 0;
	i = i | t << 24;
	i = i | r << 16;
	i = i | g << 8;
	i = i | b;
	return (i);
}

int coloors(int i)
{
	int arr[5];

	arr[0] = trgb(0,249, 200, 14);
	arr[0] = trgb(0,248, 102, 36);
	arr[1] = trgb(0,234, 53, 70);
	arr[2] = trgb(0,102, 46, 155);
	arr[3] = trgb(0,67, 188, 205);

	return(arr[i]);
}

void    my_mlx_pixel_put(t_data *img,int x, int y, unsigned int color)
{
    char    *pixel;
    pixel = img->addr + y * img->line_lenght + x * (img->bit_per_pixel / 8);
    *(unsigned int*)pixel = color;
}

double	map(double x, double in_max, double out_min, double out_max)
{
	return (x * ((out_max - out_min) / in_max) + out_min);
}