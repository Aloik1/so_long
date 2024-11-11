/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:20:51 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 16:20:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_exit_position	get_exit_position(t_map *map)
{
	t_exit_position	exit_position;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map->map_grid[i][j])
	{
		if (map->map_grid[i][j] == 'E')
		{
			exit_position.x = j;
			exit_position.y = i;
			return (exit_position);
		}
		j++;
		if (map->map_grid[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (return_null_exit());
}

static t_player_position	get_player_position(t_map *map)
{
	t_player_position	player_position;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map->map_grid[i][j])
	{
		if (map->map_grid[i][j] == 'P')
		{
			player_position.x = j;
			player_position.y = i;
			return (player_position);
		}
		j++;
		if (map->map_grid[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (return_null_player());
}

static int	count_collectibles(t_map *map, int pos_count, int i, int j)
{
	if (map->map_grid[i][j] == 'C')
	{
		pos_count++;
	}
	return (pos_count);
}

static t_collectible_position	get_collectibles_position(t_map *map)
{
	t_collectible_position	collectibles;
	int			i;
	int			j;
	int			pos_count;

	i = 0;
	j = 0;
	pos_count = 0;
	collectibles.positions = NULL;
	collectibles.positions = malloc(sizeof(int *) * map->collectibles);
	if (!collectibles.positions)
	{
		return_null_and_free_collectibles(collectibles);
		return (collectibles);
	}
	while (i < map->rows)
	{
		while (j < map->cols)
		{
			pos_count = count_collectibles(map, pos_count, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (collectibles);
}

int	path_checks(t_map *map)
{
	t_player_position	player_position;
	t_collectible_position	collectibles;
	t_exit_position		exit_position;

	player_position = get_player_position(map);
	collectibles = get_collectibles_position(map);
	exit_position = get_exit_position(map);
	if (player_position.x == -1 || player_position.y == -1)
		return (0);
	if (collectibles.positions == NULL)
		return (0);
	if (exit_position.x == -1 || exit_position.y == -1)
		return (0);
	if (!flood_check(map, player_position))
		return (0);
	return (1);
}

