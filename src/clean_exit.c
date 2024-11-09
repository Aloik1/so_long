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


void	free_textures(t_textures *textures, void *mlx)
{
	if (textures->collectible_1_img)
		mlx_destroy_image(mlx, textures->collectible_1_img);
	if (textures->collectible_2_img)
		mlx_destroy_image(mlx, textures->collectible_2_img);
	if (textures->collectible_3_img)
		mlx_destroy_image(mlx, textures->collectible_3_img);
	if (textures->collectible_4_img)
		mlx_destroy_image(mlx, textures->collectible_4_img);
	if (textures->collectible_5_img)
		mlx_destroy_image(mlx, textures->collectible_5_img);
	if (textures->floor_img)
		mlx_destroy_image(mlx, textures->floor_img);
	if (textures->wall_top_img)
		mlx_destroy_image(mlx, textures->wall_top_img);
	if (textures->wall_bottom_img)
		mlx_destroy_image(mlx, textures->wall_bottom_img);
	if (textures->wall_left_img)
		mlx_destroy_image(mlx, textures->wall_left_img);
	if (textures->wall_right_img)
		mlx_destroy_image(mlx, textures->wall_right_img);
	if (textures->exit_img)
		mlx_destroy_image(mlx, textures->exit_img);
	if (textures->player_img)
		mlx_destroy_image(mlx, textures->player_img);
}

void clean_exit(t_game *game, t_textures *textures)
{
	if (!game)
		exit(1);
	if (game->map)
		free_map(game->map);
	if (game->player)
	{
		if (game->player->player_texture)
			mlx_destroy_image(game->window->mlx, game->player->player_texture);
		free(game->player);
	}
	free_textures(textures, game->window->mlx);
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