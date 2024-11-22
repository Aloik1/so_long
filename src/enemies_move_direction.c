/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:11:22 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 21:05:08 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	assign_positions(t_game *game, int enemy_number, int pos_y, int pos_x)
{
	if (enemy_number == 1)
	{
		game->enemies->enemy_1_y = pos_y;
		game->enemies->enemy_1_x = pos_x;
	}
	if (enemy_number == 2)
	{
		game->enemies->enemy_2_y = pos_y;
		game->enemies->enemy_2_x = pos_x;
	}
	if (enemy_number == 3)
	{
		game->enemies->enemy_3_y = pos_y;
		game->enemies->enemy_3_x = pos_x;
	}
	if (enemy_number == 4)
	{
		game->enemies->enemy_4_y = pos_y;
		game->enemies->enemy_4_x = pos_x;
	}
	if (enemy_number == 5)
	{
		game->enemies->enemy_5_y = pos_y;
		game->enemies->enemy_5_x = pos_x;
	}
}

static int	four_free_spaces(t_game *game, int pos_y, int pos_x, int direction, int enemy_number)
{
	int	i;

	i = (rand() % 4) + 1;
	if (i == 1)
	{
		pos_y--;
		direction = direction - direction + 1;
	}
	else if (i == 2)
	{
		pos_y++;
		direction = direction - direction + 2;
	}
	else if (i == 3)
	{
		pos_x--;
		direction = direction - direction + 3;
	}
	else
	{
		pos_x++;
		direction = direction - direction + 4;
	}
	assign_positions(game, enemy_number, pos_y, pos_x); //assigns new position
	return (direction);
}

static int	three_free_spaces(t_game *game, int pos_y, int pos_x, int direction, int enemy_number)
{
	int	i;

	direction = 0;
	i = (rand() % 3) + 1;
	if (i == 1 && game->map->map_aux[pos_y - 1][pos_x] == '0')
	{
		pos_y--;
		direction = direction + 1;
	}
	else if (i == 1 && game->map->map_aux[pos_y - 1][pos_x] == '1')
		i = 2;
	if (i == 2 && game->map->map_aux[pos_y + 1][pos_x] == '0')
	{
		pos_y++;
		direction = direction + 2;
	}
	else if (i == 2 && game->map->map_aux[pos_y + 1][pos_x] == '1')
		i = 3;
	if (i == 3 && game->map->map_aux[pos_y][pos_x - 1] == '0')
	{
		pos_x--;
		direction = direction + 3;
	}
	else if (i == 3 && game->map->map_aux[pos_y][pos_x + 1] == '0')
	{
		pos_x++;
		direction = direction + 4;
	}
	assign_positions(game, enemy_number, pos_y, pos_x);
	
	return (direction);
}

static int	two_free_spaces(t_game *game, int pos_y, int pos_x, int direction, int enemy_number)
{
	if (direction == 0)
	{
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
	else if (direction == 1)
	{
		if (game->map->map_aux[pos_y - 1][pos_x] == '0')
		{
			direction = direction - direction + 1;
			pos_y--;
		}
		else
		{
			if (game->map->map_aux[pos_y][pos_x - 1] == '0')
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
		}
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (direction);
	}
	else if (direction == 2)
	{
		if (game->map->map_aux[pos_y + 1][pos_x] == '0')
		{
			direction = direction - direction + 2;
			pos_y++;
		}
		else
		{
			if (game->map->map_aux[pos_y][pos_x - 1] == '0')
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
		}
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (direction);
	}
	else if (direction == 3)
	{
		if (game->map->map_aux[pos_y][pos_x - 1] == '0')
		{
			direction = direction - direction + 3;
			pos_x--;
		}
		else
		{
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
			else
			{
				direction = direction - direction + 4;
				pos_x++;
			}
		}
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (direction);
	}
	if (direction == 4)
	{
		if (game->map->map_aux[pos_y][pos_x + 1] == '0')
		{
			direction = direction - direction + 4;
			pos_x++;
		}
		else
		{
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
			else
			{
				direction = direction - direction + 3;
				pos_x--;
			}
		}
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (direction);
	}
	return (0);
}


static int	one_free_space(t_game *game, int pos_y, int pos_x, int direction, int enemy_number)
{
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
		direction = direction -direction + 3;
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

int	generate_direction(t_game *game, int free_spaces, int pos_y, int pos_x, int direction)
{
	int	enemy_number;
	
	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (free_spaces == 4)
		direction = four_free_spaces(game, pos_y, pos_x, direction, enemy_number);
	if (free_spaces == 3)
		direction = three_free_spaces(game, pos_y, pos_x, direction, enemy_number);
	if (free_spaces == 2)
		direction = two_free_spaces(game, pos_y, pos_x, direction, enemy_number);
	if (free_spaces == 1)
		direction = one_free_space(game, pos_y, pos_x, direction, enemy_number);
	return (direction);
}
