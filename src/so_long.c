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

static int	initial_checks(int argc, char **argv, t_game *game)
{
	if (!game->player || !game || !game->window)
	{
		ft_printerror("Error: Could not allocate memory for player, game or textures\n");
		return (0);
	}
	if (!basic_check(argc, argv))
	{
		free(game);
		return (0);
	}
	if (!read_map(argv[1], game))
	{
		free(game);
		return (0);
	}
	if (!path_checks(game))
	{
		ft_printerror("Error: Invalid path, can't reach all collectibles or exit\n");
		free(game);
		return (0);
	}
	return (1);
}

static int	initialize_everything(t_game *game)
{
	if (!window_and_mlx(&game->window))
	{
		free(game);
		return (0);
	}
	ft_printf("Initialized window\n");
	if (!texture_initialize(game, game->window->mlx))
	{
		free(game);
		return (0);
	}
	game->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!game->camera)
	{
		free(game);
		return (0);
	}
	if (!init_player(game))
	{
		free(game);
		return (0);
	}
	camera_init(game->camera, game->player, game->map);
	return (1);
}

static int	draw_everything(t_game *game)
{
	if (!draw_map(game, game->window, game->camera, game->textures))
	{
		free(game);
		return (0);
	}
	if (!draw_player(game, game->window, game->player, game->camera))
	{
		free(game);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		*game;


	game = (t_game *)malloc(sizeof(t_game));
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	init_textures(game->textures);
	game->player = (t_player *)malloc(sizeof(t_player));
	game->window = (t_window *)malloc(sizeof(t_window));

	if (!initial_checks(argc, argv, game))
		return (0);
	if (!initialize_everything(game))
		return (0);
	if (!draw_everything(game))
		return (0);
	mlx_key_hook(game->window->win, movement, game);
	mlx_hook(game->window->win, 17, 0, clean_exit, game);
	// start the loop
	mlx_loop(game->window->mlx);
	// Free resources before exiting
	return (0);
}
