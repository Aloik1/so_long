/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:09 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 17:04:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_flood_grid(t_flood_grid flood_grid)
{
	int		i;

	i = 0;
	while (i < flood_grid.rows)
	{
		free(flood_grid.flood_map[i]);
		i++;
	}
	free(flood_grid.flood_map);
}

void	explore_flood_grid(t_flood_grid *flood_grid, int current_x, int current_y)
{
	if (current_x < 0 || current_y < 0 || current_x >= flood_grid->cols
		|| current_y >= flood_grid->rows)
		return ;
	if (flood_grid->flood_map[current_y][current_x] == '1' || flood_grid->flood_map[current_y][current_x] == 'V') {
		return;
	}
	if (flood_grid->flood_map[current_y][current_x] == 'C')
		flood_grid->collectibles_count--;
	if (flood_grid->flood_map[current_y][current_x] == 'E')
		flood_grid->exits_count--;
	flood_grid->flood_map[current_y][current_x] = 'V';
	if (flood_grid->collectibles_count == 0 && flood_grid->exits_count == 0) 
		return ;	
	explore_flood_grid(flood_grid, current_x + 1, current_y);
	explore_flood_grid(flood_grid, current_x - 1, current_y);
	explore_flood_grid(flood_grid, current_x, current_y + 1);
	explore_flood_grid(flood_grid, current_x, current_y - 1);
}

static t_flood_grid	create_flood_grid(t_map *map)
{
	t_flood_grid	flood_grid;
	int		i;
	int		j;

	i = 0;
	flood_grid.rows = map->rows;
	flood_grid.flood_map = malloc(sizeof(char *) * map->rows);
	while (i < map->rows)
	{
		flood_grid.flood_map[i] = malloc(sizeof(char) * (map->cols + 1));
		j = 0;
		while (j < map->cols)
		{
			flood_grid.flood_map[i][j] = map->map_grid[i][j];
			j++;
		}
		flood_grid.flood_map[i][map->cols] = '\0';
		i++;
	}
	return (flood_grid);
}

int	flood_check(t_map *map, t_player_position player_position)
{
	t_flood_grid	flood;
	int		valid_path;
	
	flood = create_flood_grid(map);
	flood.collectibles_count = map->collectibles;
	flood.exits_count = map->exits;
	flood.start_x = player_position.x;
	flood.start_y = player_position.y;
	flood.cols = map->cols;
	flood.rows = map->rows;
	explore_flood_grid(&flood, flood.start_x, flood.start_y);
	valid_path = (flood.collectibles_count == 0 && flood.exits_count == 0);
	free_flood_grid(flood);
	return (valid_path);
}
