/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_collectible_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:32:42 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 22:00:10 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	three_collectibles(t_game *game, void *mlx)
{
	if (!initialize_3_collectibles(game))
		return (0);
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1->collectible_img)
		return (0);
	game->textures->collectible_2->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_2->collectible_img)
		return (0);
	game->textures->collectible_3->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_3->collectible_img)
		return (0);
	return (1);
}

static int	two_collectibles(t_game *game, void *mlx)
{
	if (!initialize_2_collectibles(game))
		return (0);
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1->collectible_img)
		return (0);
	game->textures->collectible_2->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_2->collectible_img)
		return (0);
	return (1);
}

static int	one_collectible(t_game *game, void *mlx)
{
	game->textures->collectible_1 = (t_collectible_1 *)malloc(sizeof(t_collectible_1));
	if(!game->textures->collectible_1)
		return (0);
	// game->textures->collectible_1->position = (int *)malloc(sizeof(int) * 2);
	// ft_printf("collectible 1 position pointer is: %p\n", game->textures->collectible_1->position);
	// if(!game->textures->collectible_1->position)
	// 	return (0);
	game->textures->collectible_1->count = 0;
	game->textures->collectible_1->number = 1;
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1->collectible_img)
		return (0);
	return (1);
}

int	more_collectible_textures(t_game *game, void *mlx)
{
	if (game->map->collectibles == 3)
	{
		if (!three_collectibles(game, mlx))
			return (0);
		return (1);
	}
	if (game->map->collectibles == 2)
	{
		if (!two_collectibles(game, mlx))
			return (0);
		return (1);
	}
	if (game->map->collectibles == 1)
	{
		if (!one_collectible(game, mlx))
			return (0);
		return (1);
	}
	return (1);
}