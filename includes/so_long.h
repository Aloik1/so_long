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
	int		**positions;
}	t_collectible_position;

typedef struct s_exit_position
{
	int		x; // column
	int		y; // row
}	t_exit_position;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		collectibles;
	int		exits;
	int		players;
	char		**map_grid;
	t_collectible_position	*collectible;
	t_exit_position		*exit;
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
	void	*floor_img;
	void	*wall_top_img;
	void	*wall_bottom_img;
	void	*wall_left_img;
	void	*wall_right_img;
	void	*collectible_1_img;
	void	*collectible_2_img;
	void	*collectible_3_img;
	void	*collectible_4_img;
	void	*collectible_5_img;
	void	*exit_img;
	void	*player_img;
	int		collectible_1_width;
	int		collectible_1_height;
	int		collectible_2_width;
	int		collectible_2_height;
	int		collectible_3_width;
	int		collectible_3_height;
	int		collectible_4_width;
	int		collectible_4_height;
	int		collectible_5_width;
	int		collectible_5_height;
	int		floor_width;
	int		floor_height;
	int		wall_top_width;
	int		wall_top_height;
	int		wall_bottom_width;
	int		wall_bottom_height;
	int		wall_left_width;
	int		wall_left_height;
	int		wall_right_width;
	int		wall_right_height;
	int		exit_width;
	int		exit_height;
	int		player_width;
	int		player_height;
}	t_textures;

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
}	t_game;


// global variables
extern t_textures	textures;
// function prototypes
int			basic_check(int argc, char **argv);
int			read_map(char *file, t_map **map);
int			window_and_mlx(t_window **window);
int			flood_check(t_map *map, t_player_position player_position);
void			free_map(t_map *map);
t_player_position	return_null_player(void);
t_collectible_position	return_null_and_free_collectibles(t_collectible_position collectibles);
t_exit_position		return_null_exit(void);
int			path_checks(t_map *map);
int			map_checks(t_map *map);
int			draw_map(t_map *map, t_window *window, t_camera *camera);
int			init_player(t_map *map, t_window *window, t_player *player);
int			draw_player(t_window *window, t_player *player, t_camera *camera);
int			movement(int keycode, t_game *game, t_textures *textures);
void			redraw_everything(t_game *game);
void			update_camera(t_camera *camera, t_player *player, t_map *map);
void			camera_init(t_camera *camera, t_player *player, t_map *map);
int			collect_collectible(t_game *game, t_player *player);
void			open_exit(t_map *map, t_player *player, t_game *game, t_textures *textures);
void			draw_exit(t_map *map, t_window *window, t_textures *textures, t_camera *camera);
void			clean_exit(t_game *game, t_textures *textures);

#endif
