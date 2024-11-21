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

void	redraw_everything(t_game *game, t_textures *textures, int moves)
{
	if (!game || !game->window || !game->map || !game->player || !game->camera
		|| !game->movement) 
		return ;
	if (!game->window->mlx || !game->window->win) 
		return ;
	if (!textures)
		return ;
	mlx_clear_window(game->window->mlx, game->window->win);
	update_camera(game->camera, game->player, game->map);
	draw_map(game, game->window, game->camera, textures);
	draw_player(game, game->window, game->player, game->camera);
	enemies_movement(game, game->enemies);
	draw_info(game, moves);
	check_collision(game, moves);
	
}

