/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_up_down.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:45 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 16:59:01 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	choose_enemy_up_3_4(t_game *game, int animation, int pos_y, int pos_x)
{
	int	pixel_y;
	int	pixel_x;
	
	if (animation == 3)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_up_3, pixel_x, pixel_y);
	}
	else
	{
		animation = 1;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_up_1, pixel_x, pixel_y);
	}	
}

void	choose_enemy_up_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x)
{
	int	pixel_y;
	int	pixel_x;
	
	if (animation == 1)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_up_1, pixel_x, pixel_y);
	}
	else if (animation == 2)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_up_2, pixel_x, pixel_y);
	}
	else
		choose_enemy_up_3_4(game, animation, pos_y, pos_x);
}

static void	choose_enemy_down_3_4(t_game *game, int animation, int pos_y, int pos_x)
{
	int	pixel_y;
	int	pixel_x;
	
	if (animation == 3)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_down_3, pixel_x, pixel_y);
	}
	else
	{
		animation = 1;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_down_1, pixel_x, pixel_y);
	}
}

void	choose_enemy_down_1_2_3_4(t_game *game, int animation, int pos_y, int pos_x)
{
	int	pixel_y;
	int	pixel_x;

	if (animation == 1)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_down_1, pixel_x, pixel_y);
	}
	else if (animation == 2)
	{
		animation++;
		check_enemy_number(game, pos_y, pos_x, animation);
		pixel_y = determine_pixel_position_y(game, pos_y);
		pixel_x = determine_pixel_position_x(game, pos_x);
		if (pixel_y > 0 && pixel_x > 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win, 
				game->textures->enemy_down_2, pixel_x, pixel_y);
	}
	else
		choose_enemy_down_3_4(game, animation, pos_y, pos_x);
}


