/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:25:22 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 19:25:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Define the global textures variable


int	main(int argc, char **argv)
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_game		*game;

	map = NULL;
	window = NULL;
	player = (t_player *)malloc(sizeof(t_player));
	game = (t_game *)malloc(sizeof(t_game));
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!player || !game || !game->textures)
	{
		ft_printerror("Error: Could not allocate memory for player, game or textures\n");
		return (1);
	}
	if (!basic_check(argc, argv))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	if (!read_map(argv[1], &map))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	if (map->rows == 0 || map->cols == 0 || map->collectibles == 0 
		|| map->exits == 0 || map->players == 0)
	{
		ft_printerror("Error: Invalid map\n");
		free_map(map);
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	if (!path_checks(map))
	{
		ft_printerror("Error: Invalid path, can't reach all collectibles or exit\n");
		free_map(map);
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	// create the window
	if (!window_and_mlx(&window))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	
	// Initialize the camera
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		ft_printerror("Error: Could not allocate memory for camera\n");
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	// init the player
	if (!init_player(map, window, player, game->textures))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	ft_printf("Player initialized\n");
	// initialize the camera
	camera_init(game->camera, player, map);
	// initialize the textures
	if (!texture_initialize(game->textures, window->mlx))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	ft_printf("------------Textures initialized-------------\n");
	ft_printf("Wall texture: %p\n", game->textures->wall_top_img);
	ft_printf("Floor texture: %p\n", game->textures->floor_img);
	ft_printf("Collectible texture: %p\n", game->textures->collectible_1_img);
	// draw the map
	ft_printf("Drawing the map...\n");
	if (!draw_map(map, window, game->camera, game->textures)) // Pass the camera
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	ft_printf("-----------Map drawn.-------------\n");
	// draw the player
	if (!draw_player(window, player, game->camera))
	{
		free(player);
		free(game);
		// free(textures);
		return (1);
	}
	ft_printf("-----------Player drawn-------------\n");
	ft_printf("Player position: (%d, %d)\n", player->position.x, player->position.y);
	game->player = player;
	game->map = map;
	game->window = window;
	// check for key presses
	mlx_key_hook(window->win, movement, game);
	
	// start the loop
	mlx_loop(window->mlx);
	// Free resources before exiting
	return (0);
}

