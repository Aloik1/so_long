/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_player_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:15:02 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 17:31:15 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*player_up(t_game *game)
{
	ft_printf("Before moving up, move_up is %d\n", game->movement->move_up);
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
	ft_printf("Before moving down, move_down is %d\n", game->movement->move_down);
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
	ft_printf("Before moving right, move_right is %d\n", game->movement->move_right);
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
	ft_printf("Before moving left, move_left is %d\n", game->movement->move_left);
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

	ft_printf("Key pressed is %d\n", game->movement->key_pressed);
	texture_to_return = NULL;
	if (game->movement->key_pressed == 119 /*W*/)
	{
		texture_to_return = player_up(game);
		return (texture_to_return);
	}
	if (game->movement->key_pressed == 97 /*A*/)
	{
		texture_to_return = player_left(game);
		return (texture_to_return);
	}
	if (game->movement->key_pressed == 115 /*S*/)
	{
		texture_to_return = player_down(game);
		return (texture_to_return);
	}
	if (game->movement->key_pressed == 100 /*D*/)
	{
		texture_to_return = player_right(game);
		return (texture_to_return);
	}
	else
		return (game->player->player_texture);
	return (NULL);
}
