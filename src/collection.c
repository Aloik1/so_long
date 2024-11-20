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
	ft_printf("Player position y is %d\nPlayer position x is %d\n", game->player->position.y, game->player->position.x);
	ft_printf("game->textures->collectible_1_y %d\ngame->textures->collectible_1_x %d\n", game->textures->collectible_1_y, game->textures->collectible_1_x);
	ft_printf("game->textures->collectible_2_y %d\ngame->textures->collectible_2_x %d\n", game->textures->collectible_2_y, game->textures->collectible_2_x);
	ft_printf("Entering collected check\n");
	if (game->player->position.x == game->textures->collectible_1_y
		&& game->player->position.y == game->textures->collectible_1_x)
	{
		ft_printf("Number 1\n");
		if (game->textures->collectible_1_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_2_y
		&& game->player->position.y == game->textures->collectible_2_x)
	{
		ft_printf("Number 2\n");
		if (game->textures->collectible_2_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_3_y
		&& game->player->position.y == game->textures->collectible_3_x)
	{
		ft_printf("Number 3\n");
		if (game->textures->collectible_3_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_4_y
		&& game->player->position.y == game->textures->collectible_4_x)
	{
		ft_printf("Number 4\n");
		if (game->textures->collectible_4_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_5_y
		&& game->player->position.y == game->textures->collectible_5_x)
	{
		ft_printf("Number 5\n");
		if (game->textures->collectible_5_state > 0)
			return (1);
	}
	return (0);
}

static void	delete_collectible_from_map(t_game *game/*, t_map *map*/, t_player_position *player)
{
	ft_printf("Player position y is %d\nPlayer position x is %d\n", player->y, player->x);
	ft_printf("collectible_1_y collectible_1_x %d %d\n", game->textures->collectible_1_y, game->textures->collectible_1_x);
	ft_printf("collectible_2_y collectible_2_x %d %d\n", game->textures->collectible_2_y, game->textures->collectible_2_x);
	if (player->y == game->textures->collectible_1_x && player->x == game->textures->collectible_1_y
		&& game->textures->collectible_1_state != 0)
	{
		game->textures->collectible_1_state = 0;
		return ;
	}
	if (player->y == game->textures->collectible_2_x && player->x == game->textures->collectible_2_y
		&& game->textures->collectible_2_state != 0)
	{
		game->textures->collectible_2_state = 0;
		return ;
	}
	if (player->y == game->textures->collectible_3_x && player->x == game->textures->collectible_3_y
		&& game->textures->collectible_3_state != 0)
	{
		game->textures->collectible_3_state = 0;
		return ;
	}
	if (player->y == game->textures->collectible_4_x && player->x == game->textures->collectible_4_y
		&& game->textures->collectible_4_state != 0)
	{
		game->textures->collectible_4_state = 0;
		return ;
	}
	if (player->y == game->textures->collectible_5_x && player->x == game->textures->collectible_5_y
		&& game->textures->collectible_5_state != 0)
	{
		game->textures->collectible_5_state = 0;
		return ;
	}
	else
	{
		game->map->collectibles++;
		game->player->collectibles_collected--;
	}
	return ;
}

static int	check_and_delete_collectible(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
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
			ft_printf("Checking player position index %d, values are %d %d\n", j, game->player->position.y, game->player->position.x);
			if (game->map->collectible->positions[j][0] == player->position.y 
				&& game->map->collectible->positions[j][1] == player->position.x)
			{
				ft_printf("Collectible found at player position (%d, %d)\n", player->position.y, player->position.x);
				if (!check_if_collected(game))
					return (0);
				
				

				ft_printf("Position to check is: %d \n", i);
				
				delete_collectible_from_map(game, &player->position);
				ft_printf("Collectible deleted! Remaining: %d\n", game->map->collectibles);
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
	if (!game || !player || !game->map || !game->map->collectible 
		|| !game->map->collectible->positions) 
		return (0);
	if (check_and_delete_collectible(game, player))
		return (1);
	return (0);
}


