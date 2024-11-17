/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_texture_initialize.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:02:40 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/17 20:42:04 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	five_collectibles(t_game *game, void *mlx)
{
	game->textures->collectible_1 = (t_collectible_1 *)malloc(sizeof(t_collectible_1));
	game->textures->collectible_2 = (t_collectible_2 *)malloc(sizeof(t_collectible_2));
	game->textures->collectible_3 = (t_collectible_3 *)malloc(sizeof(t_collectible_3));
	game->textures->collectible_4 = (t_collectible_4 *)malloc(sizeof(t_collectible_4));
	game->textures->collectible_5 = (t_collectible_5 *)malloc(sizeof(t_collectible_5));
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_2->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_3->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_4->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_5->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	return (1);
}

static int	four_collectibles(t_game *game, void *mlx)
{
	game->textures->collectible_1 = (t_collectible_1 *)malloc(sizeof(t_collectible_1));
	game->textures->collectible_2 = (t_collectible_2 *)malloc(sizeof(t_collectible_2));
	game->textures->collectible_3 = (t_collectible_3 *)malloc(sizeof(t_collectible_3));
	game->textures->collectible_4 = (t_collectible_4 *)malloc(sizeof(t_collectible_4));
	game->textures->collectible_1->count = 0;
	game->textures->collectible_2->count = 0;
	game->textures->collectible_3->count = 0;
	game->textures->collectible_4->count = 0;
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_2->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_3->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	game->textures->collectible_4->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
		return (0);
	return (1);
}

int	collectible_textures_initialize(t_game *game, void *mlx)
{
	
	if (game->map->collectibles == 5)
	{
		if (!five_collectibles(game, mlx))
			return (0);
		game->textures->collectible_1->count = 0;
		game->textures->collectible_2->count = 0;
		game->textures->collectible_3->count = 0;
		game->textures->collectible_4->count = 0;
		game->textures->collectible_5->count = 0;
		return (1);
	}
	if (game->map->collectibles == 4)
	{
		if (!four_collectibles(game, mlx))
			return (0);
		return (1);
	}
	else
		if (!more_collectible_textures(game, mlx))
			return (0);
	return (1);	
}
