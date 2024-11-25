/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:35:24 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 03:02:04 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extra_enemies_textures(t_textures *textures, void *mlx)
{
	textures->enemy_right_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_right_3.xpm",
			&textures->enemy_right_3_width,
			&textures->enemy_right_3_height);
	if (!textures->enemy_right_3)
		return (0);
	textures->enemy_up_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_up_3.xpm",
			&textures->enemy_up_3_width,
			&textures->enemy_up_3_height);
	if (!textures->enemy_up_3)
		return (0);
	textures->enemy_down_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_down_1.xpm",
			&textures->enemy_down_1_width,
			&textures->enemy_down_1_height);
	if (!textures->enemy_down_1)
		return (0);
	return (1);
}

int	even_more_enemies_textures(t_textures *textures, void *mlx)
{
	textures->enemy_left_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_left_2.xpm",
			&textures->enemy_left_2_width,
			&textures->enemy_left_2_height);
	if (!textures->enemy_left_2)
		return (0);
	textures->enemy_left_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_left_3.xpm",
			&textures->enemy_left_3_width,
			&textures->enemy_left_3_height);
	if (!textures->enemy_left_3)
		return (0);
	textures->enemy_right_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_right_1.xpm",
			&textures->enemy_right_1_width,
			&textures->enemy_right_1_height);
	if (!textures->enemy_right_1)
		return (0);
	textures->enemy_right_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/enemies/enemy_right_2.xpm",
			&textures->enemy_right_2_width,
			&textures->enemy_right_2_height);
	if (!textures->enemy_right_2)
		return (0);
	return (1);
}

static int	even_more_positions_for_enemies(t_game *game,
		t_map *map, int i, int j)
{
	if (game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_5_y == 9999
		&& game->enemies->enemy_5_x == 9999)
	{
		game->enemies->enemy_5_y = i;
		game->enemies->enemy_5_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	return (0);
}

static int	more_positions_for_enemies(t_game *game, t_map *map, int i, int j)
{
	if (game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_3_y == 9999
		&& game->enemies->enemy_3_x == 9999)
	{
		game->enemies->enemy_3_y = i;
		game->enemies->enemy_3_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else if (game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_4_y == 9999
		&& game->enemies->enemy_4_x == 9999)
	{
		game->enemies->enemy_4_y = i;
		game->enemies->enemy_4_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else
		if (!even_more_positions_for_enemies(game, map, i, j))
			return (0);
	return (1);
}

int	positions_for_enemies(t_game *game, t_map *map, int i, int j)
{
	if (game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_1_y == 9999
		&& game->enemies->enemy_1_x == 9999)
	{
		game->enemies->enemy_1_y = i;
		game->enemies->enemy_1_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else if (game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_2_y == 9999
		&& game->enemies->enemy_2_x == 9999)
	{
		game->enemies->enemy_2_y = i;
		game->enemies->enemy_2_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else
		if (more_positions_for_enemies(game, map, i, j))
			return (1);
	return (0);
}
