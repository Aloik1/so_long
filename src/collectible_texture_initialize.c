/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_texture_initialize.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:02:40 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/18 23:26:45 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	five_collectibles(t_game *game, void *mlx)
{
	if (!initialize_5_collectibles(game))
		return (0);
	ft_printf("Collectibles initialized successfully\n");
	game->textures->collectible_1->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1->collectible_img)
		return (0);
	ft_printf("Collectible_1 loaded\n");
	game->textures->collectible_2->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_2->collectible_img)
		return (0);
	ft_printf("Collectible_2 loaded\n");
	game->textures->collectible_3->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_3->collectible_img)
		return (0);
	ft_printf("Collectible_3 loaded\n");
	game->textures->collectible_4->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_4->collectible_img)
		return (0);
	ft_printf("Collectible_4 loaded\n");
	game->textures->collectible_5->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_5->collectible_img)
		return (0);
	ft_printf("Collectible_5 loaded\n");
	return (1);
}

static int	four_collectibles(t_game *game, void *mlx)
{
	if (!initialize_4_collectibles(game))
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
	game->textures->collectible_4->collectible_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_4->collectible_img)
		return (0);
	return (1);
}

int	collectible_textures_initialize(t_game *game, void *mlx)
{
	ft_printf("Number of collectibles is: %d\n", game->map->collectibles);
	game->textures->collectible_animation_1 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_animation_2 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_2.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_animation_3 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_3.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_animation_4 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_4.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_animation_5 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_5.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_animation_5 = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_5.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	game->textures->collectible_destroyed = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_destroyed.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (game->map->collectibles == 5)
	{
		if (!five_collectibles(game, mlx))
			return (0);
	}
	if (game->map->collectibles == 4)
	{
		if (!four_collectibles(game, mlx))
			return (0);
	}
	else
		if (!more_collectible_textures(game, mlx))
			return (0);
	collectible_position_adder(game);
	return (1);	
}
