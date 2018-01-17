/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirale_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:31:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/15 11:34:24 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		spirale_square(t_data *data)
{
	t_data	center;
	t_axis	si;
	int		width;
	int		size;
	int		turn;

	center.x = 360;
	center.y = 640;
	center.mlx = data->mlx;
	center.win = data->win;
	width = 4;
	turn = 1;
	size = 0;
	si.z = 0;
	while (size < 125)
	{
		si.x = 1;
		si.y = 0;
		center.x += draw_lines(&center, si, turn + width);
		si.x = 0;
		si.y = 1;
		center.y += draw_lines(&center, si, turn + width);
		turn += width;
		si.x = -1;
		si.y = 0;
		center.x -= draw_lines(&center, si, turn + width);
		si.x = 0;
		si.y = -1;
		center.y -= draw_lines(&center, si, turn + width);
		turn += width;
		size++;
	}
	return (0);
}
