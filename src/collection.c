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

static int	check_if_collected(t_game *game)
{
	ft_printf("Entering collected check\n");
	// ft_printf("Position 1[0], Position 1[1] are %d %d\n", game->textures->collectible_1->position[0], game->textures->collectible_1->position[1]);
	// ft_printf("Position 2[0], Position 2[1] are %d %d\n", game->textures->collectible_2->position[0], game->textures->collectible_2->position[1]);
	// ft_printf("Position 3[0], Position 3[1] are %d %d\n", game->textures->collectible_3->position[0], game->textures->collectible_3->position[1]);
	// ft_printf("Position 4[0], Position 4[1] are %d %d\n", game->textures->collectible_4->position[0], game->textures->collectible_4->position[1]);
	if (game->player->position.y == game->textures->collectible_1->position[0]
		&& game->player->position.x == game->textures->collectible_1->position[1])
	{
		ft_printf("Number 1\n");
		if (game->textures->collectible_1->number > 0)
			return (1);
	}
	else if (game->player->position.y == game->textures->collectible_2->position[0]
		&& game->player->position.x == game->textures->collectible_2->position[1])
	{
		ft_printf("Number 2\n");
		if (game->textures->collectible_2->number > 0)
			return (1);
	}
	else if (game->player->position.y == game->textures->collectible_3->position[0]
		&& game->player->position.x == game->textures->collectible_3->position[1])
	{
		ft_printf("Number 3\n");
		if (game->textures->collectible_3->number > 0)
			return (1);
	}
	else if (game->player->position.y == game->textures->collectible_4->position[0]
		&& game->player->position.x == game->textures->collectible_4->position[1])
	{
		ft_printf("Number 4\n");
		if (game->textures->collectible_4->number > 0)
			return (1);
	}
	else if (game->player->position.y == game->textures->collectible_5->position[0]
		&& game->player->position.x == game->textures->collectible_5->position[1])
	{
		ft_printf("Number 5\n");
		if (game->textures->collectible_5->number > 0)
			return (1);
	}
	return (0);
}

static void	delete_collectible_from_map(t_game *game/*, t_map *map*/, t_player_position *player)
{
	// ft_printf("Position 1[0], Position 1[1] are %d %d\n", game->textures->collectible_1->position[0], game->textures->collectible_1->position[1]);
	// ft_printf("Position 2[0], Position 2[1] are %d %d\n", game->textures->collectible_2->position[0], game->textures->collectible_2->position[1]);
	// ft_printf("Position 3[0], Position 3[1] are %d %d\n", game->textures->collectible_3->position[0], game->textures->collectible_3->position[1]);
	// ft_printf("Position 4[0], Position 4[1] are %d %d\n", game->textures->collectible_4->position[0], game->textures->collectible_4->position[1]);
	// ft_printf("Position 5[0], Position 5[1] are %d %d\n", game->textures->collectible_5->position[0], game->textures->collectible_5->position[1]);
	ft_printf("Player position y is %d\nPlayer position x is %d\n", player->y, player->x);
	if (player->y == game->textures->collectible_1->position[0] && player->x == game->textures->collectible_1->position[1]
		&& game->textures->collectible_1->number != 0)
	{
		ft_printf("number for collectible 1 before is: %d\n", game->textures->collectible_1->number);
		game->textures->collectible_1->number = 0;
		// game->textures->collectible_1->position[0] = 0;
		// game->textures->collectible_1->position[1] = 0;
		ft_printf("number for collectible 1 after is: %d\n", game->textures->collectible_1->number);
		return ;
	}
	if (player->y == game->textures->collectible_2->position[0] && player->x == game->textures->collectible_2->position[1]
		&& game->textures->collectible_2->number != 0)
	{
		ft_printf("number for collectible 2 before is: %d\n", game->textures->collectible_2->number);
		game->textures->collectible_2->number = 0;
		// game->textures->collectible_2->position[0] = 0;
		// game->textures->collectible_2->position[1] = 0;
		ft_printf("number for collectible 2 after is: %d\n", game->textures->collectible_2->number);
		return ;
	}
	if (player->y == game->textures->collectible_3->position[0] && player->x == game->textures->collectible_3->position[1]
		&& game->textures->collectible_3->number != 0)
	{
		ft_printf("number for collectible 3 before is: %d\n", game->textures->collectible_3->number);
		game->textures->collectible_3->number = 0;
		// game->textures->collectible_3->position[0] = 0;
		// game->textures->collectible_3->position[1] = 0;
		ft_printf("number for collectible 3 after is: %d\n", game->textures->collectible_3->number);
		return ;
	}
	if (player->y == game->textures->collectible_4->position[0] && player->x == game->textures->collectible_4->position[1]
		&& game->textures->collectible_4->number != 0)
	{
		ft_printf("number for collectible 4 before is: %d\n", game->textures->collectible_4->number);
		game->textures->collectible_4->number = 0;
		// game->textures->collectible_4->position[0] = 0;
		// game->textures->collectible_4->position[1] = 0;
		ft_printf("number for collectible 4 after is: %d\n", game->textures->collectible_4->number);
		return ;
	}
	if (player->y == game->textures->collectible_5->position[0] && player->x == game->textures->collectible_5->position[1]
		&& game->textures->collectible_5->number != 0)
	{
		ft_printf("number for collectible 5 before is: %d\n", game->textures->collectible_5->number);
		game->textures->collectible_5->number = 0;
		// game->textures->collectible_5->position[0] = 0;
		// game->textures->collectible_5->position[1] = 0;
		ft_printf("number for collectible 5 after is: %d\n", game->textures->collectible_5->number);
		return ;
	}
	else
	{
		game->map->collectibles++;
		game->player->collectibles_collected--;
	}

	// map->map_grid[player->y][player->x] = '0';
	return ;
}

static int	check_and_delete_collectible(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	//player->collectibles_collected = 0;
	if (!game || !player || !game->map || !game->map->collectible || !game->map->collectible->positions) 
	{
		ft_printf("Error: Null pointer detected in check_and_delete_collectible\n");
		return 0;
	}
	ft_printf("Collectible positions pointer: %p\n", (void *)game->map->collectible->positions);
	ft_printf("Player positon is %d %d\n", game->player->position.x, game->player->position.y);
	ft_printf("Starting collectible check...\n");
	while (i < game->map->collectible->collectibles_visible) 
	{
		ft_printf("Checking collectible at index %d\n", i);
		if (!game->map->collectible->positions[i])
		{
			ft_printf("Error: Null pointer detected in check_and_delete_collectible\n");
			return 0;
		}
		j = 0;
		while (game->map->collectible->positions[j])
		{
			ft_printf("Checking positions index %d, values are %d %d\n", j, game->map->collectible->positions[j][0], game->map->collectible->positions[j][1]);
			if (game->map->collectible->positions[j][0] == player->position.y 
				&& game->map->collectible->positions[j][1] == player->position.x)
			{
				if (!check_if_collected(game))
					return (0);
				ft_printf("Collectible found at player position (%d, %d)\n", player->position.y, player->position.x);
				

				ft_printf("Position to check is: %d \n", i);
				// ft_printf("Positions[0][0], positions[0][1] are %d %d\n", game->textures->collectible_1->position[0], game->textures->collectible_1->position[1]);
				// ft_printf("Positions[1][0], positions[1][1] are %d %d\n", game->textures->collectible_2->position[0], game->textures->collectible_2->position[1]);
				// ft_printf("Positions[2][0], positions[2][1] are %d %d\n", game->textures->collectible_3->position[0], game->textures->collectible_3->position[1]);
				// ft_printf("Positions[3][0], positions[3][1] are %d %d\n", game->textures->collectible_4->position[0], game->textures->collectible_4->position[1]);
				// ft_printf("Positions[4][0], positions[4][1] are %d %d\n", game->textures->collectible_5->position[0], game->textures->collectible_5->position[1]);
				
				
				delete_collectible_from_map(game,/* game->map,*/ &player->position);
				ft_printf("Collectible deleted! Remaining: %d\n", game->map->collectibles);
				// modify_positions(game->map, i);
				player->collectibles_collected++;
				game->map->collectibles--;
				return (1);
			}
			j++;
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


