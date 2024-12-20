/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_frees.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 18:21:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	cilit_bang(t_game *game)
{
	if (game->window)
	{
		if (game->window->win)
		{
			mlx_destroy_window(game->window->mlx, game->window->win);
			game->window->win = NULL;
		}
		if (game->window->mlx)
		{
			mlx_destroy_display(game->window->mlx);
			free(game->window->mlx);
			game->window->mlx = NULL;
		}
		free(game->window);
		game->window = NULL;
	}
}

static void	free_collectible_and_aux(t_map *map, int i)
{
	if (map->map_aux)
	{
		while (i < map->rows)
		{
			free(map->map_aux[i]);
			i++;
		}
		free(map->map_aux);
	}
	i = 0;
	if (map->collectible)
	{
		while (map->collectible->positions[i])
		{
			if (map->collectible->positions[i] != NULL)
				free(map->collectible->positions[i]);
			i++;
		}
		free(map->collectible->positions);
		free(map->collectible);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_grid)
		{
			while (i < map->rows)
			{
				free(map->map_grid[i]);
				i++;
			}
			free(map->map_grid);
		}
		i = 0;
		free_collectible_and_aux(map, i);
		free(map);
	}
	return ;
}

t_player_position	return_null_player(void)
{
	t_player_position	player_position;

	player_position.x = -1;
	player_position.y = -1;
	return (player_position);
}

t_collectible_position	return_null_collectibles(
		t_collectible_position collectibles)
{
	int	i;

	i = 0;
	while (collectibles.positions[i])
	{
		free(collectibles.positions[i]);
		i++;
	}
	free(collectibles.positions);
	collectibles.positions = NULL;
	return (collectibles);
}
