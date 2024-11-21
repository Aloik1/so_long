NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I./includes

LIBFT_DIR = libs/libft
MINILIBX_DIR = libs/minilibx-linux
FT_PRINTF_DIR = libs/libft/ft_printf
SRC_DIR = src

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC = 	$(SRC_DIR)/so_long.c 			$(SRC_DIR)/basic_check.c \
	$(SRC_DIR)/map.c 			$(SRC_DIR)/window_and_mlx.c \
	$(SRC_DIR)/path_checks.c 		$(SRC_DIR)/map_checks.c \
	$(SRC_DIR)/many_frees.c 		$(SRC_DIR)/flood_check.c \
	$(SRC_DIR)/map_drawing.c 		$(SRC_DIR)/player.c \
	$(SRC_DIR)/movement.c 			$(SRC_DIR)/redraw.c \
	$(SRC_DIR)/camera.c 			$(SRC_DIR)/collection.c \
	$(SRC_DIR)/exit.c 			$(SRC_DIR)/clean_exit.c \
	$(SRC_DIR)/texture_initialize.c		$(SRC_DIR)/choose_texture.c \
	$(SRC_DIR)/utils.c 			$(SRC_DIR)/player_textures_initialize.c \
	$(SRC_DIR)/choose_player_texture.c 	$(SRC_DIR)/collectible_texture_initialize.c \
	$(SRC_DIR)/more_collectible_textures.c	$(SRC_DIR)/texture_chooser.c \
	$(SRC_DIR)/collectible_position_adder.c $(SRC_DIR)/collectible_animation.c \
	$(SRC_DIR)/exit_texture_initialize.c 	$(SRC_DIR)/map_reading_utils.c \
	$(SRC_DIR)/clean_textures.c 		$(SRC_DIR)/clean_player_textures.c \
	$(SRC_DIR)/additional_buttons.c 	$(SRC_DIR)/enemies_initialize.c \
	$(SRC_DIR)/draw_enemies.c 		$(SRC_DIR)/clean_enemies_textures.c \
	$(SRC_DIR)/enemies_update.c 		$(SRC_DIR)/enemies_movement.c \
	$(SRC_DIR)/enemies_move_direction.c	$(SRC_DIR)/draw_updated_enemy.c \

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
