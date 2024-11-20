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

static int	more_checks_if_collected(t_game *game)
{
	if (game->player->position.x == game->textures->collectible_4_y
		&& game->player->position.y == game->textures->collectible_4_x)
	{
		if (game->textures->collectible_4_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_5_y
		&& game->player->position.y == game->textures->collectible_5_x)
	{
		if (game->textures->collectible_5_state > 0)
			return (1);
	}
	return (0);
}

static int	check_if_collected(t_game *game)
{
	if (game->player->position.x == game->textures->collectible_1_y
		&& game->player->position.y == game->textures->collectible_1_x)
	{
		if (game->textures->collectible_1_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_2_y
		&& game->player->position.y == game->textures->collectible_2_x)
	{
		if (game->textures->collectible_2_state > 0)
			return (1);
	}
	else if (game->player->position.x == game->textures->collectible_3_y
		&& game->player->position.y == game->textures->collectible_3_x)
	{
		if (game->textures->collectible_3_state > 0)
			return (1);
	}
	else if (more_checks_if_collected(game))
		return (1);
	return (0);
}

static void	delete_collectible_from_map(t_game *game, t_player_position *player)
{
	if (player->y == game->textures->collectible_1_x && player->x == game->textures->collectible_1_y
		&& game->textures->collectible_1_state != 0)
		game->textures->collectible_1_state = 0;
	else if (player->y == game->textures->collectible_2_x && player->x == game->textures->collectible_2_y
		&& game->textures->collectible_2_state != 0)
		game->textures->collectible_2_state = 0;
	else if (player->y == game->textures->collectible_3_x && player->x == game->textures->collectible_3_y
		&& game->textures->collectible_3_state != 0)
		game->textures->collectible_3_state = 0;
	else if (player->y == game->textures->collectible_4_x && player->x == game->textures->collectible_4_y
		&& game->textures->collectible_4_state != 0)
		game->textures->collectible_4_state = 0;
	else if (player->y == game->textures->collectible_5_x && player->x == game->textures->collectible_5_y
		&& game->textures->collectible_5_state != 0)
		game->textures->collectible_5_state = 0;
	else
	{
		game->map->collectibles++;
		game->player->collectibles_collected--;
	}
	return ;
}

static int	check_and_delete_collectible(t_game *game, t_player *player, int i, int j)
{
	if (!game || !player || !game->map || !game->map->collectible || !game->map->collectible->positions)
		return 0;
	while (i < game->map->collectible->collectibles_visible) 
	{
		if (!game->map->collectible->positions[i])
			return 0;
		j = 0;
		while (game->map->collectible->positions[j])
		{
			if (game->map->collectible->positions[j][0] == player->position.y 
				&& game->map->collectible->positions[j][1] == player->position.x)
			{
				if (!check_if_collected(game))
					return (0);
				delete_collectible_from_map(game, &player->position);
				player->collectibles_collected++;
				game->map->collectibles--;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	collect_collectible(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game || !player || !game->map || !game->map->collectible 
		|| !game->map->collectible->positions) 
		return (0);
	if (check_and_delete_collectible(game, player, i, j))
		return (1);
	return (0);
}


