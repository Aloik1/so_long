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

void free_map(t_map *map) 
{
    int i = 0;

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
        free(map);
    }
}

t_player_position	return_null_player(void)
{
	t_player_position	player_position;

	player_position.x = -1;
	player_position.y = -1;
	return (player_position);
}
t_collectible_position	return_null_and_free_collectibles(t_collectible_position collectibles)
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
t_exit_position	return_null_exit(void)
{
	t_exit_position	exit_position;

	exit_position.x = -1;
	exit_position.y = -1;
	return (exit_position);
}
