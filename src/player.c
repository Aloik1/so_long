/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:28:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 14:28:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_position(t_player *player, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map_grid[i][j] == 'P')
			{

				player->position.x = j;
				player->position.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_player(t_game *game)
{

	game->player->speed = 1;
	game->player->direction = 0;
	game->player->collectibles_collected = 0;
	player_position(game->player, game->map);
	game->textures->player_width = game->player->width;
	game->textures->player_height = game->player->height;
	return (1);
}

int	draw_player(t_game *game, t_window *window, t_player *player, t_camera *camera)
{
	if (!player->player_texture)
		return 0;
	player->pixel_x = (player->position.x - camera->x) * TILE_SIZE + 48 - (player->width) / 2;
	player->pixel_y = (player->position.y - camera->y) * TILE_SIZE + 48 - (player->height) / 2;
	mlx_put_image_to_window(window->mlx, window->win, choose_player_texture(game), player->pixel_x, player->pixel_y);
	return 1;
}
