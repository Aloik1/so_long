/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:37:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 19:37:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	texture_initialize(t_game *game, void *mlx)
{
	game->textures->floor_img = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_img)
	{
		ft_printf("Error: Could not load floor texture.\n");
		return (0);
	}
	game->textures->wall_top_img = mlx_xpm_file_to_image(mlx, "assets/textures/walls/forest_wall_main.xpm", &game->textures->wall_top_width, &game->textures->wall_top_height);
	if (!game->textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall top texture.\n");
		return (0);
	}
	game->textures->collectible_1_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &game->textures->collectible_1_width, &game->textures->collectible_1_height);
	if (!game->textures->collectible_1_img)
	{
		ft_printf("Error: Could not load collectible 1 texture.\n");
		return (0);
	}
	game->textures->exit_img = mlx_xpm_file_to_image(mlx, "assets/textures/exit/exit.xpm", &game->textures->exit_width, &game->textures->exit_height);
	if (!game->textures->exit_img)
	{
		ft_printf("Error: Could not load exit texture.\n");
		return (0);
	}
	game->player->player_texture = mlx_xpm_file_to_image(mlx, "assets/textures/character/character_basic.xpm", &game->player->width, &game->player->height);
	if (!game->player->player_texture)
	{
		ft_printf("Error: Could not load player texture.\n");
		return 0;
	}
	return (1);
}

