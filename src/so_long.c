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
	t_game		*game;


	game = (t_game *)malloc(sizeof(t_game));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->window = (t_window *)malloc(sizeof(t_window));
	if (!game->player || !game || !game->textures || !game->window)
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
	ft_printf("all checks done\n");

	// create the window
	if (!window_and_mlx(&game->window))
	{
		free(game);
		ft_printf("Couldn't load window\n");
		return (1);
	}
	ft_printf("Initialized window\n");
	// initialize the textures
	if (!texture_initialize(game, game->window->mlx))
	{
		ft_printf("couldn't load textures\n");
		free(game);
		return (1);
	}
	// Initialize the camera
	ft_printf("Initialized textures\n");
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		ft_printerror("Error: Could not allocate memory for camera\n");
		free(game);
		return (1);
	}
	// init the player
	if (!init_player(game))
	{
		free(game);
		return (1);
	}
	// initialize the camera
	camera_init(game->camera, game->player, game->map);
	
	// draw the map
	if (!draw_map(game, game->window, game->camera, game->textures))
	{
		free(game);
		return (1);
	}
	// draw the player
	if (!draw_player(game, game->window, game->player, game->camera))
	{
		free(game);
		return (1);
	}
	// check for key presses
	mlx_key_hook(game->window->win, movement, game);
	mlx_hook(game->window->win, 17, 0, clean_exit, game);
	
	// start the loop
	mlx_loop(game->window->mlx);
	// Free resources before exiting
	return (0);
}

