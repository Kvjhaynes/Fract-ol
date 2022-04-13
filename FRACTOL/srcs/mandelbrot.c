/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:25:38 by khaynes           #+#    #+#             */
/*   Updated: 2022/04/12 15:16:50 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = 0;
	yy = 0;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = (pow(xx, 2) - pow(yy, 2)) + x;
		yy = (2 * temp * yy) + y;
		if (pow(xx, 2) + pow(yy, 2) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy,
				(mlx->colour) + 0x00E8000F * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, 0x0000000);
	return (0);
}

int	mandelbrot(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx *((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy *((mlx->ymax - mlx->ymin) / SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (1);
}

void	start_mandelbrot(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol - Mandelbrot");
	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mlx.colour = 0;
	mlx.fractol = 1;
	mandelbrot((void *)&mlx);
	mlx_key_hook(mlx.win, keys, (void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)&mlx);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 15, 10, 0x001B2773C, "Mandelbrot");
	mlx_loop(mlx.mlx);
}
