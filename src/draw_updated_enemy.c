/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_updated_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:24:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 02:20:43 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	determine_pixel_position_y(t_game *game, int pos_y)
{
	int	pixel_y;
	
	if (pos_y <= game->camera->y + game->camera->height
		&& pos_y >= game->camera->y)
		pixel_y = (pos_y - game->camera->y) * TILE_SIZE 
			+ 48 - (game->textures->enemy_up_1_height) / 2;
	else
		return (0);
	return (pixel_y);
}

int	determine_pixel_position_x(t_game *game, int pos_x)
{
	int	pixel_x;
	
	if (pos_x <= game->camera->x + game->camera->width
		&& pos_x >= game->camera->x)
		pixel_x = (pos_x - game->camera->x) * TILE_SIZE 
			+ 48 - (game->textures->enemy_up_1_width) / 2;
	else
		return (0);
	return (pixel_x);
}

void	check_enemy_number(t_game *game, int pos_y, int pos_x, int animation)
{
	if (pos_y == game->enemies->enemy_1_y && pos_x == game->enemies->enemy_1_x)
		game->textures->animation_1 = animation;
	if (pos_y == game->enemies->enemy_2_y && pos_x == game->enemies->enemy_2_x)
		game->textures->animation_2 = animation;
	if (pos_y == game->enemies->enemy_3_y && pos_x == game->enemies->enemy_3_x)
		game->textures->animation_3 = animation;
	if (pos_y == game->enemies->enemy_4_y && pos_x == game->enemies->enemy_4_x)
		game->textures->animation_4 = animation;
	if (pos_y == game->enemies->enemy_5_y && pos_x == game->enemies->enemy_5_x)
		game->textures->animation_5 = animation;
}

void	draw_enemy(t_game *game, int direction, int animation, int *coordinates)
{
	ft_printf("Inside draw enemy, enemy coordinates are: %d %d\n", coordinates[0], coordinates[1]);
	ft_printf("Direction is %d\n", direction);
	if (direction == 1)
		choose_enemy_up_1_2_3_4(game, animation, coordinates[0], coordinates[1]);
	if (direction == 2)
		choose_enemy_down_1_2_3_4(game, animation, coordinates[0], coordinates[1]);
	if (direction == 3)
		choose_enemy_left_1_2_3_4(game, animation, coordinates[0], coordinates[1]);
	if (direction == 4)
		choose_enemy_right_1_2_3_4(game, animation, coordinates[0], coordinates[1]);
}
