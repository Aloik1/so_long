/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_player_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:13:45 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 19:15:21 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"\

void	clean_player_textures(t_game *game)
{
	if (game->textures->player_up_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_1);
		game->textures->player_up_1 = NULL;
	}
	if (game->textures->player_up_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_2);
		game->textures->player_up_2 = NULL;
	}
	if (game->textures->player_up_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_3);
		game->textures->player_up_3 = NULL;
	}
	if (game->textures->player_down_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_1);
		game->textures->player_down_1 = NULL;
	}
	if (game->textures->player_down_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_2);
		game->textures->player_down_2 = NULL;
	}
}

void	clean_more_player_textures(t_game *game)
{
	if (game->textures->player_down_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_3);
		game->textures->player_down_3 = NULL;
	}
	if (game->textures->player_left_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_1);
		game->textures->player_left_1 = NULL;
	}
	if (game->textures->player_left_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_2);
		game->textures->player_left_2 = NULL;
	}
	if (game->textures->player_left_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_3);
		game->textures->player_left_3 = NULL;
	}
	if (game->textures->player_right_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_1);
		game->textures->player_right_1 = NULL;
	}
}
