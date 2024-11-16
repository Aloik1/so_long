/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:09:34 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/16 16:19:41 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*choose_floor(t_game *game, int j, int i)
{
	ft_printf("Checking if all open\n");
	if (game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '0'
		&& game->map->map_grid[j + 1][i] == '0' && game->map->map_grid[j - 1][i] == '0')
		return(game->textures->floor_all_open);
	ft_printf("Checking horizontal path\n");
	if (game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '1'
		&& game->map->map_grid[j + 1][i] == '0' && game->map->map_grid[j - 1][i] == '0')
		return(game->textures->floor_top_bot);
	ft_printf("Checking vertical path\n");
	if (game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '0'
		&& game->map->map_grid[j + 1][i] == '1' && game->map->map_grid[j - 1][i] == '1')
		return(game->textures->floor_left_right);
	ft_printf("Checking if bot open\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_bot_open);
	ft_printf("Checking if left open\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_left_open);
	ft_printf("Checking if top open\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_top_open);
	ft_printf("Checking if left open\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_left_open);
	ft_printf("Checking top right corner\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_top_right_corner);
	ft_printf("Checking top left corner\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_top_left_corner);
	ft_printf("Checking bot left corner\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_bot_left_corner);
	ft_printf("Checking bot right corner\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_bot_right_corner);
	ft_printf("Checking if right is closed\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '1'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_right_closed);
	ft_printf("Checking if top is closed\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '1' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_top_closed);
	ft_printf("Checking if left is closed\n");
	if (game->map->map_grid[j - 1][i] == '1' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '0')
		return(game->textures->floor_left_closed);
	ft_printf("Checking if bot is closed\n");
	if (game->map->map_grid[j - 1][i] == '0' && game->map->map_grid[j + 1][i] == '0'
		&& game->map->map_grid[j][i + 1] == '0' && game->map->map_grid[j][i - 1] == '1')
		return(game->textures->floor_bot_closed);
	return (NULL);
}
