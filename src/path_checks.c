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

static int	get_collectibles_position(t_map *map)
{
	int			i;
	int			j;
	int			position_add;
	int			pos_count;

	i = 0;
	j = 0;
	position_add = 0;
	pos_count = 0;
	while (i < map->rows)
	{
		while (j < map->cols)
		{
			if (map->map_grid[i][j] == 'C')
			{
				pos_count++;
				map->collectible->positions[position_add][0] = i;
				map->collectible->positions[position_add][1] = j;
				ft_printf("Position %d is %d %d\n", position_add, i, j);
				position_add++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (pos_count);
}

int	path_checks(t_game *game)
{
	t_player_position	player_position;
	int			collectibles;
	t_exit_position		exit_position;

	player_position = get_player_position(game->map);
	collectibles = get_collectibles_position(game->map);
	exit_position = get_exit_position(game->map);
	if (player_position.x == -1 || player_position.y == -1)
		return (0);
	if (collectibles == 0)
		return (0);
	if (exit_position.x == -1 || exit_position.y == -1)
		return (0);
	if (!flood_check(game->map, player_position))
		return (0);
	return (1);
}

