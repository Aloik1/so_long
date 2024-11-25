/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spaces_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:55:19 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 02:30:10 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	two_free_spaces_0(t_game *game, int pos_y, int pos_x, int direction)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (game->map->map_aux[pos_y - 1][pos_x] == '0')
	{
		direction = direction - direction + 1;
		pos_y--;
	}
	else if (game->map->map_aux[pos_y + 1][pos_x] == '0')
	{
		direction = direction - direction + 2;
		pos_y++;
	}
	else if (game->map->map_aux[pos_y][pos_x - 1] == '0')
	{
		direction = direction - direction + 3;
		pos_x--;
	}
	else if (game->map->map_aux[pos_y][pos_x + 1] == '0')
	{
		direction = direction - direction + 4;
		pos_x++;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction);
}

int	two_free_spaces_1(t_game *game, int pos_y, int pos_x, int direction)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (game->map->map_aux[pos_y - 1][pos_x] == '0')
	{
		direction = direction - direction + 1;
		pos_y--;
	}
	else if (game->map->map_aux[pos_y][pos_x - 1] == '0')
	{
		direction = direction - direction + 3;
		pos_x--;
	}
	else if (game->map->map_aux[pos_y][pos_x + 1] == '0')
	{
		direction = direction - direction + 4;
		pos_x++;
	}
	else
	{
		direction = direction - direction + 2;
		pos_y++;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction);
}

int	two_free_spaces_2(t_game *game, int pos_y, int pos_x, int direction)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (game->map->map_aux[pos_y + 1][pos_x] == '0')
	{
		direction = direction - direction + 2;
		pos_y++;
	}
	else if (game->map->map_aux[pos_y][pos_x - 1] == '0')
	{
		direction = direction - direction + 3;
		pos_x--;
	}
	else if (game->map->map_aux[pos_y][pos_x + 1] == '0')
	{
		direction = direction - direction + 4;
		pos_x++;
	}
	else
	{
		direction = direction - direction + 1;
		pos_y--;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction);
}

int	two_free_spaces_3(t_game *game, int pos_y, int pos_x, int direction)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (game->map->map_aux[pos_y][pos_x - 1] == '0')
	{
		direction = direction - direction + 3;
		pos_x--;
	}
	else if (game->map->map_aux[pos_y - 1][pos_x] == '0')
	{
		direction = direction - direction + 1;
		pos_y--;
	}
	else if (game->map->map_aux[pos_y + 1][pos_x] == '0')
	{
		direction = direction - direction + 2;
		pos_y++;
	}
	else
	{
		direction = direction - direction + 4;
		pos_x++;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction);
}

int	two_free_spaces_4(t_game *game, int pos_y, int pos_x, int direction)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (game->map->map_aux[pos_y][pos_x + 1] == '0')
	{
		direction = direction - direction + 4;
		pos_x++;
	}
	else if (game->map->map_aux[pos_y - 1][pos_x] == '0')
	{
		direction = direction - direction + 1;
		pos_y--;
	}
	else if (game->map->map_aux[pos_y + 1][pos_x] == '0')
	{
		direction = direction - direction + 2;
		pos_y++;
	}
	else
	{
		direction = direction - direction + 3;
		pos_x--;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction);
}
