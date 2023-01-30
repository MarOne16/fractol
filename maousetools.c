/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maousetools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:32:20 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/30 16:06:11 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key4(t_data *maro, int x, int y)
{
		maro->xr *= 0.95;
		maro->yr *= 0.95;
		maro->xi *= 0.95;
		maro->yi *= 0.95;
		maro->ax = map(x, WIDTH, maro->xr, maro->yr);
		maro->ay = map(y, WIDTH, maro->xi, maro->yi);
		maro->xr += (maro->bx - maro->ax);
		maro->yr += (maro->bx - maro->ax);
		maro->xi += (maro->by - maro->ay);
		maro->yi += (maro->by - maro->ay);
}

int	mousekeys(int key, int x, int y, t_data *maro)
{
	maro->bx = map(x, WIDTH, maro->xr, maro->yr);
	maro->by = map(y, WIDTH, maro->xi, maro->yi);
	if (key == 4)
		key4(maro, x, y);
	else if (key == 5)
	{
		maro->xr /= 0.95;
		maro->yr /= 0.95;
		maro->xi /= 0.95;
		maro->yi /= 0.95;
		maro->ax = map(x, WIDTH, maro->xr, maro->yr);
		maro->ay = map(y, WIDTH, maro->xi, maro->yi);
		maro->xr += (maro->bx - maro->ax);
		maro->yr += (maro->bx - maro->ax);
		maro->xi += (maro->by - maro->ay);
		maro->yi += (maro->by - maro->ay);
	}
	if (maro->function == 1)
		updatej(maro);
	else if (maro->function == 2)
		updatem(maro);
	else if (maro->function == 3)
		updateb(maro);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while ((c1[i] || c2[i]))
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
		i++;
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
