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


static int	even_more_floors(t_game *game, void *mlx)
{
	game->textures->floor_top_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_top_closed.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_bot_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_bot_closed.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_left_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_left_closed.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_right_closed = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_closed.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	return (1);
}

static int	more_floors(t_game *game, void *mlx)
{
	game->textures->floor_top_right_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_top_right.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_top_left_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_top_left.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_bot_right_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_bot_right.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_bot_left_corner = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_corner_bot_left.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_all_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_all_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_all_open)
		return (0);
	game->textures->floor_top_bot = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_side_top_bot_walls.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_top_bot)
		return (0);
	if (!even_more_floors(game, mlx))
		return (0);
	return (1);
}

static int	floor_textures(t_game *game, void *mlx)
{
	game->textures->floor_left_right = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_side_left_right_walls.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_left_right)
		return (0);
	game->textures->floor_top_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_top_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_top_open)
		return (0);
	game->textures->floor_bot_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_bot_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_bot_open)
		return (0);
	game->textures->floor_left_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_left_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_left_open)
		return (0);
	game->textures->floor_right_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	game->textures->floor_right_open = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor_right_open.xpm", &game->textures->floor_width, &game->textures->floor_height);
	if (!game->textures->floor_right_open)
		return (0);
	if (!more_floors(game, mlx))
		return (0);
	return (1);
}

int	texture_initialize(t_game *game, void *mlx)
{
	if (!floor_textures(game, mlx))
		return (0);
	ft_printf("Floors textures are done\n");
	game->textures->wall_top_img = mlx_xpm_file_to_image(mlx, "assets/textures/walls/forest_wall_main.xpm", &game->textures->wall_top_width, &game->textures->wall_top_height);
	if (!game->textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall top texture.\n");
		return (0);
	}
	ft_printf("Walls textures are done\n");
	if (!collectible_textures_initialize(game, mlx))
		return (0);
	ft_printf("Collectible textures are done\n");
	if (!exit_initialize(game, mlx))
		return (0);
	if (!player_texture_initialize(game, mlx))
		return (0);
	return (1);
}

