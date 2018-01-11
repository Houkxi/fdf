/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:31:18 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/12 00:17:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

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

int		create_tab_x(t_data *data)
{
	int		fi;
	int size;
	t_axis si;

	fi = 0;
	size = 7;
	si.x = 0;
	si.y = 0;
	si.z = 3;
	while (fi < 11)
	{
		//square_creation(data, &si, size);
		si.x = 1;
		si.y = 1;
		if(data->y < 140 * 17)
		if (fi < 12)
		{
			draw_lines(data, si, 40);
			data->x += 40;
			si.y = 0;
			draw_lines(data, si , 40);
		}
		//data->x += 40;
		fi++;
	}
	//square_creation(data, &si, size);
	si.x = 0;
	si.y = 1;
	draw_lines(data, si, 40);
	return (0);
}

int		create_tab_y(t_data *data)
{
	int		fi;

	data->x = 140;
	data->y = 140;
	fi = 0;
	while (fi != 19)
	{
		create_tab_x(data);
		data->y += 40;
		data->x = 140;
		fi++;
	}

	return (0);
}

int		event_key(int keycode, void *param)
{

	t_data *data;
	int a;
	int b;

	data = (t_data*)param;
	a = 0;
	if (keycode == 124)
		data->y += 4;
	if (keycode == 123)
		data->y -= 4;
	if (keycode == 125)
		data->x += 4;
	if (keycode == 126)
		data->x -= 4;
	if (keycode == 15)
		spirale_sq_diag(data);
	if (keycode == 17)
		create_tab_y(data);
	if (keycode == 16)
		spirale_square(data);
	if (keycode == 8)
		clean_board(data);
	if (keycode == 53)
		exit(EXIT_FAILURE);
	a = 0;
	while (a < 2)
	{
		b = 0;
		while (b < 2)
		{
			mlx_pixel_put(data->mlx, data->win, data->y + a, data->x + b, 0X0066FF66);
			b++;
		}
		a++;
	}
	mlx_pixel_put(data->mlx, data->win, data->y, data->x, 0X00000FFF);
	return (keycode);
}

int	main()
{
	t_data *data;
	int x;
	int y;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1280, 720, "mlx_42");
	data->x = 140;
	data->y = 140;
	y = 0;
	x = 0;
	while (x < 720)
	{
		mlx_pixel_put(data->mlx, data->win, 0, x, 0X00FF00FF);
		mlx_pixel_put(data->mlx, data->win, 1, x, 0X00FF00FF);
		mlx_pixel_put(data->mlx, data->win, 1278, x, 0X00FF00FF);
		mlx_pixel_put(data->mlx, data->win, 1279, x, 0X00FF00FF);
		x++;
	}
	while (y < 1280)
	{
		mlx_pixel_put(data->mlx, data->win, y, 0, 0X0066FF66);
		mlx_pixel_put(data->mlx, data->win, y, 1, 0X0066FF66);
		mlx_pixel_put(data->mlx, data->win, y, 718, 0X0066FF66);
		mlx_pixel_put(data->mlx, data->win, y, 719, 0X0066FF66);
		y++;
	}
	mlx_key_hook(data->win, event_key, data);
	mlx_loop(data->mlx);
}
