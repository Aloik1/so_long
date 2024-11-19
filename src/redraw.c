/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:55:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 19:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	free_collectible_positions(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while(game->map->collectible->positions[i])
// 	{
// 		free(game->map->collectible->positions[i]);
// 		i++;
// 	}
// }

void	redraw_everything(t_game *game, t_textures *textures)
{
	if (!game || !game->window || !game->map || !game->player || !game->camera
		|| !game->movement) 
	{
		ft_printf("Error: Null pointer detected in redraw_everything\n");
		return;
	}

	if (!game->window->mlx || !game->window->win) 
	{
		ft_printf("Error: Invalid window or MLX instance\n");
		return;
	}
	if (!textures) 
	{
		ft_printf("Error: Textures pointer is NULL in redraw_everything\n");
		return;
	}
	//free_collectible_positions(game);
	ft_printf("Redrawing game state...\n");
	ft_printf("Floor texture: %p\n", textures->floor_img);
	ft_printf("Wall texture: %p\n", textures->wall_top_img);

	mlx_clear_window(game->window->mlx, game->window->win);
	ft_printf("Cleared window\n");
	ft_printf("Updating camera...\n");
	update_camera(game->camera, game->player, game->map);

	ft_printf("Drawing map...\n");
	game->player->player_texture = choose_player_texture(game);
	draw_map(game, game->window, game->camera, textures);

	ft_printf("Drawing player at position (%d, %d)...\n", game->player->pixel_x, game->player->pixel_y);
	draw_player(game, game->window, game->player, game->camera);
}

