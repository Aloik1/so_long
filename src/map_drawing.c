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

static void	draw_floor(t_game *game, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	ft_printf("Drawing floor with camera at (%d, %d)\n", camera->x, camera->y);
	if (!textures->floor_img || !textures)
	{
		ft_printf("Error: Could not load floor texture.\n");
		return ;
	}

	i = camera->y;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == '0' || game->map->map_grid[i][j] == 'P'
				|| game->map->map_grid[i][j] == 'E' || game->map->map_grid[i][j] == 'C')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
				ft_printf("floor_image: %p\n", textures->floor_img);
				mlx_put_image_to_window(window->mlx, window->win, textures->floor_img, pixel_x, pixel_y);
			}
			j++;
		}
		i++;
	}
}
static void	draw_wall(t_map *map, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	if (!textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall top texture.\n");
		return ;
	}

	ft_printf("Drawing wall with camera at (%d, %d)\n", camera->x, camera->y);

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
				mlx_put_image_to_window(window->mlx, window->win, textures->wall_top_img, pixel_x, pixel_y);
			}
			j++;
		}
		i++;
	}
}
static void	draw_collectibles(t_game *game, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	collectible_count;
	int	pixel_x;
	int	pixel_y;

	collectible_count = 0;
	i = 0;
	
	if (!textures->collectible_1_img /*|| !textures->collectible_2_img || !textures->collectible_3_img 
		|| !textures->collectible_4_img || !textures->collectible_5_img*/)
	{
		ft_printf("Error: Could not load collectible texture.\n");
		return ;
	}

	ft_printf("Drawing collectibles with camera at (%d, %d)\n", camera->x, camera->y);
	ft_printf("pointer to fill %p\n", game->map->collectible->positions[collectible_count]);
	// i = 0;
	// if (map->collectible->positions)
	// {
	// 	while (map->collectible->positions[i])
	// 	{
	// 		free(map->collectible->positions[i]);
	// 		i++;
	// 	}
	// 	free(map->collectible->positions);
	// }
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
	game->map->collectible->collectibles_visible = collectible_count;
	ft_printf("collectible count is: %d\n", collectible_count);
	// map->collectible->positions = (int **)malloc(sizeof(int *) * (collectible_count + 1));
	// if (!map->collectible->positions)
	// {
	// 	ft_printf("Error: Could not allocate memory for collectible positions.\n");
	// 	return ;
	// }
	i = camera->y;
	collectible_count = 0;
	while (i < camera->y + camera->height && i < game->map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == 'C')
			{
				pixel_x = (j - camera->x) * TILE_SIZE + 24;
				pixel_y = (i - camera->y) * TILE_SIZE + 24;
				mlx_put_image_to_window(window->mlx, window->win, textures->collectible_1_img, pixel_x, pixel_y);
				ft_printf("collectible count is: %d\n", collectible_count);
				ft_printf("pointer to fill %p\n", game->map->collectible->positions[collectible_count]);
				game->map->collectible->positions[collectible_count][0] = j;
				game->map->collectible->positions[collectible_count][1] = i;
				ft_printf("collectible position: %d, %d\n", game->map->collectible->positions[collectible_count][0], game->map->collectible->positions[collectible_count][1]);
				ft_printf("textures->collectible_1_img: %p\n", textures->collectible_1_img);
				collectible_count++;
			}
			j++;
		}
		i++;
	}
	//game->map->collectible->positions[collectible_count] = NULL;
	ft_printf("textures->collectible_1_img: %p\n", textures->collectible_1_img);
	ft_printf("collectible positions allocated\n");
}

int	draw_map(t_game *game, t_window *window, t_camera *camera, t_textures *textures)
{
	ft_printf("----------------Drawing floor...-----------------\n");
	draw_floor(game, window, textures, camera);
	ft_printf("Floor texture loaded: %p\n", textures->floor_img);
	ft_printf("----------------Drawing wall...-----------------\n");
	draw_wall(game->map, window, textures, camera);
	ft_printf("Wall texture loaded: %p\n", textures->wall_top_img);
	ft_printf("----------------Drawing collectibles...-----------------\n");
	draw_collectibles(game, window, textures, camera);
	ft_printf("Collectibles loaded\n");
	ft_printf("----------------Drawing exit...-----------------\n");
	draw_exit(game->map, window, textures, camera);
	ft_printf("Exit loaded\n");
	return (1);
}

