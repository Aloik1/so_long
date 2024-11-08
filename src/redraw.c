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

// void	redraw_player(t_game *game)
// {
// 	mlx_clear_window(game->window->mlx, game->window->win);
// 	draw_player(game->window, game->player);
// }

void	redraw_everything(t_game *game)
{
	if (!game || !game->window || !game->map || !game->player || !game->camera) {
		ft_printf("Error: Null pointer detected in redraw_everything\n");
		return;
	}

	if (!game->window->mlx || !game->window->win) {
		ft_printf("Error: Invalid window or MLX instance\n");
		return;
	}

	ft_printf("Redrawing game state...\n");

	mlx_clear_window(game->window->mlx, game->window->win);
	ft_printf("Cleared window\n");
	ft_printf("Updating camera...\n");
	update_camera(game->camera, game->player, game->map);

	ft_printf("Drawing map...\n");
	draw_map(game->map, game->window, game->camera);

	ft_printf("Drawing player at position (%d, %d)...\n", game->player->pixel_x, game->player->pixel_y);
	draw_player(game->window, game->player, game->camera);
}

