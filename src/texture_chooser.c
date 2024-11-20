/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:03:11 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 16:51:10 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*more_ifs(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	ft_printf("Collectible position is %d %d\n", i, j);
	if (i == game->textures->collectible_3_x 
		&& j == game->textures->collectible_3_y)
	{
		if (game->textures->collectible_3_state == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_4_x
		&& j == game->textures->collectible_4_y)
	{
		if (game->textures->collectible_4_state == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_5_x 
		&& j == game->textures->collectible_5_y)
	{
		if (game->textures->collectible_5_state == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_chooser(game);
	}
	return (texture_to_return);
}

void	*texture_chooser(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	ft_printf("i is %d and j is %d\n", i, j);
	ft_printf("Collectible position is: %d %d\n", game->textures->collectible_1_x, game->textures->collectible_1_y);
	ft_printf("Collectible position is: %d %d\n", game->textures->collectible_2_x, game->textures->collectible_2_y);
	if (i == game->textures->collectible_1_x 
		&& j == game->textures->collectible_1_y)
	{
		ft_printf("Collectible 1\n");
		if (game->textures->collectible_1_state == 0)
		{
			ft_printf("collectible state is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_chooser(game);
	}
	else if (i == game->textures->collectible_2_x
		&& j == game->textures->collectible_2_y)
	{
		ft_printf("Collectible 2\n");
		if (game->textures->collectible_2_state == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_chooser(game);
	}
	else
	{
		texture_to_return = more_ifs(game, i, j);
	}
	ft_printf("Texture chosen is: %p\n", texture_to_return);
	return (texture_to_return);
}
