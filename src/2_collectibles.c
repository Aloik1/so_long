/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_collectibles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:23:39 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 00:48:40 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	initialize_2_counts(t_game *game)
// {
// 	game->textures->collectible_1->count = 0;
// 	game->textures->collectible_2->count = 0;
// 	game->textures->collectible_1->number = 1;
// 	game->textures->collectible_2->number = 2;
// 	return ;
// }

// static int	initialize_2_positions(t_game *game)
// {
// 	game->textures->collectible_1->position = (int *)malloc(sizeof(int) * 2);
// 	if(!game->textures->collectible_1->position)
// 		return (0);
// 	game->textures->collectible_2->position = (int *)malloc(sizeof(int) * 2);
// 	if(!game->textures->collectible_2->position)
// 		return (0);
// 	return (1);
// }

// int	initialize_2_collectibles(t_game *game)
// {
// 	game->textures->collectible_1 = (t_collectible_1 *)malloc(sizeof(t_collectible_1));
// 	if(!game->textures->collectible_1)
// 		return (0);
// 	game->textures->collectible_2 = (t_collectible_2 *)malloc(sizeof(t_collectible_2));
// 	if(!game->textures->collectible_2)
// 		return (0);
// 	// if (!initialize_2_positions(game))
// 	// 	return (0);
// 	initialize_2_counts(game);
// 	return (1);
// }