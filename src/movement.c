/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:44:44 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 19:44:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_up(t_game *game, t_player *player, t_map *map)
{
	game->movement->key_pressed = 119;
	game->movement->previous_key_pressed = 119;
	if (!player || !map || !map->map_grid)
		return ;
	if (player->position.y > 0 && map->map_grid[player->position.y - 1] != NULL
		&& map->map_grid[player->position.y - 1][player->position.x] != '1')
		player->position.y = player->position.y - 1;
}

static void	move_down(t_game *game, t_player *player, t_map *map)
{
	game->movement->key_pressed = 115;
	game->movement->previous_key_pressed = 115;
	if (!player || !map || !map->map_grid)
		return ;
	if (player->position.y < map->rows - 1
		&& map->map_grid[player->position.y + 1] != NULL
		&& map->map_grid[player->position.y + 1][player->position.x] != '1')
	{
		player->position.y = player->position.y + 1;
	}
}

static void	move_left(t_game *game, t_player *player, t_map *map)
{
	game->movement->key_pressed = 97;
	game->movement->previous_key_pressed = 97;
	if (!player || !map || !map->map_grid)
		return ;
	if (player->position.x > 0
		&& map->map_grid[player->position.y] != NULL
		&& map->map_grid[player->position.y][player->position.x - 1] != '1')
		player->position.x -= 1;
}

static void	move_right(t_game *game, t_player *player, t_map *map)
{
	game->movement->key_pressed = 100;
	game->movement->previous_key_pressed = 100;
	if (!player || !map || !map->map_grid)
		return ;
	if (player->position.x < map->cols - 1
		&& map->map_grid[player->position.y] != NULL
		&& map->map_grid[player->position.y][player->position.x + 1] != '1')
		player->position.x = player->position.x + 1;
}

int	movement(int keycode, t_game *game)
{
	static int	i;

	game->movement->key_pressed = 0;
	if (keycode == KEY_W)
		move_up(game, game->player, game->map);
	else if (keycode == KEY_A)
		move_left(game, game->player, game->map);
	else if (keycode == KEY_S)
		move_down(game, game->player, game->map);
	else if (keycode == KEY_D)
		move_right(game, game->player, game->map);
	else if (keycode == KEY_ENTER)
		enter_press(game, i);
	else
		return (escape_button(keycode, game));
	if (keycode != KEY_ENTER)
	{
		i++;
		ft_printf("Movement count is: %d\n", i);
		collect_collectible(game, game->player);
	}
	if (!(keycode == KEY_ENTER))
		redraw_everything(game, game->textures, i);
	open_exit(game->map, game->player, game);
	return (1);
}
