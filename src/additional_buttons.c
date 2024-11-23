/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:56:35 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/23 17:16:28 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	escape_button(int keycode, t_game *game)
{
	if (keycode == 65307)
		clean_exit(game);
	return (0);
}

void	*choose_same_texture(t_game *game)
{
	if (game->movement->previous_key_pressed == 119)
		return (game->textures->player_up_1);
	if (game->movement->previous_key_pressed == 115)
		return (game->textures->player_down_1);
	if (game->movement->previous_key_pressed == 97)
		return (game->textures->player_left_1);
	if (game->movement->previous_key_pressed == 100)
		return (game->textures->player_right_1);
	return (NULL);
}

void	enter_press(t_game *game, int moves)
{
	redraw_everything(game, game->textures, moves);
	return ;
}
