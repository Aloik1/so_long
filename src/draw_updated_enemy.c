/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_updated_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:24:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 22:28:51 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_enemy_number(t_game *game, int pos_y, int pos_x, int animation)
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

void	draw_enemy(t_game *game, int direction, int animation, int pos_y, int pos_x)
{
	int	pixel_y;
	int	pixel_x;
	
	if (direction == 1)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_up_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_up_2_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_up_3_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_up_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_1, pixel_x, pixel_y);
		}
	}
	if (direction == 2)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_down_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_down_2_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_down_3_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_down_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_1, pixel_x, pixel_y);
		}
	}
	if (direction == 3)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_left_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_left_2_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_left_3_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_left_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_1, pixel_x, pixel_y);
		}
	}
	if (direction == 4)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_right_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_right_2_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_right_3_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = (pos_y - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_right_1_height) / 2;
			pixel_x = (pos_x - game->camera->y) * TILE_SIZE + 48 - 11;
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_1, pixel_x, pixel_y);
		}
	}
}
