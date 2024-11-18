/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:55:05 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 00:05:53 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*collectible_1_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_1->count > 4)
	{
		game->textures->collectible_1->count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_1->count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_1->count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_1->count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_1->count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_1->count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_1->count++;
	return (texture);
}
void	*collectible_2_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_2->count > 4)
	{
		game->textures->collectible_2->count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_2->count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_2->count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_2->count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_2->count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_2->count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_2->count++;
	return (texture);
}

void	*collectible_3_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_3->count > 4)
	{
		game->textures->collectible_3->count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_3->count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_3->count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_3->count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_3->count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_3->count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_3->count++;
	return (texture);
}

void	*collectible_4_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_4->count > 4)
	{
		game->textures->collectible_4->count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_4->count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_4->count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_4->count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_4->count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_4->count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_4->count++;
	return (texture);
}

void	*collectible_5_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_5->count > 4)
	{
		game->textures->collectible_5->count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_5->count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_5->count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_5->count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_5->count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_5->count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_5->count++;
	return (texture);
}