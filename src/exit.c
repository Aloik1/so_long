/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:44:58 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 16:59:29 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	closed_or_open(t_game *game, t_window *window, t_textures *textures, int i, int j)
{
	int	pixel_x;
	int	pixel_y;
	
	pixel_x = (j - game->camera->x) * TILE_SIZE;
	pixel_y = (i - game->camera->y) * TILE_SIZE;
	if (game->map->collectibles == 0)
		mlx_put_image_to_window(window->mlx, window->win, 
			textures->exit_open, pixel_x, pixel_y);
	else
		mlx_put_image_to_window(window->mlx, window->win, 
			textures->exit_closed, pixel_x, pixel_y);
	game->map->exit_x = j;
	game->map->exit_y = i;
}

void	draw_exit(t_game *game, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;

	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == 'E')
				closed_or_open(game, window, textures, i, j);
			j++;
		}
		i++;
	}
}

int	open_exit(t_map *map, t_player *player, t_game *game)
{
	if (map->collectibles == 0 && player->position.x == map->exit_x
		&& player->position.y == map->exit_y)
	{
		ft_printf("You win!\n");
		clean_exit(game);
		return (1);
	}
	return (0);
}