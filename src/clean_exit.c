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


void	free_textures(t_game *game)
{
	// if (game->textures->collectible_1_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->collectible_1_img);
	// if (game->textures->collectible_2_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->collectible_2_img);
	// if (game->textures->collectible_3_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->collectible_3_img);
	// if (game->textures->collectible_4_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->collectible_4_img);
	// if (game->textures->collectible_5_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->collectible_5_img);
	if (game->textures->floor_all_open)
		mlx_destroy_image(game->window->mlx, game->textures->floor_all_open);
	if (game->textures->floor_top_bot)
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_bot);
	if (game->textures->floor_left_right)
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_right);
	if (game->textures->floor_top_open)
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_open);
	if (game->textures->floor_bot_open)
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_open);
	if (game->textures->floor_left_open)
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_open);
	if (game->textures->floor_right_open)
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_open);
	if (game->textures->floor_top_right_corner)
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_right_corner);
	if (game->textures->floor_top_left_corner)
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_left_corner);
	if (game->textures->floor_bot_left_corner)
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_left_corner);
	if (game->textures->floor_bot_right_corner)
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_right_corner);
	if (game->textures->floor_top_closed)
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_closed);
	if (game->textures->floor_bot_closed)
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_closed);
	if (game->textures->floor_left_closed)
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_closed);
	if (game->textures->floor_right_closed)
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_closed);


	if (game->textures->wall_top_img)
		mlx_destroy_image(game->window->mlx, game->textures->wall_top_img);
	// if (game->textures->wall_bottom_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->wall_bottom_img);
	// if (game->textures->wall_left_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->wall_left_img);
	// if (game->textures->wall_right_img)
	// 	mlx_destroy_image(game->window->mlx, game->textures->wall_right_img);
	if (game->textures->exit_img)
		mlx_destroy_image(game->window->mlx, game->textures->exit_img);
	if (game->textures->player_img)
		mlx_destroy_image(game->window->mlx, game->player->player_texture);
}

void clean_exit(t_game *game)
{
	if (!game)
		exit(1);
	if (game->map)
		free_map(game->map);
	free_textures(game);
	if (game->player)
	{
		free(game->player);
	}
	
	if (game->camera)
	{
		free(game->camera);
	}
	if (game->window)
	{
		if (game->window->win)
			mlx_destroy_window(game->window->mlx, game->window->win);
		if (game->window->mlx)
		{
			mlx_destroy_display(game->window->mlx);
			free(game->window->mlx);
		}
		free(game->window);
	}

	
	free(game);
	exit(0);
}