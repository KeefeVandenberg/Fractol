# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 17:24:08 by kvandenb          #+#    #+#              #
#    Updated: 2018/01/20 15:08:44 by kvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror -lpthread

make_libft = @make -C ./GNl/libft/

header = fractol.h

includes = ./GNL/libft/libft.a ./GNL/get_next_line.c ./minilibx_macos/libmlx.a

SRC = main.c init.c utils.c thread_julia.c burningship.c mandelbrot.c loop_events.c

OBJ = *.o

cc = @gcc

name = fractol

all : $(name)

$(name) :
	@make -C GNL/libft/
	$(cc) $(libx_flags) -g $(SRC) $(includes) -o $(name)
	@echo "Created Fractol executable"
	
clean:
	@make -C GNL/libft/ clean
	@/bin/rm -f $(name)
	
fclean: clean
	@make -C GNL/libft/ fclean
	
re: fclean all