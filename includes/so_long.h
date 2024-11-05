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

# define TILE_SIZE 	64
# define KEY_W 		119
# define KEY_A 		97
# define KEY_S 		115
# define KEY_D 		100
# define KEY_ESC 	65307
# define KEY_PRESS 	2
# define KEY_RELEASE 	3
# define DESTROY_NOTIFY 17 // event code for window close
# define WIN_WIDTH 	960 // 960 x 540 window size
# define WIN_HEIGHT 	540 //
# define VIEW_RANGE 	10 // 10 tiles visible in the view

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int		win_width;
	int		win_height;
}	t_window;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		collectibles;
	int		exits;
	int		players;
	char		**map_grid;
}	t_map;

typedef struct s_player_position
{
	int		x; // column
	int		y; // row
}	t_player_position;

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

#endif
