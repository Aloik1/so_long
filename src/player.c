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
				ft_printf("x and y are: %d, %d\n", player->position.x, player->position.y);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_player(t_map *map, t_player *player, t_textures *textures)
{
	
	player->speed = 1;
	player->direction = 0;
	player->collectibles_collected = 0;

	// Load player texture
	player_position(player, map);
	ft_printf("Player position: %d, %d\n", player->position.x, player->position.y);
	// Set player dimensions
	textures->player_width = player->width;
	textures->player_height = player->height;
	return 1;
}

int	draw_player(t_window *window, t_player *player, t_camera *camera)
{
	if (!player->player_texture)
	{
		ft_printf("Error: Player texture is NULL.\n");
		return 0;
	} 
	else 
	{
		ft_printf("Player texture loaded: %p\n", player->player_texture);
		ft_printf("Player dimensions: %d x %d\n", player->width, player->height);
	}
	ft_printf("Player position: %d, %d\n", player->position.x, player->position.y);
	player->pixel_x = (player->position.x - camera->x) * TILE_SIZE + 48 - (player->width) / 2;
	player->pixel_y = (player->position.y - camera->y) * TILE_SIZE + 48 - (player->height) / 2;
	mlx_put_image_to_window(window->mlx, window->win, player->player_texture, player->pixel_x, player->pixel_y);
	return 1;
}
