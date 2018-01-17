/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:06:34 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/17 18:13:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef	struct		s_data
{
	void			*mlx;
	void			*win;
	int				**tab;
	double			x;
	double			y;
}					t_data;
typedef	struct		s_axis
{
	double			x;
	double			y;
	double			z;
}					t_axis;

int		clean_board(t_data *data);
int		square_creation(t_data *data, t_axis ax, int max);
int		draw_lines(t_data *data, t_axis sides, int len);
int		line(t_data *data, t_axis a, t_axis b);
int		get_next_line(const int fd, char **line);

/*FUN*/
int		spirale_square(t_data *data);
int		spirale_sq_diag(t_data *data);

#endif
