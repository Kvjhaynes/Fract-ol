/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:55:12 by khaynes           #+#    #+#             */
/*   Updated: 2022/04/13 12:06:55 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

void	ft_header(void)
{
	ft_printf(".::::::::                          .::  .::           .::\n");
	ft_printf(".::                                .::   .:           .::\n");
	ft_printf(".::      .: .:::   .::       .:::.:.: .:      .::     .::\n");
	ft_printf(".::::::   .::    .::  .::  .::     .::      .::  .::  .::\n");
	ft_printf(".::       .::   .::   .:: .::      .::     .::    .:: .::\n");
	ft_printf(".::       .::   .::   .::  .::     .::      .::  .::  .::\n");
	ft_printf(".::      .:::     .:: .:::   .:::   .::       .::    .:::\n\n");
}

void	ft_run(t_data *mlx, int flag)
{
	if (mlx->fractol == 1)
	{
		if (flag)
			mandelbrot(mlx);
		else
			start_mandelbrot();
	}
	if (mlx->fractol == 2)
	{
		if (flag)
			julia(mlx);
		else
			start_julia();
	}
}

void	ft_usage(int flag)
{
	if (flag)
		ft_printf(".:: Usage: ./fractol <name> ::.\n");
	ft_printf(".:: List of available fractals ::.\n");
	ft_printf("::: - Mandelbrot               :::\n");
	ft_printf("::: - Julia                    :::\n");
}

void	ft_how_to_use(void)
{
	ft_printf(".::        Keys to use       ::.\n");
	ft_printf(":::    Scroll up to zoom in  :::\n");
	ft_printf(":::  Scroll down to zoom out :::\n");
	ft_printf(":::    C: to change colors   :::\n");
	ft_printf(":::  Use arrows to navigate  :::\n");
	ft_printf(":::W,A,S,D: for Julia to move:::\n\n");
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	if (argc >= 2)
	{
		ft_header();
		ft_usage(0);
		ft_how_to_use();
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			mlx.fractol = 1;
		else if (!ft_strcmp(argv[1], "Julia"))
			mlx.fractol = 2;
		ft_run((void *)&mlx, 0);
	}
	else
	{
		ft_printf(".::: The parameters are invalid! :::.\n");
		ft_usage(1);
	}
}
