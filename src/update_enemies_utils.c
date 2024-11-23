/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:25:57 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 17:07:58 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_enemy_1(t_game *game, t_enemies *enemies, int i, int j)
{
	game->textures->direction_1 = generate_direction(game, 
		update_enemy(game, enemies->enemy_1_y, enemies->enemy_1_x), 
			enemies->enemy_1_y, enemies->enemy_1_x, game->textures->direction_1);
	if (check_if_in_camera(game, i, j))
		draw_enemy(game, game->textures->direction_1, game->textures->animation_1, 
			enemies->enemy_1_y, enemies->enemy_1_x);
	return ;
}
void	update_enemy_2(t_game *game, t_enemies *enemies, int i, int j)
{
	game->textures->direction_2 = generate_direction(game, 
		update_enemy(game, enemies->enemy_2_y, enemies->enemy_2_x), 
			enemies->enemy_2_y, enemies->enemy_2_x, game->textures->direction_2);
	if (check_if_in_camera(game, i, j))
		draw_enemy(game, game->textures->direction_2, game->textures->animation_2, 
			enemies->enemy_2_y, enemies->enemy_2_x);
	return ;
}
void	update_enemy_3(t_game *game, t_enemies *enemies, int i, int j)
{
	game->textures->direction_3 = generate_direction(game, 
		update_enemy(game, enemies->enemy_3_y, enemies->enemy_3_x), 
			enemies->enemy_3_y, enemies->enemy_3_x, game->textures->direction_3);
	if (check_if_in_camera(game, i, j))
		draw_enemy(game, game->textures->direction_3, game->textures->animation_3, 
			enemies->enemy_3_y, enemies->enemy_3_x);
	return ;
}
void	update_enemy_4(t_game *game, t_enemies *enemies, int i, int j)
{
	game->textures->direction_4 = generate_direction(game, 
		update_enemy(game, enemies->enemy_4_y, enemies->enemy_4_x), 
			enemies->enemy_4_y, enemies->enemy_4_x, game->textures->direction_4);
	if (check_if_in_camera(game, i, j))
		draw_enemy(game, game->textures->direction_4, game->textures->animation_4, 
			enemies->enemy_4_y, enemies->enemy_4_x);
	return ;
}

void	update_enemy_5(t_game *game, t_enemies *enemies, int i, int j)
{
	game->textures->direction_5 = generate_direction(game, 
		update_enemy(game, enemies->enemy_5_y, enemies->enemy_5_x), 
			enemies->enemy_5_y, enemies->enemy_5_x, game->textures->direction_5);
	if (check_if_in_camera(game, i, j))
		draw_enemy(game, game->textures->direction_5, game->textures->animation_5, 
			enemies->enemy_5_y, enemies->enemy_5_x);
	return ;
}