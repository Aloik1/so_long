/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:51:13 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 18:51:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 	96
# define KEY_W 		119
# define KEY_A 		97
# define KEY_S 		115
# define KEY_D 		100
# define KEY_ENTER 	65293
# define KEY_ESC 	65307
# define KEY_PRESS 	2
# define KEY_RELEASE 	3
# define DESTROY_NOTIFY 17 // event code for window close
# define WIN_WIDTH 	960 // 960 x 576 window size
# define WIN_HEIGHT 	576 //
# define VIEW_RANGE 	10 // 10 tiles visible in the view

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int		win_width;
	int		win_height;
}	t_window;

typedef struct s_enemies
{
	int	number_of_enemies;
	int	enemy_1_x;
	int	enemy_1_y;
	int	enemy_2_x;
	int	enemy_2_y;
	int	enemy_3_x;
	int	enemy_3_y;
	int	enemy_4_x;
	int	enemy_4_y;
	int	enemy_5_x;
	int	enemy_5_y;
}	t_enemies;

typedef struct s_collectible_position
{
	int		x;
	int		y;
	int		collectibles_visible;
	int		**positions;
}	t_collectible_position;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		collectibles;
	int		exits;
	int		players;
	char		**map_grid;
	char		**map_aux;
	t_collectible_position	*collectible;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_player_position
{
	int		x;
	int		y;
}	t_player_position;

typedef struct s_player
{
	t_player_position	position;
	void		*player_texture;
	int		pixel_x;
	int		pixel_y;
	int		collectibles_collected;
	int		width;
	int		height;	
	int		speed;
	int		direction;
}	t_player;

typedef struct s_flood_grid
{
	char	**flood_map;
	int	collectibles_count;
	int	exits_count;
	int	start_x;
	int	start_y;
	int	rows;
	int	cols;
}	t_flood_grid;

typedef struct s_textures
{
	void			*floor_img;
	void			*floor_all_open;
	void			*floor_top_bot;
	void			*floor_left_right;
	void			*floor_top_open;
	void			*floor_bot_open;
	void			*floor_left_open;
	void			*floor_right_open;
	void			*floor_top_right_corner;
	void			*floor_top_left_corner;
	void			*floor_bot_right_corner;
	void			*floor_bot_left_corner;
	void			*floor_top_closed;
	void			*floor_bot_closed;
	void			*floor_left_closed;
	void			*floor_right_closed;

	void			*wall_top_img;

	void			*collectible_image;
	void			*collectible_animation_1;
	void			*collectible_animation_2;
	void			*collectible_animation_3;
	void			*collectible_animation_4;
	void			*collectible_animation_5;
	void			*collectible_destroyed;

	void			*exit_closed;
	void			*exit_open;

	void			*player_img;//
	void			*player_up_1;//
	void			*player_up_2;//
	void			*player_up_3;//
	void			*player_down_1;//
	void			*player_down_2;//
	void			*player_down_3;//
	void			*player_left_1;//
	void			*player_left_2;//
	void			*player_left_3;//
	void			*player_right_1;//
	void			*player_right_2;//
	void			*player_right_3;//

	void			*enemy_base;
	int			enemy_base_height;
	int			enemy_base_width;

	void			*enemy_up_1;
	int			enemy_up_1_height;
	int			enemy_up_1_width;

	void			*enemy_up_2;
	int			enemy_up_2_height;
	int			enemy_up_2_width;

	void			*enemy_up_3;
	int			enemy_up_3_height;
	int			enemy_up_3_width;

	void			*enemy_down_1;
	int			enemy_down_1_height;
	int			enemy_down_1_width;

	void			*enemy_down_2;
	int			enemy_down_2_height;
	int			enemy_down_2_width;

	void			*enemy_down_3;
	int			enemy_down_3_height;
	int			enemy_down_3_width;

	void			*enemy_right_1;
	int			enemy_right_1_height;
	int			enemy_right_1_width;

	void			*enemy_right_2;
	int			enemy_right_2_height;
	int			enemy_right_2_width;

	void			*enemy_right_3;
	int			enemy_right_3_height;
	int			enemy_right_3_width;

	void			*enemy_left_1;
	int			enemy_left_1_height;
	int			enemy_left_1_width;

	void			*enemy_left_2;
	int			enemy_left_2_height;
	int			enemy_left_2_width;

	void			*enemy_left_3;
	int			enemy_left_3_height;
	int			enemy_left_3_width;

	int			direction_1;
	int			direction_2;
	int			direction_3;
	int			direction_4;
	int			direction_5;
	
	int			animation_1;
	int			animation_2;
	int			animation_3;
	int			animation_4;
	int			animation_5;

	int			collectible_1_width;
	int			collectible_1_height;
	int			collectible_count;
	int			collectible_1_x;
	int			collectible_1_y;
	int			collectible_2_x;
	int			collectible_2_y;
	int			collectible_3_x;
	int			collectible_3_y;
	int			collectible_4_x;
	int			collectible_4_y;
	int			collectible_5_x;
	int			collectible_5_y;
	int			collectible_1_state;
	int			collectible_2_state;
	int			collectible_3_state;
	int			collectible_4_state;
	int			collectible_5_state;

	int			floor_width;
	int			floor_height;
	int			wall_top_width;
	int			wall_top_height;
	int			wall_bottom_width;
	int			wall_bottom_height;
	int			wall_left_width;
	int			wall_left_height;
	int			wall_right_width;
	int			wall_right_height;
	int			exit_width;
	int			exit_height;
	int			player_width;
	int			player_height;
}	t_textures;

typedef struct s_movement
{
	int	move_up;
	int	move_down;
	int	move_right;
	int	move_left;
	int	key_pressed;
	int	previous_key_pressed;
}	t_movement;

typedef struct s_camera
{
	int		x;
	int		y;
	int		width;
	int		height;
}	t_camera;

typedef struct 		s_game
{
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_camera	*camera;
	t_textures	*textures;
	t_movement	*movement;
	t_enemies	*enemies;

}	t_game;

// function prototypes
int			basic_check(int argc, char **argv);
int			read_map(char *file, t_game *game);
int			window_and_mlx(t_game *game, t_window **window);
int			flood_check(t_map *map, t_player_position player_position);
void			free_map(t_map *map);
t_player_position	return_null_player(void);
t_collectible_position	return_null_and_free_collectibles(t_collectible_position collectibles);
int			path_checks(t_game *game);
int			map_checks(t_map *map);
int			draw_map(t_game *game, t_window *window, t_camera *camera, t_textures *textures);
int			init_player(t_game *game);
int			draw_player(t_game *game, t_window *window, t_player *player, t_camera *camera);
int			movement(int keycode, t_game *game);
void			redraw_everything(t_game *game, t_textures *textures, int moves);
void			update_camera(t_camera *camera, t_player *player, t_map *map);
void			camera_init(t_camera *camera, t_player *player, t_map *map);
int			collect_collectible(t_game *game, t_player *player);
int			open_exit(t_map *map, t_player *player, t_game *game);
void			draw_exit(t_game *game, t_textures *textures, t_camera *camera);
int			clean_exit(t_game *game);
int			texture_initialize(t_game *game, void *mlx);
void			*choose_floor(t_game *game, int j, int i);
void			aux_map_creation(t_game *game);
int			player_texture_initialize(t_game *game, void *mlx);
void			*choose_player_texture(t_game *game);
void			more_collectible_textures(t_textures *textures, t_map *map);
int			collectible_textures_initialize(t_game *game, void *mlx);
void			*texture_chooser(t_game *game, int i, int j);
void			*collectible_chooser(t_game *game);
int			exit_initialize(t_game *game, void *mlx);
int			init_textures(t_textures *textures);
int			memory_check_grid(t_map *map);
int			memory_check_fd(int fd);
int			memory_check_map(t_map *map);
void			clean_more_collectible_animation(t_game *game);
void			clean_more_floors(t_game *game);
void			clean_even_more_floors(t_game *game);
void			clean_some_floors(t_game *game);
void			clean_floors(t_game *game);
void			clean_player_textures(t_game *game);
void			clean_more_player_textures(t_game *game);
void			cilit_bang(t_game *game);
void			enter_press(t_game *game, int moves);
void			*choose_same_texture(t_game *game);
int			escape_button(int keycode, t_game *game);
int			enemies_init(t_game *game);
int			draw_enemies(t_game *game, t_camera *camera, t_window *window);
void			free_enemies(t_game *game);
void			enemies_movement(t_game *game, t_enemies *enemies, int *updated);
int			update_enemy(t_game *game, int pos_y, int pos_x);
int			generate_direction(t_game *game, int free_spaces, int pos_y, int pos_x, int direction);
void			draw_enemy(t_game *game, int direction, int animation, int pos_y, int pos_x);
int			determine_enemy(t_enemies *enemies, int i, int j);
void			check_collision(t_game *game);
void			draw_info(t_game *game, int moves);
int			positions_for_enemies(t_game *game, t_map *map, int i, int j);
int			determine_pixel_position_y(t_game *game, int pos_y);
int			determine_pixel_position_x(t_game *game, int pos_x);
void			check_enemy_number(t_game *game, int pos_y, int pos_x, int animation);
void			choose_enemy_up_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x);
void			choose_enemy_down_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x);
void			choose_enemy_left_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x);
void			choose_enemy_right_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x);
int			check_if_in_camera(t_game *game, int i, int j);
void			update_enemy_1(t_game *game, t_enemies *enemies, int i, int j);
void			update_enemy_2(t_game *game, t_enemies *enemies, int i, int j);
void			update_enemy_3(t_game *game, t_enemies *enemies, int i, int j);
void			update_enemy_4(t_game *game, t_enemies *enemies, int i, int j);
void			update_enemy_5(t_game *game, t_enemies *enemies, int i, int j);
int			choose_enemy_1(t_game *game, t_enemies *enemies, int *params, int updated_1);
int			choose_enemy_2(t_game *game, t_enemies *enemies, int *params, int updated_2);
int			choose_enemy_3(t_game *game, t_enemies *enemies, int *params, int updated_3);
int			choose_enemy_4(t_game *game, t_enemies *enemies, int *params, int updated_4);
int			choose_enemy_5(t_game *game, t_enemies *enemies, int *params, int updated_5);
void			update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number, int i, int j);
int			three_free_spaces_1(t_game *game, int pos_x, int pos_y, int direction);
int			three_free_spaces_2(t_game *game, int pos_x, int pos_y, int direction);
int			three_free_spaces_3(t_game *game, int pos_x, int pos_y, int direction);
int			three_free_spaces_4(t_game *game, int pos_x, int pos_y, int direction);
void			assign_positions(t_game *game, int enemy_number, int pos_y, int pos_x);
int			two_free_spaces_0(t_game *game, int pos_y, int pos_x, int direction);
int			two_free_spaces_1(t_game *game, int pos_y, int pos_x, int direction);
int			two_free_spaces_2(t_game *game, int pos_y, int pos_x, int direction);
int			two_free_spaces_3(t_game *game, int pos_y, int pos_x, int direction);
int			two_free_spaces_4(t_game *game, int pos_y, int pos_x, int direction);
int			even_more_enemies_textures(t_textures *textures, void *mlx);
int			even_even_more_floors(t_textures *textures, void *mlx);
int			initial_player_textures(t_game *game, void *mlx);
void		draw_collectible(t_game *game, int i, int j, t_window *window);
void		check_collectible_line(t_map *map, char *line);
//int			one_free_space_3(int i, int pos_x, int pos_y, int direction)


#endif
