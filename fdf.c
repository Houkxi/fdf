/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:07:16 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/17 19:16:04 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"

/*
	Repenser comment dessiner une ligne, gerer les diagonales et voir comment
	mieux calculer les coordonnees.
*/

int		diagonal_line(t_data *data)
{
	t_axis a;
	t_axis b;
	a.x = 500;
	a.y = 50;
	b.x = 100;
	b.y = 750;

	line(data, a, b);
	return (0);
}

int			create_tab(t_data *data, int **tab, t_axis size)
{
	t_axis	si;
	int		tmp;
	int		x;
	int		y;

	si.x = 0;
	si.y = 0;
	si.z = 3;
	x = 0;
	y = 0;
	tmp = size.y;
	while (y < size.y)
	{
		while (x < size.x)
		{
			if (tab[y][x] != 0)
			{
				data->y -= tab[y][x];
				data->x -= tab[y][x];
			}
			x++;
			square_creation(data, si, 7);
			si.x = 1;
			si.y = 1;
			draw_lines(data, si, 40);
			data->y += 40;
		}
		square_creation(data, si, 7);
		si.y = 0;
		draw_lines(data, si, 40);
		data->y = 250;
		data->x += 40;
		x = 0;
		y++;
		printf("(%d, %d)		(%f, %f)\n", y, x, size.y, size.x);
	}
	while (x < size.x)
	{
		x++;
		square_creation(data, si, 7);
		si.x = 0;
		si.y = 1;
		draw_lines(data, si, 40);
		data->y += 40;
	}
	square_creation(data, si, 7);
	return (0);
}

int		**data_gather(int fd, t_axis ax)
{
	t_axis	a;
	char	*line;
	char	**str;
	int		ret;
	int		**tab;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	line = NULL;
	tab = (int**)malloc(sizeof(int*) * ax.y);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
		str = ft_strsplit(line, ' ');
		tab[(int)a.x] = (int*)malloc(sizeof(int) * (int)ax.x);
		while (str[(int)a.y])
		{
			tab[(int)a.x][(int)a.z] = ft_atoi(str[(int)a.y]);
			a.z += 1;
			a.y += 1;
		}
		a.y = 0;
		a.z = 0;
		a.x += 1;
		free(str);
	}
	ft_show_tab_int(tab, 11, 19);
	return (tab);
}

int		event_key(int keycode, void *param)
{
	t_axis	ax;
	t_data	*data;

	ax.y = 11;
	ax.x = 19;
	ax.z = 0;
	printf("%d\n", keycode);
	data = (t_data*)param;
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
		create_tab(data, data->tab, ax);
	if (keycode == 16)
		spirale_square(data);
	if (keycode == 8)
		clean_board(data);
	if (keycode == 37)
		diagonal_line(data);
	if (keycode == 53)
		exit(EXIT_FAILURE);
	return (keycode);
}

int		main(int argv, char **argc)
{
	int		fd[argv];
	int		**tab;
	t_axis	ax;
	t_data	*data;
	double	try = 1;

	ax.y = 11;
	ax.x = 19;
	ax.z = 0;
	if (argv >= 2)
	{
		/*while (try != -9)
		{
			try = nextafter(try, -9);
			printf("%.55f\n", try);
		}*/
		try = nextafter(try, -9);
		printf("%.55f\n", try);
		printf("%f\n", copysign(1, -5));

		printf("\n%f\n", ceil(1.2569));
		printf("%f\n", floor(1.2569));
		printf("%f\n", nearbyint(5.2569));
		printf("%f\n", rint(4.72569));
		printf("%f\n", rint(1.2569));

		printf("\n%f\n", fdim(1, 5));
		printf("%f\n", fmax(1.2569, 87.256));
		printf("%f\n", fmin(1.2569, 458.1));

		printf("\n%d\n", fpclassify(58));
		printf("%d\n", fpclassify(10));

		printf("\n%d\n", isfinite(1/3));
		printf("%d\n", isnan(102));
		printf("%d\n", isnormal(1.50));

		printf("\n%f\n", cos((45 * (M_PI/180))));
		printf("%f\n", sin(45));
		printf("%f\n", tan(45));
		fd[0] = open(argc[1], O_RDONLY);
		tab = data_gather(fd[0], ax);
		if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
			return (0);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, 1280, 720, "mlx_42");
		data->x = 0;
		data->y = 0;
		data->tab = tab;
		//create_tab(data, tab, ax);
		mlx_key_hook(data->win, event_key, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
