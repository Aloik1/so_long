/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:29:18 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 23:19:51 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static void	update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number)
{

	if (enemy_number == 1)
	{
		game->textures->direction_1 = generate_direction(game, update_enemy(game, enemies->enemy_1_y, enemies->enemy_1_x), enemies->enemy_1_y, enemies->enemy_1_x, game->textures->direction_1);
		draw_enemy(game, game->textures->direction_1, game->textures->animation_1, enemies->enemy_1_y, enemies->enemy_1_x);
	}
	if (enemy_number == 2)
	{
		game->textures->direction_2 = generate_direction(game, update_enemy(game, enemies->enemy_2_y, enemies->enemy_2_x), enemies->enemy_2_y, enemies->enemy_2_x, game->textures->direction_2);
		draw_enemy(game, game->textures->direction_2, game->textures->animation_2, enemies->enemy_2_y, enemies->enemy_2_x);
	}
	if (enemy_number == 3)
	{
		game->textures->direction_3 = generate_direction(game, update_enemy(game, enemies->enemy_3_y, enemies->enemy_3_x), enemies->enemy_3_y, enemies->enemy_3_x, game->textures->direction_3);
		draw_enemy(game, game->textures->direction_3, game->textures->animation_3, enemies->enemy_3_y, enemies->enemy_3_x);
	}
	if (enemy_number == 4)
	{
		game->textures->direction_4 = generate_direction(game, update_enemy(game, enemies->enemy_4_y, enemies->enemy_4_x), enemies->enemy_4_y, enemies->enemy_4_x, game->textures->direction_4);
		draw_enemy(game, game->textures->direction_4, game->textures->animation_4, enemies->enemy_4_y, enemies->enemy_4_x);
	}
	if (enemy_number == 5)
	{
		game->textures->direction_5 = generate_direction(game, update_enemy(game, enemies->enemy_5_y, enemies->enemy_5_x), enemies->enemy_5_y, enemies->enemy_5_x, game->textures->direction_5);
		draw_enemy(game, game->textures->direction_5, game->textures->animation_5, enemies->enemy_5_y, enemies->enemy_5_x);
	}
}

void	enemies_movement(t_game *game, t_enemies *enemies)
{
	int	i;
	int	j;
	
	i = game->camera->y;
	while (i < game->camera->y + game->camera->height && i < game->map->rows)
	{
		j = game->camera->x;
		while (j < game->camera->x + game->camera->width && j < game->map->cols)
		{	
			if ((enemies->enemy_1_y == i && enemies->enemy_1_x == j)
				|| (enemies->enemy_2_y == i && enemies->enemy_2_x == j)
				|| (enemies->enemy_3_y == i && enemies->enemy_3_x == j)
				|| (enemies->enemy_4_y == i && enemies->enemy_5_x == j)
				|| (enemies->enemy_5_y == i && enemies->enemy_5_x == j))
			{
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j));
				return ;
			}
			
			j++;
		}
		i++;
	}
}
