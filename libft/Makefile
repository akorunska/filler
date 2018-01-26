# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 17:30:40 by akorunsk          #+#    #+#              #
#    Updated: 2018/01/25 14:35:46 by akorunsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF_SRC_DIR = ./printf_src

GNL_SRC_DIR = ./gnl_src

SRC = $(shell find $(PRINTF_SRC_DIR) $(GNL_SRC_DIR) -type f -name "*.c")

INC = -I printf_src/include/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBNAME = libsrc/libft.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : libmake $(OBJ)
	cp $(LIBNAME) $(NAME)
	ar r $(NAME) $(OBJ)

%.o: %.c
		gcc $(CFLAGS) $(INC) -o $@ $<

clean: libfclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

test:
	gcc main.c libftprintf.a

libmake:
	@make -C libsrc/ all

libclean:
	@make -C libsrc/ clean

libfclean:
	@make -C libsrc/ fclean
