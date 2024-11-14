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
	t_game		*game;

	window = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->player || !game || !game->textures)
	{
		ft_printerror("Error: Could not allocate memory for player, game or textures\n");
		return (1);
	}
	if (!basic_check(argc, argv))
	{
		free(game);
		return (1);
	}
	if (!read_map(argv[1], game))
	{
		free(game);
		return (1);
	}
	if (!path_checks(game))
	{
		ft_printerror("Error: Invalid path, can't reach all collectibles or exit\n");
		free(game);
		return (1);
	}
	// create the window
	if (!window_and_mlx(&window))
	{
		free(game);
		return (1);
	}
	// initialize the textures
	if (!texture_initialize(game, window->mlx))
	{
		free(game);
		return (1);
	}
	// Initialize the camera
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		ft_printerror("Error: Could not allocate memory for camera\n");
		free(game);
		return (1);
	}

	// init the player
	if (!init_player(game->map, game->player, game->textures))
	{
		free(game);
		return (1);
	}
	// initialize the camera
	camera_init(game->camera, game->player, game->map);
	
	// draw the map
	if (!draw_map(game, window, game->camera, game->textures))
	{
		free(game);
		return (1);
	}
	// draw the player
	if (!draw_player(window, game->player, game->camera))
	{
		free(game);
		return (1);
	}
	game->window = window;
	// check for key presses
	mlx_key_hook(window->win, movement, game);
	
	// start the loop
	mlx_loop(window->mlx);
	// Free resources before exiting
	return (0);
}

