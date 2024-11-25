/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:29:18 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 02:28:04 by aloiki           ###   ########.fr       */
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

void	update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number, int *coordinates)
{
	if (enemy_number == 1)
		update_enemy_1(game, enemies, coordinates[0], coordinates[1]);
	if (enemy_number == 2)
		update_enemy_2(game, enemies, coordinates[0], coordinates[1]);
	if (enemy_number == 3)
		update_enemy_3(game, enemies, coordinates[0], coordinates[1]);
	if (enemy_number == 4)
		update_enemy_4(game, enemies, coordinates[0], coordinates[1]);
	if (enemy_number == 5)
		update_enemy_5(game, enemies, coordinates[0], coordinates[1]);
}

void	enemies_movement(t_game *game, t_enemies *enemies, int *updated)
{
	int	i;
	int	j;
	int	*params;
	
	params = malloc(sizeof(int) * 2);
	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			params[0] = i;
			params[1] = j;
			updated[0] = choose_enemy_1(game, enemies, params, updated[0]);
			updated[1] = choose_enemy_2(game, enemies, params, updated[1]);
			updated[2] = choose_enemy_3(game, enemies, params, updated[2]);
			updated[3] = choose_enemy_4(game, enemies, params, updated[3]);
			updated[4] = choose_enemy_5(game, enemies, params, updated[4]);
			j++;
		}
		i++;
	}
	free(params);
	free(updated);
}
