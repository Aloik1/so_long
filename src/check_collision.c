/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:23:46 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 23:36:13 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	final_checks(t_game *game)
{
	if (game->enemies->number_of_enemies == 5)
	{
		if ((game->enemies->enemy_1_y == game->player->position.y
		&& game->enemies->enemy_1_x == game->player->position.x)
		|| (game->enemies->enemy_2_y == game->player->position.y
		&& game->enemies->enemy_2_x == game->player->position.x)
		|| (game->enemies->enemy_3_y == game->player->position.y
		&& game->enemies->enemy_3_x == game->player->position.x)
		|| (game->enemies->enemy_4_y == game->player->position.y
		&& game->enemies->enemy_4_x == game->player->position.x)
		|| (game->enemies->enemy_5_y == game->player->position.y
		&& game->enemies->enemy_5_x == game->player->position.x))
		{
			ft_printf("You lose!\n");
			clean_exit(game);
		}
	}
}

static void	even_more_checks(t_game *game)
{
	if (game->enemies->number_of_enemies == 4)
	{
		if ((game->enemies->enemy_1_y == game->player->position.y
		&& game->enemies->enemy_1_x == game->player->position.x)
		|| (game->enemies->enemy_2_y == game->player->position.y
		&& game->enemies->enemy_2_x == game->player->position.x)
		|| (game->enemies->enemy_3_y == game->player->position.y
		&& game->enemies->enemy_3_x == game->player->position.x)
		|| (game->enemies->enemy_4_y == game->player->position.y
		&& game->enemies->enemy_4_x == game->player->position.x))
		{
			ft_printf("You lose!\n");
			clean_exit(game);
		}
	}
	final_checks(game);
}

static void	more_checks(t_game *game)
{
	if (game->enemies->number_of_enemies == 3)
	{
		if ((game->enemies->enemy_1_y == game->player->position.y
		&& game->enemies->enemy_1_x == game->player->position.x)
		|| (game->enemies->enemy_2_y == game->player->position.y
		&& game->enemies->enemy_2_x == game->player->position.x)
		|| (game->enemies->enemy_3_y == game->player->position.y
		&& game->enemies->enemy_3_x == game->player->position.x))
		{
			ft_printf("You lose!\n");
			clean_exit(game);
		}
	}
	even_more_checks(game);
}

void	check_collision(t_game *game)
{
	if (game->enemies->number_of_enemies == 1)
	{
		if (game->enemies->enemy_1_y == game->player->position.y
		&& game->enemies->enemy_1_x == game->player->position.x)
		{
			ft_printf("You lose!\n");
			clean_exit(game);
		}
	}
	if (game->enemies->number_of_enemies == 2)
	{
		if ((game->enemies->enemy_1_y == game->player->position.y
		&& game->enemies->enemy_1_x == game->player->position.x)
		|| (game->enemies->enemy_2_y == game->player->position.y
		&& game->enemies->enemy_2_x == game->player->position.x))
		{
			ft_printf("You lose!\n");
			clean_exit(game);
		}
	}
	more_checks(game);
}
