/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:53:29 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 19:11:29 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_more_collectible_animation(t_game *game)
{
	if (game->textures->collectible_animation_4)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_4);
		game->textures->collectible_animation_4 = NULL;
	}
	if (game->textures->collectible_animation_5)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_5);
		game->textures->collectible_animation_5 = NULL;
	}
	if (game->textures->collectible_destroyed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_destroyed);
		game->textures->collectible_destroyed = NULL;
	}
}

void	clean_more_floors(t_game *game)
{
	if (game->textures->floor_bot_right_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_right_corner);
		game->textures->floor_bot_right_corner = NULL;
	}
	if (game->textures->floor_top_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_closed);
		game->textures->floor_top_closed = NULL;
	}
	if (game->textures->floor_bot_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_closed);
		game->textures->floor_bot_closed = NULL;
	}
	if (game->textures->floor_left_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_closed);
		game->textures->floor_left_closed = NULL;
	}
	if (game->textures->floor_right_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_closed);
		game->textures->floor_right_closed = NULL;
	}
}

void	clean_even_more_floors(t_game *game)
{
	if (game->textures->floor_left_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_open);
		game->textures->floor_left_open = NULL;
	}
	if (game->textures->floor_right_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_open);
		game->textures->floor_right_open = NULL;
	}
	if (game->textures->floor_top_right_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_right_corner);
		game->textures->floor_top_right_corner = NULL;
	}
	if (game->textures->floor_top_left_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_left_corner);
		game->textures->floor_top_left_corner = NULL;
	}
	if (game->textures->floor_bot_left_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_left_corner);
		game->textures->floor_bot_left_corner = NULL;
	}
}

void	clean_floors(t_game *game)
{
	if (game->textures->floor_all_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_all_open);
		game->textures->floor_all_open = NULL;
	}
	if (game->textures->floor_top_bot)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_bot);
		game->textures->floor_top_bot = NULL;
	}
	if (game->textures->floor_left_right)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_right);
		game->textures->floor_left_right = NULL;
	}
	if (game->textures->floor_top_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_open);
		game->textures->floor_top_open = NULL;
	}
	if (game->textures->floor_bot_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_open);
		game->textures->floor_bot_open = NULL;
	}
}

void	clean_some_floors(t_game *game)
{
	if (game->textures->floor_all_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_all_open);
		game->textures->floor_all_open = NULL;
	}
	if (game->textures->floor_top_bot)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_bot);
		game->textures->floor_top_bot = NULL;
	}
	if (game->textures->floor_left_right)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_right);
		game->textures->floor_left_right = NULL;
	}
	if (game->textures->floor_top_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_open);
		game->textures->floor_top_open = NULL;
	}
	if (game->textures->floor_bot_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_open);
		game->textures->floor_bot_open = NULL;
	}
}
