/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_collectibles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:07:55 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 00:48:32 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	initialize_3_counts(t_game *game)
// {
// 	game->textures->collectible_1->count = 0;
// 	game->textures->collectible_2->count = 0;
// 	game->textures->collectible_3->count = 0;
// 	game->textures->collectible_1->number = 1;
// 	game->textures->collectible_2->number = 2;
// 	game->textures->collectible_3->number = 3;
// 	return ;
// }

// static int	initialize_3_positions(t_game *game)
// {
// 	game->textures->collectible_1->position = (int *)malloc(sizeof(int *));
// 	if(!game->textures->collectible_1->position)
// 		return (0);
// 	game->textures->collectible_2->position = (int *)malloc(sizeof(int *));
// 	if(!game->textures->collectible_1->position)
// 		return (0);
// 	game->textures->collectible_3->position = (int *)malloc(sizeof(int *));
// 	if(!game->textures->collectible_1->position)
// 		return (0);
// 	return (1);
// }

// int	initialize_3_collectibles(t_game *game)
// {
// 	game->textures->collectible_1 = (t_collectible_1 *)malloc(sizeof(t_collectible_1));
// 	if(!game->textures->collectible_1)
// 		return (0);
// 	game->textures->collectible_2 = (t_collectible_2 *)malloc(sizeof(t_collectible_2));
// 	if(!game->textures->collectible_2)
// 		return (0);
// 	game->textures->collectible_3 = (t_collectible_3 *)malloc(sizeof(t_collectible_3));
// 	if(!game->textures->collectible_3)
// 		return (0);
// 	// if (!initialize_3_positions(game))
// 	// 	return (0);
// 	initialize_3_counts(game);
// 	return (1);
// }