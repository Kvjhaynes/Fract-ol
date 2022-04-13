/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <khaynes@student.42adel.org.au>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:04:25 by khaynes           #+#    #+#             */
/*   Updated: 2022/03/16 12:28:56 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void	ft_putunsigned(unsigned int nb, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_puthex(unsigned int nbr, char *base, int *len);
void	ft_putpointer(unsigned long nbr, char *base, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
int		ft_printf(const char *format, ...);

#endif
