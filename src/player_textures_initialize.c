/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_textures_initialize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:39:39 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 17:03:25 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	player_textures_right(t_game *game, void *mlx)
{
	game->textures->player_right_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_right_1.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_right_1)
		exit(0);
	game->textures->player_right_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_right_2.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_right_2)
		exit(0);
	game->textures->player_right_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_right_3.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_right_3)
		exit(0);
	return (1);
}

static int	player_textures_left(t_game *game, void *mlx)
{
	game->textures->player_left_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_left_1.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_left_1)
		exit(0);
	game->textures->player_left_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_left_2.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_left_2)
		exit(0);
	game->textures->player_left_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_left_3.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_left_3)
		exit(0);
	return (1);
}

static int	player_textures_down(t_game *game, void *mlx)
{
	game->textures->player_down_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_down_1.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_down_1)
		exit(0);
	game->textures->player_down_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_down_2.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_down_2)
		exit(0);
	game->textures->player_down_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_down_3.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_down_3)
		exit(0);
	return (1);
}

int	player_texture_initialize(t_game *game, void *mlx)
{
	game->player->player_texture = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_up_0.xpm",
			&game->player->width, &game->player->height);
	if (!game->player->player_texture)
		exit(0);
	if (!initial_player_textures(game, mlx))
		return (0);
	if (!player_textures_down(game, mlx))
		return (0);
	if (!player_textures_left(game, mlx))
		return (0);
	if (!player_textures_right(game, mlx))
		return (0);
	return (1);
}
