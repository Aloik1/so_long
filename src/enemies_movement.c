/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:29:18 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 21:38:18 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_if_in_camera(t_game *game, int i, int j)
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

static void	update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number, int i, int j)
{
	if (enemy_number == 1)
	{
		game->textures->direction_1 = generate_direction(game, update_enemy(game, enemies->enemy_1_y, enemies->enemy_1_x), enemies->enemy_1_y, enemies->enemy_1_x, game->textures->direction_1);
		if (check_if_in_camera(game, i, j))
		{
			draw_enemy(game, game->textures->direction_1, game->textures->animation_1, enemies->enemy_1_y, enemies->enemy_1_x);
		}
		return ;
	}
	if (enemy_number == 2)
	{
		game->textures->direction_2 = generate_direction(game, update_enemy(game, enemies->enemy_2_y, enemies->enemy_2_x), enemies->enemy_2_y, enemies->enemy_2_x, game->textures->direction_2);
		if (check_if_in_camera(game, i, j))
		{
			draw_enemy(game, game->textures->direction_2, game->textures->animation_2, enemies->enemy_2_y, enemies->enemy_2_x);
		}
		return ;
	}
	if (enemy_number == 3)
	{
		game->textures->direction_3 = generate_direction(game, update_enemy(game, enemies->enemy_3_y, enemies->enemy_3_x), enemies->enemy_3_y, enemies->enemy_3_x, game->textures->direction_3);
		if (check_if_in_camera(game, i, j))
		{
			draw_enemy(game, game->textures->direction_3, game->textures->animation_3, enemies->enemy_3_y, enemies->enemy_3_x);
		}
		return ;
	}
	if (enemy_number == 4)
	{
		game->textures->direction_4 = generate_direction(game, update_enemy(game, enemies->enemy_4_y, enemies->enemy_4_x), enemies->enemy_4_y, enemies->enemy_4_x, game->textures->direction_4);
		if (check_if_in_camera(game, i, j))
		{
			draw_enemy(game, game->textures->direction_4, game->textures->animation_4, enemies->enemy_4_y, enemies->enemy_4_x);
		}
		return ;
	}
	if (enemy_number == 5)
	{
		game->textures->direction_5 = generate_direction(game, update_enemy(game, enemies->enemy_5_y, enemies->enemy_5_x), enemies->enemy_5_y, enemies->enemy_5_x, game->textures->direction_5);
		if (check_if_in_camera(game, i, j))
		{
			draw_enemy(game, game->textures->direction_5, game->textures->animation_5, enemies->enemy_5_y, enemies->enemy_5_x);
		}
		return ;
	}
}

void	enemies_movement(t_game *game, t_enemies *enemies)
{
	int	i;
	int	j;
	int	updated_1;
	int	updated_2;
	int	updated_3;
	int	updated_4;
	int	updated_5;
	
	updated_1 = 0;
	updated_2 = 0;
	updated_3 = 0;
	updated_4 = 0;
	updated_5 = 0;
	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{	
			if (enemies->enemy_1_y == i && enemies->enemy_1_x == j 
				&& updated_1 == 0)
			{
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_1++;
			}
			if (enemies->enemy_2_y == i && enemies->enemy_2_x == j 
				&& updated_2 == 0)
			{				
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_2++;
			}
			if (enemies->enemy_3_y == i && enemies->enemy_3_x == j
				&& updated_3 == 0)
			{
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_3++;
			}
			if (enemies->enemy_4_y == i && enemies->enemy_4_x == j
				&& updated_4 == 0)
			{
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_4++;
			}
			if (enemies->enemy_5_y == i && enemies->enemy_5_x == j
				&& updated_5 == 0)
			{
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_5++;
			}
			j++;
		}
		i++;
	}
	return ;
}
