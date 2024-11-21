/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:50:02 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 02:12:12 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_more_ints(t_textures *textures)
{
	textures->enemy_right_1_height = 0;
	textures->enemy_right_1_width = 0;
	textures->enemy_right_2_height = 0;
	textures->enemy_right_2_width = 0;
	textures->enemy_right_3_height = 0;
	textures->enemy_right_3_width = 0;
}

static void	init_textures_int(t_textures *textures)
{
	textures->enemy_base_height = 0;
	textures->enemy_base_width = 0;
	textures->enemy_up_1_height = 0;
	textures->enemy_up_1_width = 0;
	textures->enemy_up_2_height = 0;
	textures->enemy_up_2_width = 0;
	textures->enemy_up_3_height = 0;
	textures->enemy_up_3_width = 0;
	textures->enemy_down_1_height = 0;
	textures->enemy_down_1_width = 0;
	textures->enemy_down_2_height = 0;
	textures->enemy_down_2_width = 0;
	textures->enemy_down_3_height = 0;
	textures->enemy_down_3_width = 0;
	textures->enemy_left_1_height = 0;
	textures->enemy_left_1_width = 0;
	textures->enemy_left_2_height = 0;
	textures->enemy_left_2_width = 0;
	textures->enemy_left_3_height = 0;
	textures->enemy_left_3_width = 0;
	init_more_ints(textures);
}

static void	*enemy_texture_chooser(t_game *game, int i, int j)
{
	if (game->enemies->enemy_1_y == i && game->enemies->enemy_1_x == j)
		return (game->textures->enemy_base);
	if (game->enemies->enemy_2_y == i && game->enemies->enemy_2_x == j)
		return (game->textures->enemy_base);
	if (game->enemies->enemy_3_y == i && game->enemies->enemy_3_x == j)
		return (game->textures->enemy_base);
	if (game->enemies->enemy_4_y == i && game->enemies->enemy_4_x == j)
		return (game->textures->enemy_base);
	if (game->enemies->enemy_5_y == i && game->enemies->enemy_5_x == j)
		return (game->textures->enemy_base);
	return (NULL);
}

int	draw_enemies(t_game *game, t_camera *camera, t_window *window)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;
	
	init_textures_int(game->textures);
	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == 'X')
			{
				pixel_x = (j - game->camera->x) * TILE_SIZE + 24;
				pixel_y = (i - game->camera->y) * TILE_SIZE + 24;
				mlx_put_image_to_window(window->mlx, window->win, enemy_texture_chooser(game, i, j), pixel_x, pixel_y);
			}
			j++;
		}
		i++;
	}
	return (1);
	
}