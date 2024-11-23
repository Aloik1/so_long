/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spaces_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:16:03 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 15:47:13 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	three_free_spaces_1(t_game *game, int pos_x, int pos_y, int direction, int enemy_number)
{
	pos_y--;
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction + 1);
}

int	three_free_spaces_2(t_game *game, int pos_x, int pos_y, int direction, int enemy_number)
{
	pos_y++;
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction + 2);
}

int	three_free_spaces_3(t_game *game, int pos_x, int pos_y, int direction, int enemy_number)
{
	pos_x--;
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction + 3);
}

int	three_free_spaces_4(t_game *game, int pos_x, int pos_y, int direction, int enemy_number)
{
	pos_x++;
	assign_positions(game, enemy_number, pos_y, pos_x);
	return (direction + 4);
}