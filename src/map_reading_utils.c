/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:45:28 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 17:02:03 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible_line(t_map *map, char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'C')
			map->collectibles++;
		j++;
	}
}

void	draw_collectible(t_game *game, int i, int j,
	t_window *window)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = (j - game->camera->x) * TILE_SIZE + 24;
	pixel_y = (i - game->camera->y) * TILE_SIZE;
	mlx_put_image_to_window(window->mlx, window->win,
		texture_chooser(game, i, j), pixel_x, pixel_y);
}

int	memory_check_grid(t_map *map)
{
	if (!map->map_grid)
	{
		ft_printerror("Failed to allocate memory\n");
		return (0);
	}
	return (1);
}

int	memory_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printerror("Failed to open map file\n");
		return (0);
	}
	return (1);
}

int	memory_check_map(t_map *map)
{
	if (!map)
	{
		ft_printerror("Failed to allocate memory\n");
		return (0);
	}
	return (1);
}
