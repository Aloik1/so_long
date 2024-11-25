/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move_direction_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:05:47 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 03:03:40 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	assign_positions(t_game *game, int enemy_number, int pos_y, int pos_x)
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

int	four_free_spaces_3_4(t_game *game, int pos_y, int pos_x, int i)
{
	int	enemy_number;

	enemy_number = determine_enemy(game->enemies, pos_y, pos_x);
	if (i == 3)
	{
		pos_x--;
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (3);
	}
	else
	{
		pos_x++;
		assign_positions(game, enemy_number, pos_y, pos_x);
		return (4);
	}
	return (0);
}
