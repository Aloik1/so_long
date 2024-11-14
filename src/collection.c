/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:00:11 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 16:00:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	modify_positions(t_map *map, int i)
{
	int	j;

	j = i;
	ft_printf("i is %d\n", i);
	if (!map->collectible->positions)
		return ;
	if (!(map->collectibles == 1))
	{
		// while (j < map->collectibles - 1)
		// {
		// 	// ft_printf("pointer to copy from: %p\n", map->collectible->positions[j + 1]);
		// 	map->collectible->positions[j] = map->collectible->positions[j + 1];
		// 	ft_printf("Copied\n");
		// 	j++;
		// }
		// i = 0;
		// while (map->collectible->positions[i])
		// {
		// 	ft_printf("index %i positions: %d %d\n", i, map->collectible->positions[i][0], map->collectible->positions[i][1]);
		// 	i++;
		// }
		map->collectible->positions[j][0] = '0';
		map->collectible->positions[j][1] = '0';
	}
	return ;
}

static void	delete_collectible_from_map(t_map *map, t_player_position *player)
{
	map->map_grid[player->y][player->x] = '0';
	ft_printf("Collectible deleted from map at position: (%d, %d)\n", player->x, player->y);
	return ;
}

static int	check_and_delete_collectible(t_game *game, t_player *player)
{
	int	i;

	i = 0;
	player->collectibles_collected = 0;
	if (!game || !player || !game->map || !game->map->collectible || !game->map->collectible->positions) 
	{
		ft_printf("Error: Null pointer detected in check_and_delete_collectible\n");
		return 0;
	}
	ft_printf("Collectible positions pointer: %p\n", (void *)game->map->collectible->positions);
	ft_printf("Starting collectible check...\n");
	while (i < game->map->collectible->collectibles_visible) 
	{
		ft_printf("Checking collectible at index %d\n", i);
		if (!game->map->collectible->positions[i])
		{
			ft_printf("Error: Null pointer detected in check_and_delete_collectible\n");
			return 0;
		}
		if (game->map->collectible->positions[i][0] == player->position.x &&
			game->map->collectible->positions[i][1] == player->position.y) 
		{
			ft_printf("Collectible found at player position (%d, %d)\n", player->position.x, player->position.y);
			modify_positions(game->map, i);
			player->collectibles_collected++;
			game->map->collectibles--;
			
			ft_printf("Collectible deleted! Remaining: %d\n", game->map->collectibles);
			delete_collectible_from_map(game->map, &player->position);
			return (1);
		}
		i++;
	}
	ft_printf("No collectible found at player position (%d, %d)\n", player->position.x, player->position.y);
	return (0);
}

int	collect_collectible(t_game *game, t_player *player)
{
	ft_printf("Game pointer: %p\n", (void *)game);
	ft_printf("Player pointer: %p\n", (void *)player);
	ft_printf("Collectible pointer: %p\n", (void *)game->map->collectible);
	ft_printf("Collectible positions pointer: %p\n", (void *)game->map->collectible->positions);

	if (!game || !player || !game->map || !game->map->collectible 
		|| !game->map->collectible->positions) 
	{
		ft_printf("Error: Null pointer detected in collect_collectible\n");
		return (0);
	}
	if (check_and_delete_collectible(game, player))
		return (1);
	return (0);
}


