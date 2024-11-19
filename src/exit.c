/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:44:58 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 21:44:02 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_exit(t_map *map, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	i = camera->y;
	while (i < camera->y + camera->height && i < map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < map->cols)
		{
			if (map->map_grid[i][j] == 'E')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
				if (map->collectibles == 0)
					mlx_put_image_to_window(window->mlx, window->win, textures->exit_open, pixel_x, pixel_y);
				else
					mlx_put_image_to_window(window->mlx, window->win, textures->exit_closed, pixel_x, pixel_y);
				map->exit->x = j;
				map->exit->y = i;
				ft_printf("Exit position set to (%d, %d)\n", j, i);
			}
			j++;
		}
		i++;
	}
}

int	open_exit(t_map *map, t_player *player, t_game *game)
{
	ft_printf("Checking if exit is open...\n");
	ft_printf("Collectibles collected: %d\n", player->collectibles_collected);
	ft_printf("Collectibles left: %d\n", map->collectibles);
	if (map->collectibles == 0 && player->position.x == map->exit->x
		&& player->position.y == map->exit->y)
	{
		ft_printf("You win!\n");
		clean_exit(game);
		return (1);
	}
	return (0);
}