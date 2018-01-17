/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:09:05 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/17 19:16:36 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		line(t_data *data, t_axis a, t_axis b)
{
	double x;
	double y;
	double slope;
	double slopey;
	double slopex;
	double caly = 0;
	double calx = 0;

	slope = (a.y - b.y)/(a.x - b.x);
	slopey = (a.y - b.y);
	slopex = (a.x - b.x);
	x = a.x;
	y = a.y;
	slopex = -copysign(1, slopex);
	slopey = -copysign(1, slopey);
	printf("%f\n", nextafter(1.2, 5.89));
	while (y != b.y)
	{
		printf("Y %.30f, %f\n", y, caly);
		if (x != b.x)
		{
			printf("X %.30f, %f\n", x, calx);
			mlx_pixel_put(data->mlx, data->win, data->y + y, data->x + x, 0X0066FF66);
			//calx = copysign(0.5, b.x - a.x);
			//x = nextafter(x, b.x);
			x += slopex;
		}
		//caly = copysign(0.5, b.y - a.y);
		//y = nextafter(y, b.y);
		y += slopey;
		slope++;
		/*if (slope > 50)
		break;*/
	}
	return (0);
}
