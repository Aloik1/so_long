/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:55:05 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 02:47:52 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*collectible_chooser(t_game *game)
{
	void	*texture;

	texture = NULL;
	if (game->textures->collectible_count > 4)
	{
		game->textures->collectible_count = 0;
		texture = game->textures->collectible_animation_1;
		return (texture);
	}
	if (game->textures->collectible_count == 0)
		texture = game->textures->collectible_animation_1;
	if (game->textures->collectible_count == 1)
		texture = game->textures->collectible_animation_2;
	if (game->textures->collectible_count == 2)
		texture = game->textures->collectible_animation_3;
	if (game->textures->collectible_count == 3)
		texture = game->textures->collectible_animation_4;
	if (game->textures->collectible_count == 4)
		texture = game->textures->collectible_animation_5;
	game->textures->collectible_count++;
	return (texture);
}
