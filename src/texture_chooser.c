/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:03:11 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 00:17:25 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*more_ifs(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	ft_printf("Collectible position is %d %d\n", i, j);
	ft_printf("Position 1[0], Position 1[1] are %d %d\n", game->textures->collectible_1->position[0], game->textures->collectible_1->position[1]);
	ft_printf("Position 2[0], Position 2[1] are %d %d\n", game->textures->collectible_2->position[0], game->textures->collectible_2->position[1]);
	ft_printf("Position 3[0], Position 3[1] are %d %d\n", game->textures->collectible_3->position[0], game->textures->collectible_3->position[1]);
	ft_printf("Position 4[0], Position 4[1] are %d %d\n", game->textures->collectible_4->position[0], game->textures->collectible_4->position[1]);
	ft_printf("Position 5[0], Position 5[1] are %d %d\n", game->textures->collectible_5->position[0], game->textures->collectible_5->position[1]);
	if (i == game->textures->collectible_3->position[0] 
		&& j == game->textures->collectible_3->position[1])
	{
		if (game->textures->collectible_3->number == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		ft_printf("Entering collectible chooser 3\n");
		ft_printf("number for collectible 3 is: %d\n", game->textures->collectible_3->number);
		texture_to_return = collectible_3_chooser(game);
	}
	else if (i == game->textures->collectible_4->position[0] 
		&& j == game->textures->collectible_4->position[1])
	{
		if (game->textures->collectible_4->number == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		ft_printf("Entering collectible chooser 4\n");
		ft_printf("number for collectible 4 is: %d\n", game->textures->collectible_4->number);

		texture_to_return = collectible_4_chooser(game);
	}
	else if (i == game->textures->collectible_5->position[0] 
		&& j == game->textures->collectible_5->position[1])
	{
		if (game->textures->collectible_5->number == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		ft_printf("number for collectible 5 is: %d\n", game->textures->collectible_5->number);

		ft_printf("Entering collectible chooser 5\n");
		texture_to_return = collectible_5_chooser(game);
	}
	return (texture_to_return);
}

void	*texture_chooser(t_game *game, int i, int j)
{
	void	*texture_to_return;
	
	texture_to_return = NULL;
	ft_printf("i is %d and j is %d\n", i, j);
	if (i == game->textures->collectible_1->position[0] 
		&& j == game->textures->collectible_1->position[1])
	{
		ft_printf("Entering collectible chooser 1\n");
		ft_printf("number for collectible 1 is: %d\n", game->textures->collectible_1->number);
		ft_printf("collectible_1 position is %d %d\n", game->textures->collectible_1->position[0], i == game->textures->collectible_1->position[1]);
		if (game->textures->collectible_1->number == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_1_chooser(game);
	}
	else if (i == game->textures->collectible_2->position[0] 
		&& j == game->textures->collectible_2->position[1])
	{
		ft_printf("number for collectible 2 is: %d\n", game->textures->collectible_2->number);
		ft_printf("Entering collectible chooser 2\n");
		if (game->textures->collectible_2->number == 0)
		{
			ft_printf("collectible number is 0\n");
			return (game->textures->collectible_destroyed);
		}
		texture_to_return = collectible_2_chooser(game);
	}
	else
	{
		texture_to_return = more_ifs(game, i, j);
	}
	ft_printf("Texture chosen is: %p\n", texture_to_return);
	return (texture_to_return);
}
