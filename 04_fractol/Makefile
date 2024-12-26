NAME = fractol

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -lm

SRCS = main.c ft_formula.c ft_smoth_pixel.c ft_hook_control.c ft_usage.c ft_atof.c ft_of_movement.c ft_render.c ft_track_mouse.c
LIB = -Lminilibx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


all: $(NAME)
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥\033[0m"
	@echo "(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥"
	@echo "(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "File oggetto rimossi."

fclean: clean
	rm -f $(NAME)
	@echo "Eseguibile rimosso."

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re run

