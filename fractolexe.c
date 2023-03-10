/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:50:35 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/30 20:03:58 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_printchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "JULIA") == 0)
			juliaexe();
		else if (ft_strcmp(argv[1], "MANDELBROT") == 0)
			mandelbrotexe();
		else
			ft_putstr("FRACTALS EXIST :\n >> MANDELBROT\n >> JULIA\n");
		return (0);
	}
	ft_putstr("FRACTALS EXIST :\n>> MANDELBROT\n>> JULIA\n");
	return (0);
}
