/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_enemies_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:24:15 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 02:33:29 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_even_more_enemies(t_game *game)
{
	if (game->textures->enemy_left_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_left_3);
		game->textures->enemy_left_3 = NULL;
	}
	if (game->textures->enemy_right_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_right_1);
		game->textures->enemy_right_1 = NULL;
	}
	if (game->textures->enemy_right_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_right_2);
		game->textures->enemy_right_2 = NULL;
	}
	if (game->textures->enemy_right_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_right_3);
		game->textures->enemy_right_3 = NULL;
	}
}

static void	free_more_enemies(t_game *game)
{
	if (game->textures->enemy_down_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_down_1);
		game->textures->enemy_down_1 = NULL;
	}
	if (game->textures->enemy_down_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_down_2);
		game->textures->enemy_down_2 = NULL;
	}
	if (game->textures->enemy_down_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_down_3);
		game->textures->enemy_down_3 = NULL;
	}
	if (game->textures->enemy_left_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_left_1);
		game->textures->enemy_left_1 = NULL;
	}
	if (game->textures->enemy_left_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_left_2);
		game->textures->enemy_left_2 = NULL;
	}
}

void	free_enemies(t_game *game)
{
	if (game->textures->enemy_base)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_base);
		game->textures->enemy_base = NULL;
	}
	if (game->textures->enemy_up_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_up_1);
		game->textures->enemy_up_1 = NULL;
	}
	if (game->textures->enemy_up_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_up_2);
		game->textures->enemy_up_2 = NULL;
	}
	if (game->textures->enemy_up_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->enemy_up_3);
		game->textures->enemy_up_2 = NULL;
	}
	free_more_enemies(game);
	free_even_more_enemies(game);
}
