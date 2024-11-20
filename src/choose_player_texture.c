/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:15:02 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 23:48:09 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*player_up(t_game *game)
{
	if (game->movement->move_up == 0)
	{
		game->movement->move_up++;
		return (game->textures->player_up_1);
	}
	if (game->movement->move_up == 1)
	{
		game->movement->move_up++;
		return (game->textures->player_up_2);
	}
	if (game->movement->move_up == 2)
	{
		game->movement->move_up++;
		return (game->textures->player_up_3);
	}
	if (game->movement->move_up > 2)
	{
		game->movement->move_up = 0;
		return (game->textures->player_up_1);
	}
	return (NULL);
}

static void	*player_down(t_game *game)
{
	if (game->movement->move_down == 0)
	{
		game->movement->move_down++;
		return (game->textures->player_down_1);
	}
	if (game->movement->move_down == 1)
	{
		game->movement->move_down++;
		return (game->textures->player_down_2);
	}
	if (game->movement->move_down == 2)
	{
		game->movement->move_down++;
		return (game->textures->player_down_3);
	}
	if (game->movement->move_down > 2)
	{
		game->movement->move_down = 0;
		return (game->textures->player_down_1);
	}
	return (NULL);
}

static void	*player_right(t_game *game)
{
	if (game->movement->move_right == 0)
	{
		game->movement->move_right++;
		return (game->textures->player_right_1);
	}
	if (game->movement->move_right == 1)
	{
		game->movement->move_right++;
		return (game->textures->player_right_2);
	}
	if (game->movement->move_right == 2)
	{
		game->movement->move_right++;
		return (game->textures->player_right_3);
	}
	if (game->movement->move_right > 2)
	{
		game->movement->move_right = 0;
		return (game->textures->player_right_1);
	}
	return (NULL);
}

static void	*player_left(t_game *game)
{
	if (game->movement->move_left == 0)
	{
		game->movement->move_left++;
		return (game->textures->player_left_1);
	}
	if (game->movement->move_left == 1)
	{
		game->movement->move_left++;
		return (game->textures->player_left_2);
	}
	if (game->movement->move_left == 2)
	{
		game->movement->move_left++;
		return (game->textures->player_left_3);
	}
	if (game->movement->move_left > 2)
	{
		game->movement->move_left = 0;
		return (game->textures->player_left_1);
	}
	return (NULL);
}

void	*choose_player_texture(t_game *game)
{
	void	*texture_to_return;

	texture_to_return = NULL;
	if (game->movement->key_pressed == 119)
		texture_to_return = player_up(game);
	else if (game->movement->key_pressed == 97)
		texture_to_return = player_left(game);
	else if (game->movement->key_pressed == 115)
		texture_to_return = player_down(game);
	else if (game->movement->key_pressed == 100)
		texture_to_return = player_right(game);
	else if (game->movement->key_pressed != game->movement->previous_key_pressed)
		texture_to_return = choose_same_texture(game);
	else
		return (game->player->player_texture);
	return (texture_to_return);
	return (NULL);
}
