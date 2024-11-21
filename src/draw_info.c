/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:43:20 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 00:14:58 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_info(t_game *game, int moves)
{
	char	*str_to_print;
	char	*movements;
	char	*collectibles_collected;
	char	*collectibles_left;

	movements = ft_itoa(moves);
	collectibles_collected = ft_itoa(game->player->collectibles_collected);
	collectibles_left = ft_itoa(game->map->collectibles);
	str_to_print = ft_strjoin("Current moves: ", movements);
	mlx_string_put(game->window->mlx, game->window->win, 10, 10, 0xFFFFFF, str_to_print);
	free(str_to_print);
	str_to_print = ft_strjoin("Collectibles collectes: ", collectibles_collected);
	mlx_string_put(game->window->mlx, game->window->win, 10, 20, 0xFFFFFF, str_to_print);
	free(str_to_print);
	str_to_print = ft_strjoin("Collectibles remaining: ", collectibles_left);
	mlx_string_put(game->window->mlx, game->window->win, 10, 30, 0xFFFFFF, str_to_print);
	free(str_to_print);
	free(movements);
	free(collectibles_collected);
	free(collectibles_left);
}
