/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:52:11 by khaynes           #+#    #+#             */
/*   Updated: 2022/04/13 12:03:40 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ITERATION	120
# define MINX -2
# define MINY -2
# define MAXX 2
# define MAXY 2
# define SIZEX 700
# define SIZEY 700
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	ymin;
	double	xmin;
	double	ymax;
	double	xmax;
	double	juliax;
	double	juliay;
	int		loopx;
	int		loopy;
	int		colour;
	int		fractol;
}	t_data;

void	ft_run(t_data *mlx, int flag);
void	start_mandelbrot(void);
int		mandelbrot(t_data *mlx);
int		mandelbrot_set(double x, double y, t_data *mlx);
void	start_julia(void);
int		julia(t_data *mlx);
int		julia_set(double x, double y, t_data *mlx);
int		keys(int keycode, t_data *vars);
int		zoom(int keycode, int x, int y, t_data *mlx);
int		ft_strcmp(char *s1, char *s2);
int		ft_exit(void);

#endif
