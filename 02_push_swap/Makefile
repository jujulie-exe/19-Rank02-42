# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 17:27:06 by jfranco           #+#    #+#              #
#    Updated: 2024/11/04 20:06:47 by jfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = ft_atol.c ft_exit_and_error.c ft_init_.c ft_push.c ft_reverse.c ft_rotate.c ft_set_value.c ft_short_algo.c ft_split.c ft_swap.c ft_utils_list.c loop_list.c main.c push_swap.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
