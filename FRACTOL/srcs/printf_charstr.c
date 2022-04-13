/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_charstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <khaynes@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:02:16 by khaynes           #+#    #+#             */
/*   Updated: 2022/03/01 22:28:41 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}
