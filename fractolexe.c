/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:50:35 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/28 20:09:44 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	esc(int key, t_data *maro)
{
	if (key == 53)
	{
		mlx_destroy_window(maro->mlx, maro->mlx_win);
		exit(0);
	}
	return (0);
}

int	destroy(t_data *maro)
{
	mlx_clear_window(maro->mlx, maro->mlx_win);
	mlx_destroy_window(maro->mlx, maro->mlx_win);
	exit (0);
	return (0);
}

int	main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "julia") == 0)
			juliaexe();
		else if (ft_strcmp(argv[1], "mandelbrot") == 0)
			mandelbrotexe();
		else
			write(1, "not existed", 11);
	}
	return (0);
}
