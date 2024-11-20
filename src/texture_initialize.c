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

int	init_textures(t_textures *textures)
{
	// textures = (t_textures *)malloc(sizeof(t_textures));
	// if (!textures)
	// 	return (0);
	ft_printf("initializing ints\n");
	textures->collectible_1_x = 0;
	textures->collectible_1_y = 0;
	textures->collectible_2_x = 0;
	textures->collectible_2_y = 0;
	textures->collectible_3_x = 0;
	textures->collectible_3_y = 0;
	textures->collectible_4_x = 0;
	textures->collectible_4_y = 0;
	textures->collectible_5_x = 0;
	textures->collectible_5_y = 0;
	textures->collectible_1_state = 1;
	textures->collectible_2_state = 1;
	textures->collectible_3_state = 1;
	textures->collectible_4_state = 1;
	textures->collectible_5_state = 1;
	return (1);
}

static int	even_more_floors(t_textures *textures, void *mlx)
{
	textures->floor_top_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_top_closed.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_bot_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_bot_closed.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_left_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_left_closed.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_right_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_closed.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	return (1);
}

static int	more_floors(t_textures *textures, void *mlx)
{
	textures->floor_top_right_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_top_right.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_top_left_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_top_left.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_bot_right_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_bot_right.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_bot_left_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_bot_left.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_all_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_all_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_all_open)
		return (0);
	textures->floor_top_bot = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_side_top_bot_walls.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_top_bot)
		return (0);
	if (!even_more_floors(textures, mlx))
		return (0);
	return (1);
}

static int	floor_textures(t_textures *textures, void *mlx)
{
	textures->floor_left_right = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_side_left_right_walls.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_left_right)
		return (0);
	textures->floor_top_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_top_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_top_open)
		return (0);
	textures->floor_bot_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_bot_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_bot_open)
		return (0);
	textures->floor_left_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_left_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_left_open)
		return (0);
	textures->floor_right_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	textures->floor_right_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_open.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_right_open)
		return (0);
	if (!more_floors(textures, mlx))
		return (0);
	return (1);
}

int	texture_initialize(t_game *game, void *mlx)
{
	if (!init_textures(game->textures))
		return (0);
	if (!floor_textures(game->textures, mlx))
		return (0);
	ft_printf("Floors textures are done\n");
	game->textures->wall_top_img = mlx_xpm_file_to_image(mlx, "assets/textures/walls/forest_wall_main.xpm", &game->textures->wall_top_width, &game->textures->wall_top_height);
	if (!game->textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall texture.\n");
		return (0);
	}
	ft_printf("Walls textures are done\n");
	if (!collectible_textures_initialize(game, mlx))
		return (0);
	ft_printf("Collectible position in texture initialize is: %d %d\n", game->textures->collectible_1_x, game->textures->collectible_1_y);
	ft_printf("Collectible textures are done\n");
	if (!exit_initialize(game, mlx))
		return (0);
	if (!player_texture_initialize(game, mlx))
		return (0);
	return (1);
}

