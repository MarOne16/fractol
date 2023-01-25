/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:57:10 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/20 23:31:10 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bit_per_pixel;
    int     line_lenght;
    int     endian;
}             t_data;

void    my_mlx_pixel_put(t_data img,int x, int y, int color)
{
    char    *pixel;
    pixel = img.addr + y * img.line_lenght + x * (img.bit_per_pixel / 8);
    *(unsigned int*)pixel = color;
}

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main()
{
	void	*mlx;
	void	*mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx,500 , 500 , "mandelbrot");
    img.img = mlx_new_image(mlx , 500 , 500);
    img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_lenght , &img.endian);
	double x0 = 0;
	double y0 = 0;
	double x = 0;
	double y = 0;
	double xtemp = 0;

	int iteration = 0;
	int max_iteration = 100;
	while (y0 < 500)
	{
		x0 = 0;
		while (x0 < 500)
		{
			x = map(x0, 0, 500, -2, 2);
			y = map(y0, 0, 500, -2, 2);
			iteration = 0;
			while ((x * x) + (y * y) <= (2 * 2) && iteration < max_iteration)
			{
				xtemp = (x * x) - (y * y) + 0.3;
				y = 2 * x * y - 7 ;
				x = xtemp;
				iteration++;
			}
			if (iteration == max_iteration)
				my_mlx_pixel_put(img, x0, y0, 0x00000000);
			else
				my_mlx_pixel_put(img, x0, y0, iteration << 6);
			x0++;
		}
		y0++;
	}
    mlx_put_image_to_window(mlx,mlx_win,img.img,0 ,0);
    mlx_loop(mlx);
}
