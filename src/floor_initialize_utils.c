/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_initialize_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 13:47:58 by ikondrat          #+#    #+#             */
/*   Updated: 2024-11-24 13:47:58 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	initial_player_textures(t_game *game, void *mlx)
{
	game->textures->player_up_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_up_1.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_up_1)
		exit(0);
	game->textures->player_up_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_up_2.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_up_2)
		exit(0);
	game->textures->player_up_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/character/run_up_3.xpm",
			&game->player->width, &game->player->height);
	if (!game->textures->player_up_3)
		exit(0);
	return (1);
}

static int	final_floors(t_textures *textures, void *mlx)
{
	textures->floor_bot_closed = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_bot_closed.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		exit(0);
	textures->floor_left_closed = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_left_closed.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		exit(0);
	textures->floor_right_closed = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_right_closed.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		exit(0);
	return (1);
}

int	even_even_more_floors(t_textures *textures, void *mlx)
{
	textures->floor_all_open = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_all_open.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_all_open)
		exit(0);
	textures->floor_top_bot = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_side_top_bot_walls.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_top_bot)
		exit(0);
	textures->floor_top_closed = mlx_xpm_file_to_image(mlx,
			"assets/textures/floors/floor_top_closed.xpm",
			&textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		exit(0);
	if (!final_floors(textures, mlx))
		return (0);
	return (1);
}
