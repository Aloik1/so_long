/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:51:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_collectible_animation(t_game *game)
{
	if (game->textures->collectible_image)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_image);
		game->textures->collectible_image = NULL;
	}
	if (game->textures->collectible_animation_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_1);
		game->textures->collectible_animation_1 = NULL;
	}
	if (game->textures->collectible_animation_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_2);
		game->textures->collectible_animation_2 = NULL;
	}
	if (game->textures->collectible_animation_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_3);
		game->textures->collectible_animation_3 = NULL;
	}
	clean_more_collectible_animation(game);
}

static void	free_exit(t_game *game)
{
	if (game->textures->exit_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->exit_closed);
		game->textures->exit_closed = NULL;
	}
	if (game->textures->exit_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->exit_open);
		game->textures->exit_open = NULL;
	}
}

static void	free_player(t_game *game)
{
	clean_player_textures(game);
	clean_more_player_textures(game);
	if (game->textures->player_right_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_2);
		game->textures->player_right_2 = NULL;
	}
	if (game->textures->player_right_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_3);
		game->textures->player_right_3 = NULL;
	}
	if (game->player->player_texture)
	{
		mlx_destroy_image(game->window->mlx, game->player->player_texture);
		game->textures->player_img = NULL;
	}
}

void	free_textures(t_game *game)
{
	
	clean_some_floors(game);
	clean_floors(game);
	clean_more_floors(game);
	clean_even_more_floors(game);

	free_collectible_animation(game);
	free_exit(game);
	if (game->textures->wall_top_img)
	{
		mlx_destroy_image(game->window->mlx, game->textures->wall_top_img);
		game->textures->wall_top_img = NULL;
	}
	free_player(game);
	free(game->textures);
	game->textures = NULL;
}

int clean_exit(t_game *game)
{
	if (!game)
		exit(1);
	if (game->textures)
		free_textures(game);
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	if (game->movement)
		free(game->movement);
	if (game->camera)
		free(game->camera);
	cilit_bang(game);
	free(game);
	game = NULL;
	exit(0);
	return (0);
}
