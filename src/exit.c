/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:44:58 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/09 19:57:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_exit(t_map *map, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	textures->exit_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/exit/exit.xpm", &textures->exit_width, &textures->exit_height);
	if (!textures->exit_img)
	{
		ft_printf("Error: Could not load exit texture.\n");
		return ;
	}
	// map->exit = (t_exit_position *)malloc(sizeof(t_exit_position));
	if (!map->exit) {
		ft_printf("Error: Could not allocate memory for exit position.\n");
		return;
	}
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
				mlx_put_image_to_window(window->mlx, window->win, textures->exit_img, pixel_x, pixel_y);
				map->exit->x = j;
				map->exit->y = i;
				ft_printf("Exit position set to (%d, %d)\n", j, i);
			}
			j++;
		}
		i++;
	}
}

void	open_exit(t_map *map, t_player *player, t_game *game, t_textures *textures)
{
	ft_printf("Checking if exit is open...\n");
	ft_printf("Collectibles collected: %d\n", player->collectibles_collected);
	ft_printf("Collectibles left: %d\n", map->collectibles);
	if (map->collectibles == 0 && player->position.x == map->exit->x
		&& player->position.y == map->exit->y)
	{
		ft_printf("You win!\n");
		clean_exit(game, textures);
		exit(0);
	}
	if (player->collectibles_collected != map->collectibles)
	{
		ft_printf("Not enough collectibles to open the exit\n");
	}
	return ;
}