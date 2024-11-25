/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_texture_initialize.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:02:40 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/25 02:42:07 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	five_collectibles(t_textures *textures, t_map *map)
{
	textures->collectible_1_x = map->collectible->positions[0][0];
	textures->collectible_1_y = map->collectible->positions[0][1];
	textures->collectible_2_x = map->collectible->positions[1][0];
	textures->collectible_2_y = map->collectible->positions[1][1];
	textures->collectible_3_x = map->collectible->positions[2][0];
	textures->collectible_3_y = map->collectible->positions[2][1];
	textures->collectible_4_x = map->collectible->positions[3][0];
	textures->collectible_4_y = map->collectible->positions[3][1];
	textures->collectible_5_x = map->collectible->positions[4][0];
	textures->collectible_5_y = map->collectible->positions[4][1];
	textures->collectible_1_state = 1;
	textures->collectible_2_state = 1;
	textures->collectible_3_state = 1;
	textures->collectible_4_state = 1;
	textures->collectible_5_state = 1;
	return ;
}

static void	four_collectibles(t_textures *textures, t_map *map)
{
	textures->collectible_1_x = map->collectible->positions[0][0];
	textures->collectible_1_y = map->collectible->positions[0][1];
	textures->collectible_2_x = map->collectible->positions[1][0];
	textures->collectible_2_y = map->collectible->positions[1][1];
	textures->collectible_3_x = map->collectible->positions[2][0];
	textures->collectible_3_y = map->collectible->positions[2][1];
	textures->collectible_4_x = map->collectible->positions[3][0];
	textures->collectible_4_y = map->collectible->positions[3][1];
	textures->collectible_1_state = 1;
	textures->collectible_2_state = 1;
	textures->collectible_3_state = 1;
	textures->collectible_4_state = 1;
	return ;
}

static int	initialize_more_images(t_game *game, void *mlx)
{
	game->textures->collectible_animation_3 = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_3.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_animation_3)
		return (0);
	game->textures->collectible_animation_4 = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_4.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_animation_4)
		return (0);
	game->textures->collectible_animation_5 = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_5.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_animation_5)
		return (0);
	game->textures->collectible_destroyed = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_destroyed.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_destroyed)
		return (0);
	return (1);
}

static int	initialize_images(t_game *game, void *mlx)
{
	game->textures->collectible_image = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_1.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_image)
		return (0);
	game->textures->collectible_animation_1 = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_1.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_animation_1)
		return (0);
	game->textures->collectible_animation_2 = mlx_xpm_file_to_image(mlx,
			"assets/textures/collectibles/collectible_2.xpm",
			&game->textures->collectible_1_width,
			&game->textures->collectible_1_height);
	if (!game->textures->collectible_animation_2)
		return (0);
	if (!initialize_more_images(game, mlx))
		return (0);
	return (1);
}

int	collectible_textures_initialize(t_game *game, void *mlx)
{
	game->textures->collectible_count = 0;
	if (!initialize_images(game, mlx))
		return (0);
	if (game->map->collectibles == 5)
		five_collectibles(game->textures, game->map);
	if (game->map->collectibles == 4)
		four_collectibles(game->textures, game->map);
	else
		more_collectible_textures(game->textures, game->map);
	return (1);
}
