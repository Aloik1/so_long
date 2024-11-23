/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:34:58 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 15:13:19 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	choose_enemy_1(t_game *game, t_enemies *enemies, int i, int j, int updated_1)
{
	if (enemies->enemy_1_y == i && enemies->enemy_1_x == j && updated_1 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
		return (1);
	}
	else if (updated_1 == 1)
		return (1);
	return (0);
}

int	choose_enemy_2(t_game *game, t_enemies *enemies, int i, int j, int updated_2)
{
	if (enemies->enemy_2_y == i && enemies->enemy_2_x == j && updated_2 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
		return (1);
	}
	else if (updated_2 == 1)
		return (1);
	return (0);
}

int	choose_enemy_3(t_game *game, t_enemies *enemies, int i, int j, int updated_3)
{
	if (enemies->enemy_3_y == i && enemies->enemy_3_x == j && updated_3 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
		return (1);
	}
	else if (updated_3 == 1)
		return (1);
	return (0);
}

int	choose_enemy_4(t_game *game, t_enemies *enemies, int i, int j, int updated_4)
{
	if (enemies->enemy_4_y == i && enemies->enemy_4_x == j && updated_4 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
		return (1);
	}
	else if (updated_4 == 1)
		return (1);
	return (0);
}

int	choose_enemy_5(t_game *game, t_enemies *enemies, int i, int j, int updated_5)
{
	if (enemies->enemy_5_y == i && enemies->enemy_5_x == j && updated_5 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
		return (1);
	}
	else if (updated_5 == 1)
		return (1);
	return (0);
}
