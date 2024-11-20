/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_collectible_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:32:42 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 02:08:14 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	three_collectibles(t_textures *textures, t_map *map)
{
	ft_printf("Entering 3 collectibles\n");
	textures->collectible_1_x = map->collectible->positions[0][0];
	textures->collectible_1_y = map->collectible->positions[0][1];
	textures->collectible_2_x = map->collectible->positions[1][0];
	textures->collectible_2_y = map->collectible->positions[1][1];
	textures->collectible_3_x = map->collectible->positions[2][0];
	textures->collectible_3_y = map->collectible->positions[2][1];
	textures->collectible_1_state = 1;
	textures->collectible_2_state = 1;
	textures->collectible_3_state = 1;
	return ;
}

static void	two_collectibles(t_textures *textures, t_map *map)
{
	ft_printf("Entering 2 collectibles\n");
	textures->collectible_1_x = map->collectible->positions[0][0];
	textures->collectible_1_y = map->collectible->positions[0][1];
	textures->collectible_2_x = map->collectible->positions[1][0];
	textures->collectible_2_y = map->collectible->positions[1][1];
	textures->collectible_1_state = 1;
	textures->collectible_2_state = 1;
	return ;
}

void	more_collectible_textures(t_textures *textures, t_map *map)
{
	if (map->collectibles == 3)
		three_collectibles(textures, map);
	if (map->collectibles == 2)
		two_collectibles(textures, map);
	if (map->collectibles == 1)
	{
		ft_printf("Entering 1 collectibles\n");
		textures->collectible_1_x = map->collectible->positions[0][0];
		textures->collectible_1_y = map->collectible->positions[0][1];
		textures->collectible_1_state = 1;
		ft_printf("Collectible position in more collectible textures is: %d %d\n", textures->collectible_1_x, textures->collectible_1_y);
	}
	return ;
}