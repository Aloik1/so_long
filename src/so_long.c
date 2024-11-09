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
t_textures textures;

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
	if (!player || !game)
	{
		ft_printerror("Error: Could not allocate memory for player or game\n");
		return (1);
	}
	if (!basic_check(argc, argv))
	{
		free(player);
		return (1);
	}
	if (!read_map(argv[1], &map))
	{
		free(player);
		return (1);
	}
	if (map->rows == 0 || map->cols == 0 || map->collectibles == 0 
		|| map->exits == 0 || map->players == 0)
	{
		ft_printerror("Error: Invalid map\n");
		free_map(map);
		free(player);
		return (1);
	}
	if (!path_checks(map))
	{
		ft_printerror("Error: Invalid path, can't reach all collectibles or exit\n");
		free_map(map);
		free(player);
		return (1);
	}
	// create the window
	if (!window_and_mlx(&window))
	{
		free(player);
		return (1);
	}
	// Initialize the camera
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		ft_printerror("Error: Could not allocate memory for camera\n");
		free(player);
		return (1);
	}
	// init the player
	if (!init_player(map, window, player))
	{
		free(player);
		return (1);
	}
	ft_printf("Player initialized\n");
	// initialize the camera
	camera_init(game->camera, player, map);

	// draw the map
	ft_printf("Drawing the map...\n");
	if (!draw_map(map, window, game->camera)) // Pass the camera
	{
		free(player);
		return (1);
	}
	ft_printf("Map drawn.\n");
	// draw the player
	if (!draw_player(window, player, game->camera))
	{
		free(player);
		return (1);
	}
	ft_printf("Player drawn\n");
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

