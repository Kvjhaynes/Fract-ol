#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:32:46 by ahjadani          #+#    #+#              #
#    Updated: 2022/04/12 15:19:28 by khaynes          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = srcs
FILES = srcs/additional_funcs.c srcs/ft_printf.c srcs/printf_charstr.c srcs/printf_nbrs.c srcs/fractol.c srcs/julia.c srcs/mandelbrot.c
CFLAGS = -Werror -Wextra -Wall

OBJECTS = $(FILES:.c=.o)
NAME = fractol
HEADER = include
INCS = -I$(HEADER) -Imlx
CC = gcc
RM = rm -f
UNAME = $(shell uname -s)
ifeq ($(UNAME),Linux)
	XFLAGS = -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
	XFLAGS = -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(INCS) -Lmlx -lmlx $^ -o $@ $(XFLAGS)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

bonus: all

startall:
	$(shell ./fractol Mandelbrot & ./fractol Julia & ./fractol "Burning ship")

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, startall, bonus
