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

static int	get_exit_position(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map->map_grid[i][j])
	{
		if (map->map_grid[i][j] == 'E')
		{
			map->exit_x = j;
			map->exit_y = i;
			return (1);
		}
		j++;
		if (map->map_grid[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (0);
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

static int	get_collectibles_position(t_map *map)
{
	int			i;
	int			j;
	int			position_add;

	i = 0;
	j = 0;
	position_add = 0;
	while (i < map->rows)
	{
		while (j < map->cols)
		{
			if (map->map_grid[i][j] == 'C')
			{
				map->collectible->positions[position_add][0] = i;
				map->collectible->positions[position_add][1] = j;
				position_add++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (position_add);
}

int	path_checks(t_game *game)
{
	t_player_position	player_position;
	int			collectibles;

	player_position = get_player_position(game->map);
	collectibles = get_collectibles_position(game->map);
	if (!get_exit_position(game->map))
		return (0);
	if (player_position.x == -1 || player_position.y == -1)
		return (0);
	if (collectibles == 0)
		return (0);
	if (!flood_check(game->map, player_position))
		return (0);
	return (1);
}

