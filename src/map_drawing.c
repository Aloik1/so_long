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

static void	draw_floor(t_map *map, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	textures->floor_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/floors/floor.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_img)
	{
		ft_printf("Error: Could not load floor texture.\n");
		free(textures);
		return ;
	}

	ft_printf("Drawing floor with camera at (%d, %d)\n", camera->x, camera->y);

	i = camera->y;
	while (i < camera->y + camera->height && i < map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < map->cols)
		{
			if (map->map_grid[i][j] == '0' || map->map_grid[i][j] == 'P'
				|| map->map_grid[i][j] == 'E' || map->map_grid[i][j] == 'C')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
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

	textures->wall_top_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/walls/wall_general.xpm", &textures->wall_top_width, &textures->wall_top_height);
	if (!textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall top texture.\n");
		free(textures);
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
static void	draw_collectibles(t_map *map, t_window *window, t_textures *textures, t_camera *camera)
{
	int	i;
	int	j;
	int	collectible_count;
	int	pixel_x;
	int	pixel_y;

	collectible_count = 0;
	i = 0;
	textures->collectible_1_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_1_width, &textures->collectible_1_height);
	textures->collectible_2_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_2_width, &textures->collectible_2_height);
	textures->collectible_3_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_3_width, &textures->collectible_3_height);
	textures->collectible_4_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_4_width, &textures->collectible_4_height);
	textures->collectible_5_img = mlx_xpm_file_to_image(window->mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_5_width, &textures->collectible_5_height);
	if (!textures->collectible_1_img || !textures->collectible_2_img || !textures->collectible_3_img 
		|| !textures->collectible_4_img || !textures->collectible_5_img)
	{
		ft_printf("Error: Could not load collectible texture.\n");
		free(textures);
		return ;
	}

	ft_printf("Drawing collectibles with camera at (%d, %d)\n", camera->x, camera->y);

	i = camera->y;
	while (i < camera->y + camera->height && i < map->rows)
	{
		j = camera->x;
		while (j < camera->x + camera->width && j < map->cols)
		{
			if (map->map_grid[i][j] == 'C')
			{
				pixel_x = (j - camera->x) * TILE_SIZE;
				pixel_y = (i - camera->y) * TILE_SIZE;
				mlx_put_image_to_window(window->mlx, window->win, textures->collectible_1_img, pixel_x, pixel_y);
				collectible_count++;
			}
			j++;
		}
		i++;
	}
}

int	draw_map(t_map *map, t_window *window, t_camera *camera)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
	{
		ft_printf("Error: Could not allocate memory for textures.\n");
		return (0);
	}
	draw_floor(map, window, textures, camera);
	ft_printf("Floor texture loaded: %p\n", textures->floor_img);
	draw_wall(map, window, textures, camera);
	ft_printf("Wall texture loaded: %p\n", textures->wall_top_img);
	draw_collectibles(map, window, textures, camera);
	ft_printf("Collectibles loaded\n");
	free(textures);
	return (1);
}

