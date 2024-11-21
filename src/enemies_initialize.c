/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:08:16 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 23:16:10 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	more_enemies_textures(t_textures *textures, void *mlx)
{
	textures->enemy_down_2 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_down_2.xpm", &textures->enemy_down_2_width, &textures->enemy_down_2_height);
	if (!textures->enemy_down_2)
		return (0);
	textures->enemy_down_3 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_down_3.xpm", &textures->enemy_down_3_width, &textures->enemy_down_3_height);
	if (!textures->enemy_down_3)
		return (0);
	textures->enemy_left_1 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_left_1.xpm", &textures->enemy_left_1_width, &textures->enemy_left_1_height);
	if (!textures->enemy_left_1)
		return (0);
	textures->enemy_left_2 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_left_2.xpm", &textures->enemy_left_2_width, &textures->enemy_left_2_height);
	if (!textures->enemy_left_2)
		return (0);
	textures->enemy_left_3 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_left_3.xpm", &textures->enemy_left_3_width, &textures->enemy_left_3_height);
	if (!textures->enemy_left_3)
		return (0);
	textures->enemy_right_1 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_right_1.xpm", &textures->enemy_right_1_width, &textures->enemy_right_1_height);
	if (!textures->enemy_right_1)
		return (0);
	textures->enemy_right_2 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_right_2.xpm", &textures->enemy_right_2_width, &textures->enemy_right_2_height);
	if (!textures->enemy_right_2)
		return (0);
	textures->enemy_right_3 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_right_3.xpm", &textures->enemy_right_3_width, &textures->enemy_right_3_height);
	if (!textures->enemy_right_3)
		return (0);
	return (1);
}

static int	enemies_textures_init(t_textures *textures, void *mlx)
{
	textures->enemy_base = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_down.xpm", &textures->enemy_base_width, &textures->enemy_base_height);
	if (!textures->enemy_base)
		return (0);
	textures->enemy_up_1 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_up_1.xpm", &textures->enemy_up_1_width, &textures->enemy_up_1_height);
	if (!textures->enemy_up_1)
		return (0);
	textures->enemy_up_2 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_up_2.xpm", &textures->enemy_up_2_width, &textures->enemy_up_2_height);
	if (!textures->enemy_up_2)
		return (0);
	textures->enemy_up_3 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_up_3.xpm", &textures->enemy_up_3_width, &textures->enemy_up_3_height);
	if (!textures->enemy_up_3)
		return (0);
	textures->enemy_down_1 = mlx_xpm_file_to_image(mlx, "assets/textures/enemies/enemy_down_1.xpm", &textures->enemy_down_1_width, &textures->enemy_down_1_height);
	if (!textures->enemy_down_1)
		return (0);
	if (!more_enemies_textures(textures, mlx))
		return (0);
	return (1);
}

static void	enemies_init_positions(t_game *game, t_map *map, int number_of_enemies)
{
	int	i;
	int	j;

	i = rand() % (map->rows - 1) + 1;
	j = rand() % (map->cols - 1) + 1;
	if (game->map->map_grid[i][j] == '0')
	{
		game->enemies->enemy_1_y = i;
		game->enemies->enemy_1_x = j;
		map->map_grid[i][j] = 'X';
		number_of_enemies--;
		if (number_of_enemies != 0)
			enemies_init_positions(game, map, number_of_enemies);
		else
			return ;
	}
	else
		enemies_init_positions(game, map, number_of_enemies);
	return ;
}

static int	init_basic(t_game *game)
{
	game->enemies = (t_enemies *)malloc(sizeof(t_enemies));
	if (!game->enemies)
		return (0);
	game->enemies->number_of_enemies = 0;
	game->enemies->enemy_1_x = 9999;
	game->enemies->enemy_1_y = 9999;
	game->enemies->enemy_2_x = 9999;
	game->enemies->enemy_2_y = 9999;
	game->enemies->enemy_3_x = 9999;
	game->enemies->enemy_3_y = 9999;
	game->enemies->enemy_4_x = 9999;
	game->enemies->enemy_4_y = 9999;
	game->enemies->enemy_5_x = 9999;
	game->enemies->enemy_5_y = 9999;
	game->textures->direction_1 = 0;
	game->textures->direction_2 = 0;
	game->textures->direction_3 = 0;
	game->textures->direction_4 = 0;
	game->textures->direction_5 = 0;
	game->textures->animation_1 = 1;
	game->textures->animation_2 = 1;
	game->textures->animation_3 = 1;
	game->textures->animation_4 = 1;
	game->textures->animation_5 = 1;
	return (1);
}

int	enemies_init(t_game *game)
{
	if (!init_basic(game))
		return (0);
	if (game->map->rows <= 5 || game->map->cols <= 5)
		game->enemies->number_of_enemies = 1;
	else if (game->map->rows <= 10 || game->map->cols <= 10)
		game->enemies->number_of_enemies = 2;
	else if (game->map->rows <= 15 || game->map->cols <= 15)
		game->enemies->number_of_enemies = 3;
	else if (game->map->rows <= 20 || game->map->cols <= 20)
		game->enemies->number_of_enemies = 4;
	else if (game->map->rows > 20 || game->map->cols > 20)
		game->enemies->number_of_enemies = 5;
	enemies_init_positions(game, game->map, game->enemies->number_of_enemies);
	if (!enemies_textures_init(game->textures, game->window->mlx))
		return (0);
	return (1);
}
