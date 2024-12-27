NAME = fractol

# Compiler and flags
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iminilibx -Isrc

# Source files and objects
SRCS = src/main.c src/ft_formula.c src/ft_smoth_pixel.c src/ft_hook_control.c \
       src/ft_usage.c src/ft_atof.c src/ft_of_movement.c src/ft_render.c \
       src/ft_track_mouse.c
OBJ_DIR = obj
OBJ = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# MiniLibX paths
MINILIBX_DIR = minilibx
MINILIBX_LIB = -L$(MINILIBX_DIR) -lmlx_Linux
MINILIBX_INCLUDE = -I$(MINILIBX_DIR)

# Libraries to link
LIB = $(MINILIBX_LIB) -L/usr/lib -lXext -lX11 -lm -lz

# Default target
all: $(NAME)
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | Fractol | Julie ♥\033[0m"

# Create the object directory before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile MiniLibX only if needed
minilibx:
	@echo "\033[38;5;208mCompiling MiniLibX...\033[0m"
	@if [ ! -f $(MINILIBX_DIR)/libmlx_Linux.a ] || [ $(MINILIBX_DIR)/mlx.h -nt $(MINILIBX_DIR)/libmlx_Linux.a ]; then \
		$(MAKE) -C $(MINILIBX_DIR); \
	else \
		echo "MiniLibX already compiled"; \
	fi

# Compile the program
$(NAME): $(OBJ_DIR) $(OBJ) minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: src/%.c
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

