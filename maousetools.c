/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maousetools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:32:20 by mqaos             #+#    #+#             */
/*   Updated: 2023/01/28 20:10:20 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key4(t_data *maro, int x, int y)
{
		maro->xr = maro->xr * 0.95;
		maro->yr = maro->yr * 0.95;
		maro->xi = maro->xi * 0.95;
		maro->yi = maro->yi * 0.95;
		maro->ax = map(x, WIDTH, maro->xr, maro->yr);
		maro->ay = map(y, HEIGHT, maro->xi, maro->yi);
		maro->xr += (maro->bx - maro->ax);
		maro->yr += (maro->bx - maro->ax);
		maro->xi += (maro->by - maro->ay);
		maro->yi += (maro->by - maro->ay);
}

int	mousekeys(int key, int x, int y, t_data *maro)
{
	maro->bx = map (x, WIDTH, maro->xr, maro->yr);
	maro->by = map (y, HEIGHT, maro->xi, maro->yi);
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
	if (maro->function == 1)
		updatej(maro);
	else if (maro->function == 2)
		updatem(maro);
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
