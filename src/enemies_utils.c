/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:35:24 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 16:12:17 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	more_positions_for_enemies(t_game *game, t_map *map, int i, int j)
{
	if(game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_4_y == 9999
		&& game->enemies->enemy_4_x == 9999)
	{
		game->enemies->enemy_4_y = i;
		game->enemies->enemy_4_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else if(game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_5_y == 9999
		&& game->enemies->enemy_5_x == 9999)
	{
		game->enemies->enemy_5_y = i;
		game->enemies->enemy_5_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else
		return (0);
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
	else if(game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_2_y == 9999
		&& game->enemies->enemy_2_x == 9999)
	{
		game->enemies->enemy_2_y = i;
		game->enemies->enemy_2_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else if(game->map->map_grid[i][j] == '0'
		&& game->enemies->enemy_3_y == 9999
		&& game->enemies->enemy_3_x == 9999)
	{
		game->enemies->enemy_3_y = i;
		game->enemies->enemy_3_x = j;
		map->map_grid[i][j] = 'X';
		return (1);
	}
	else
		if (more_positions_for_enemies(game, map, i, j))
			return (1);
	return (0);
}
