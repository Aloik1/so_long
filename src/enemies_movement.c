/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:29:18 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 15:05:49 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_if_in_camera(t_game *game, int i, int j)
{
	if (i <= game->camera->y + game->camera->height && i <= game->map->rows
		&& i >= game->camera->y
		&& j <= game->camera->x + game->camera->width && j < game->map->cols
		&& j >= game->camera->x)
		return (1);
	return (0);
}

int	determine_enemy(t_enemies *enemies, int i, int j)
{
	if (enemies->enemy_1_y == i && enemies->enemy_1_x == j)
		return (1);
	if (enemies->enemy_2_y == i && enemies->enemy_2_x == j)
		return (2);
	if (enemies->enemy_3_y == i && enemies->enemy_3_x == j)
		return (3);
	if (enemies->enemy_4_y == i && enemies->enemy_4_x == j)
		return (4);
	if (enemies->enemy_5_y == i && enemies->enemy_5_x == j)
		return (5);
	return (0);
}

void	update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number, int i, int j)
{
	if (enemy_number == 1)
		update_enemy_1(game, enemies, i, j);
	if (enemy_number == 2)
		update_enemy_2(game, enemies, i, j);
	if (enemy_number == 3)
		update_enemy_3(game, enemies, i, j);
	if (enemy_number == 4)
		update_enemy_4(game, enemies, i, j);
	if (enemy_number == 5)
		update_enemy_5(game, enemies, i, j);
}

void	enemies_movement(t_game *game, t_enemies *enemies, int updated_1, int updated_2, int updated_3)
{
	int	i;
	int	j;
	int	updated_4;
	int	updated_5;
	
	updated_4 = 0;
	updated_5 = 0;
	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{	
			updated_1 = choose_enemy_1(game, enemies, i, j, updated_1);
			updated_2 = choose_enemy_2(game, enemies, i, j, updated_2);
			updated_3 = choose_enemy_3(game, enemies, i, j, updated_3);
			updated_4 = choose_enemy_4(game, enemies, i, j, updated_4);
			updated_5 = choose_enemy_5(game, enemies, i, j, updated_5);
			j++;
		}
		i++;
	}
}
