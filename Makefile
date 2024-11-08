NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I./includes

LIBFT_DIR = libs/libft
MINILIBX_DIR = libs/minilibx-linux
FT_PRINTF_DIR = libs/libft/ft_printf
SRC_DIR = src

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/basic_check.c \
	$(SRC_DIR)/map.c $(SRC_DIR)/window_and_mlx.c \
	$(SRC_DIR)/path_checks.c $(SRC_DIR)/map_checks.c \
	$(SRC_DIR)/many_frees.c $(SRC_DIR)/flood_check.c \
	$(SRC_DIR)/map_drawing.c $(SRC_DIR)/player.c \
	$(SRC_DIR)/movement.c $(SRC_DIR)/redraw.c \
	$(SRC_DIR)/camera.c \

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MINILIBX) $(FT_PRINTF) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(FT_PRINTF) $(MINILIBX_FLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	make clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
