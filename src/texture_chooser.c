/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:03:11 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 23:19:02 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*more_ifs(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	if (i == game->textures->collectible_3_x 
		&& j == game->textures->collectible_3_y)
	{
		if (game->textures->collectible_3_state == 0)
			return (game->textures->collectible_destroyed);
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_4_x
		&& j == game->textures->collectible_4_y)
	{
		if (game->textures->collectible_4_state == 0)
			return (game->textures->collectible_destroyed);
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_5_x 
		&& j == game->textures->collectible_5_y)
	{
		if (game->textures->collectible_5_state == 0)
			return (game->textures->collectible_destroyed);
		texture_to_return = collectible_chooser(game);
	}
	return (texture_to_return);
}

void	*texture_chooser(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	if (i == game->textures->collectible_1_x 
		&& j == game->textures->collectible_1_y)
	{
		if (game->textures->collectible_1_state == 0)
			return (game->textures->collectible_destroyed);
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_2_x
		&& j == game->textures->collectible_2_y)
	{
		if (game->textures->collectible_2_state == 0)
			return (game->textures->collectible_destroyed);
		texture_to_return = collectible_chooser(game);
	}
	else
		texture_to_return = more_ifs(game, i, j);
	return (texture_to_return);
}
