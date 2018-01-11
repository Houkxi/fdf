/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:06:34 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/11 17:48:24 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct		s_data
{
	void *mlx;
	void *win;
	int x;
	int y;
}					t_data;
typedef	struct		s_axis
{
	int				x;
	int				y;
	int				z;
}					t_axis;

int		clean_board(t_data *data);
int		square_creation(t_data *data, t_axis *ax, int max);
int		draw_lines(t_data *data, t_axis sides, int len);
int		get_next_line(const int fd, char **line);

#endif
