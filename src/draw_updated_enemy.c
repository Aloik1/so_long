/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_updated_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:24:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 21:44:32 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	determine_pixel_position_y(t_game *game, int pos_y)
{
	int	pixel_y;
	
	if (pos_y <= game->camera->y + game->camera->height
		&& pos_y >= game->camera->y)
		pixel_y = (pos_y - game->camera->y) * TILE_SIZE + 48 - (game->textures->enemy_up_1_height) / 2;
	else
		return (0);
	return (pixel_y);
}

static int	determine_pixel_position_x(t_game *game, int pos_x)
{
	int	pixel_x;
	
	if (pos_x <= game->camera->x + game->camera->width
		&& pos_x >= game->camera->x)
		pixel_x = (pos_x - game->camera->x) * TILE_SIZE + 48 - (game->textures->enemy_up_1_width) / 2;
	else
		return (0);
	return (pixel_x);
}

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
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_up_1, pixel_x, pixel_y);
		}
	}
	if (direction == 2)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_down_1, pixel_x, pixel_y);
		}
	}
	if (direction == 3)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)	
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_left_1, pixel_x, pixel_y);
		}
	}
	if (direction == 4)
	{
		if (animation == 1)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_1, pixel_x, pixel_y);
		}
		else if (animation == 2)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_2, pixel_x, pixel_y);
		}
		else if (animation == 3)
		{
			animation++;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_3, pixel_x, pixel_y);
		}
		else
		{
			animation = 1;
			check_enemy_number(game, pos_y, pos_x, animation);
			pixel_y = determine_pixel_position_y(game, pos_y);
			pixel_x = determine_pixel_position_x(game, pos_x);
			if (pixel_y > 0 && pixel_x > 0)
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->textures->enemy_right_1, pixel_x, pixel_y);
		}
	}
}
