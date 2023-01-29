/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:13 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/28 21:04:52 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
	int		function;
	float	xr;
	float	yr;
	float	xi;
	float	yi;
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	bx;
	double	by;
	double	ax;
	double	ay;
	float	x1;
	float	y1;
	void	*mlx;
	void	*mlx_win;
	int		iteration;
	int		max_iteration;
}			t_data;

int		ft_strcmp(const char *s1, const char *s2);
int		destroy(t_data *maro);
void	updatem(t_data *maro);
void	updatej(t_data *maro);
int		esc(int key, t_data *maro);
void	mandelbrotexe(void);
void	juliaexe(void);
int		trgb(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
int		coloors(int i);
void	julia(t_data *maro);
void	mandelbrot(t_data *maro);
void	update(t_data *maro);
int		mousemov(int x, int y, t_data *fk);
void	key4(t_data *maro, int x, int y);
int		mousekeys(int key, int x, int y, t_data *maro);
void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);
double	map(double x, double in_max, double out_min, double out_max);

#endif