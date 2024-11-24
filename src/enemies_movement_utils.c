/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:34:58 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 00:04:22 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	choose_enemy_1(t_game *game, t_enemies *enemies, int *params, int updated_1)
{
	if (enemies->enemy_1_y == params[0] && enemies->enemy_1_x == params[1] && updated_1 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, params[0], params[1]), params[0], params[1]);
		return (1);
	}
	else if (updated_1 == 1)
		return (1);
	return (0);
}

int	choose_enemy_2(t_game *game, t_enemies *enemies, int *params, int updated_2)
{
	if (enemies->enemy_2_y == params[0] && enemies->enemy_2_x == params[1] && updated_2 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, params[0], params[1]), params[0], params[1]);
		return (1);
	}
	else if (updated_2 == 1)
		return (1);
	return (0);
}

int	choose_enemy_3(t_game *game, t_enemies *enemies, int *params, int updated_3)
{
	if (enemies->enemy_3_y == params[0] && enemies->enemy_3_x == params[1] && updated_3 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, params[0], params[1]), params[0], params[1]);
		return (1);
	}
	else if (updated_3 == 1)
		return (1);
	return (0);
}

int	choose_enemy_4(t_game *game, t_enemies *enemies, int *params, int updated_4)
{
	if (enemies->enemy_4_y == params[0] && enemies->enemy_4_x == params[1] && updated_4 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, params[0], params[1]), params[0], params[1]);
		return (1);
	}
	else if (updated_4 == 1)
		return (1);
	return (0);
}

int	choose_enemy_5(t_game *game, t_enemies *enemies, int *params, int updated_5)
{
	if (enemies->enemy_5_y == params[0] && enemies->enemy_5_x == params[1] && updated_5 == 0)
	{
		update_enemies_position(game, enemies, determine_enemy(enemies, params[0], params[1]), params[0], params[1]);
		return (1);
	}
	else if (updated_5 == 1)
		return (1);
	return (0);
}
