# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 17:32:18 by jfranco           #+#    #+#              #
#    Updated: 2024/12/21 19:02:15 by jfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fractol

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = main.c ft_fractol_utility.c ft_fractol_init.c ft_formula.c ft_smoth_pixel.c
LIB = -Lminilibx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re
