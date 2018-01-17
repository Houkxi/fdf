/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:16:56 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/15 11:25:24 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		draw_lines(t_data *data, t_axis sides, int len)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (sides.x == 1 || sides.x == -1)
	{
		while (x != len * sides.x)
		{
			mlx_pixel_put(data->mlx, data->win, data->y + sides.z, data->x + x, 0X0066FF66);
			x += sides.x;
		}
	}
	if (sides.y == 1 || sides.y == -1)
	{
		while (y != len * sides.y)
		{
			mlx_pixel_put(data->mlx, data->win, data->y + y, data->x + sides.z, 0X0066FF66);
			y += sides.y;
		}
	}
	return (len);
}
