/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:50:17 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 21:08:59 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_enemy(t_game *game, int pos_y, int pos_x)
{
	int	y;
	int	x;
	char	**map;

	y = pos_y;
	x = pos_x;
	map = game->map->map_aux;
	if (map[y - 1][x] == '0' && map[y + 1][x] == '0' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '0')
		return (4);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '1' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '0')
		return (3);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '0' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '1')
		return (3);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '0' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '0')
		return (3);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '0' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '0')
		return (3);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '0' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '1')
		return (2);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '0' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '0')
		return (2);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '0')
		return (2);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '0')
		return (2);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '1' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '1')
		return (2);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '0' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		return (2);
	if (map[y - 1][x] == '0' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '0'
		&& map[y][x + 1] == '1')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '0' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '0')
		return (1);
	return (0);
}