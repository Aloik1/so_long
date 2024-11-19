/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_position_adder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:59:14 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 01:25:34 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	five_collectibles_positions(t_game *game)
{
	game->textures->collectible_1->position = game->map->collectible->positions[0];
	game->textures->collectible_2->position = game->map->collectible->positions[1];
	game->textures->collectible_3->position = game->map->collectible->positions[2];
	game->textures->collectible_4->position = game->map->collectible->positions[3];
	game->textures->collectible_5->position = game->map->collectible->positions[4];
	ft_printf("Position 1 is: %d %d\n", game->textures->collectible_1->position[0], game->textures->collectible_1->position[1]);
	ft_printf("Position 2 is: %d %d\n", game->textures->collectible_2->position[0], game->textures->collectible_2->position[1]);
	ft_printf("Position 3 is: %d %d\n", game->textures->collectible_3->position[0], game->textures->collectible_3->position[1]);
	ft_printf("Position 4 is: %d %d\n", game->textures->collectible_4->position[0], game->textures->collectible_4->position[1]);
	ft_printf("Position 5 is: %d %d\n", game->textures->collectible_5->position[0], game->textures->collectible_5->position[1]);
}

void	four_collectibles_positions(t_game *game)
{
	int	**position;
	
	position = game->map->collectible->positions;
	game->textures->collectible_1->position = position[0];
	game->textures->collectible_2->position = position[1];
	game->textures->collectible_3->position = position[2];
	game->textures->collectible_4->position = position[3];
}

void	three_collectibles_positions(t_game *game)
{
	int	**position;
	
	position = game->map->collectible->positions;
	game->textures->collectible_1->position = position[0];
	game->textures->collectible_2->position = position[1];
	game->textures->collectible_3->position = position[2];
}

void	two_collectibles_positions(t_game *game)
{
	int	**position;
	
	position = game->map->collectible->positions;
	game->textures->collectible_1->position = position[0];
	game->textures->collectible_2->position = position[1];
}
void	collectible_position_adder(t_game *game)
{
	int	**position;
	
	position = game->map->collectible->positions;
	if (game->map->collectibles == 5)
		five_collectibles_positions(game);
	if (game->map->collectibles == 4)
		four_collectibles_positions(game);
	if (game->map->collectibles == 3)
		three_collectibles_positions(game);
	if (game->map->collectibles == 2)
		two_collectibles_positions(game);
	if (game->map->collectibles == 1)
		game->textures->collectible_1->position = position[0];
	
	
}
