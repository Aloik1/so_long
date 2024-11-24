/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:54:00 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 13:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_floor(t_game *game, t_window *window, t_camera *camera)
{
	int		i;
	int		j;
	int		pixel_x;
	int		pixel_y;
	void	*texture_to_draw;

	texture_to_draw = NULL;
	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] != '1')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
				texture_to_draw = choose_floor(game, i, j);
				mlx_put_image_to_window(window->mlx, window->win,
					texture_to_draw, pixel_x, pixel_y);
			}
			j++;
		}
		i++;
	}
}

static void	draw_wall(t_map *map, t_window *window,
	t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	if (!textures->wall_top_img)
		return ;
	i = camera->y;
	while (i < camera->y + camera->height && i < map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < map->cols)
		{
			if (map->map_grid[i][j] == '1')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
				mlx_put_image_to_window(window->mlx, window->win,
					textures->wall_top_img, pixel_x, pixel_y);
			}
			j++;
		}
		i++;
	}
}

static int	count_collectibles(t_game *game, t_camera *camera)
{
	int	i;
	int	j;
	int	collectible_count;

	i = 0;
	collectible_count = 0;
	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	return (collectible_count);
}

static void	draw_collectibles(t_game *game, t_window *window, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;
	int	collectibles_visible;

	pixel_x = 0;
	pixel_y = 0;
	i = 0;
	collectibles_visible = count_collectibles(game, camera);
	game->map->collectible->collectibles_visible = collectibles_visible;
	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == 'C')
				draw_collectible(game, i, j, window);
			j++;
		}
		i++;
	}
}

int	draw_map(t_game *game, t_window *window,
	t_camera *camera, t_textures *textures)
{
	draw_floor(game, window, camera);
	draw_wall(game->map, window, textures, camera);
	draw_collectibles(game, window, camera);
	draw_exit(game, window, textures, camera);
	return (1);
}
