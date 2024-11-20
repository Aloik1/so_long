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

typedef struct s_collectible_position
{
	int		x; // column
	int		y; // row
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
	int		x; // column
	int		y; // row
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
	void			*floor_img;//
	void			*floor_all_open;//
	void			*floor_top_bot;//
	void			*floor_left_right;//
	void			*floor_top_open;//
	void			*floor_bot_open;//
	void			*floor_left_open;//
	void			*floor_right_open;//
	void			*floor_top_right_corner;//
	void			*floor_top_left_corner;//
	void			*floor_bot_right_corner;//
	void			*floor_bot_left_corner;//
	void			*floor_top_closed;//
	void			*floor_bot_closed;//
	void			*floor_left_closed;//
	void			*floor_right_closed;//

	void			*wall_top_img;//

	void			*collectible_image;
	void			*collectible_animation_1;//
	void			*collectible_animation_2;//
	void			*collectible_animation_3;//
	void			*collectible_animation_4;//
	void			*collectible_animation_5;//
	void			*collectible_destroyed;//

	void			*exit_closed;//
	void			*exit_open;//

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

}	t_game;

// function prototypes
int			basic_check(int argc, char **argv);
int			read_map(char *file, t_game *game);
int			window_and_mlx(t_window **window);
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
void			redraw_everything(t_game *game, t_textures *textures);
void			update_camera(t_camera *camera, t_player *player, t_map *map);
void			camera_init(t_camera *camera, t_player *player, t_map *map);
int			collect_collectible(t_game *game, t_player *player);
int			open_exit(t_map *map, t_player *player, t_game *game);
void			draw_exit(t_game *game, t_window *window, t_textures *textures, t_camera *camera);
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

#endif
