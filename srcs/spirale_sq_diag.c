/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirale_sq_diag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:33:23 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/15 11:34:20 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		spirale_sq_diag(t_data *data)
{
	t_data	center;
	t_axis	si;
	int		width;
	int		size;
	int		turn;
	int		tmp;

	center.x = 360;
	center.y = 640;
	center.mlx = data->mlx;
	center.win = data->win;
	width = 4;
	turn = 1;
	size = 0;
	si.x = 0;
	si.z = 0;
	si.y = 0;
	while (size < 25)
	{
		while (turn < width)
		{
			si.x = -1;
			si.y = 1;
			tmp = draw_lines(&center, si, 2);
			center.x -= tmp;
			center.y += tmp;
			turn++;
		}
		turn = 0;
		width += 2;
		while (turn < width)
		{
			si.x = 1;
			si.y = 1;
			tmp = draw_lines(&center, si, 2);
			center.x += tmp;
			center.y += tmp;
			turn++;
		}
		turn = 0;
		width += 2;
		while (turn < width)
		{
			si.x = 1;
			si.y = -1;
			tmp = draw_lines(&center, si, 2);
			center.x += tmp;
			center.y -= tmp;
			turn++;
		}
		turn = 0;
		width += 2;
		while (turn < width)
		{
			si.x = -1;
			si.y = -1;
			tmp = draw_lines(&center, si, 2);
			center.x -= tmp;
			center.y -= tmp;
			turn++;
		}
		turn = 0;
		width += 2;
		size++;
	}

	return (0);
}
