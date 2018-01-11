/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:14:10 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/11 19:24:26 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		square_creation(t_data *data, t_axis *ax, int max)
{
	ax->y = 0;
	while (ax->y < max)
	{
		ax->x = 0;
		while (ax->x < max)
		{
			mlx_pixel_put(data->mlx, data->win, data->y + ax->y, data->x + ax->x, 0X0066FF66);
			ax->x += 1;
		}
		ax->y += 1;
	}
	return (0);
}
