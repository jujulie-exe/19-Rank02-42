NAME = fractol

# Compiler and flags
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iminilibx

# Source files and objects
SRCS = main.c ft_formula.c ft_smoth_pixel.c ft_hook_control.c ft_usage.c ft_atof.c ft_of_movement.c ft_render.c ft_track_mouse.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# MiniLibX paths
MINILIBX_DIR = minilibx
MINILIBX_LIB = -L$(MINILIBX_DIR) -lmlx_Linux
MINILIBX_INCLUDE = -I$(MINILIBX_DIR)

# Libraries to link
LIB = $(MINILIBX_LIB) -L/usr/lib -lXext -lX11 -lm -lz

# Default target
all: minilibx $(NAME)
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥\033[0m"

# Compile MiniLibX
minilibx:
	@echo "\033[38;5;208mCompiling MiniLibX...\033[0m"
	@$(MAKE) -C $(MINILIBX_DIR)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the program
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects and MiniLibX
clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "File oggetto rimossi."

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)
	@echo "Eseguibile rimosso."

# Recompile everything
re: fclean all

# Run the program
run: re
	./$(NAME)

.PHONY: all clean fclean re run minilibx

