/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:09:36 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/15 11:39:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		clean_board(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < 1280)
	{
		while (x < 720)
		{
			mlx_pixel_put(data->mlx, data->win, y, x, 0X00000000);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
