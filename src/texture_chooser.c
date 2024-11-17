/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:03:11 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/18 00:47:03 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*texture_chooser(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	if (i == game->textures->collectible_1->position[0] 
		&& j == game->textures->collectible_1->position[1])
	{
		ft_printf("Entering collectible chooser 1\n");
		texture_to_return = collectible_1_chooser(game);
	}
	else if (i == game->textures->collectible_2->position[0] 
		&& j == game->textures->collectible_2->position[1])
	{
		ft_printf("Entering collectible chooser 2\n");
		texture_to_return = collectible_2_chooser(game);
	}
	else if (i == game->textures->collectible_3->position[0] 
		&& j == game->textures->collectible_3->position[1])
	{
		ft_printf("Entering collectible chooser 3\n");
		texture_to_return = collectible_3_chooser(game);
	}
	else if (i == game->textures->collectible_4->position[0] 
		&& j == game->textures->collectible_4->position[1])
	{
		ft_printf("Entering collectible chooser 4\n");
		texture_to_return = collectible_1_chooser(game);
	}
	else if (i == game->textures->collectible_5->position[0] 
		&& j == game->textures->collectible_5->position[1])
	{
		ft_printf("Entering collectible chooser 5\n");
		texture_to_return = collectible_1_chooser(game);
	}
	return (texture_to_return);
}
