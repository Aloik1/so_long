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

static void	move_up(t_player *player, t_map *map)
{
	if (!player || !map || !map->map_grid) 
	{
		ft_printf("Error: Null pointer detected in move_up\n");
		return;
	}
	ft_printf("Attempting to move up from (%d, %d)\n", player->position.x, player->position.y);

	// Check map bounds and grid access
	if (player->position.y > 0 && map->map_grid[player->position.y - 1] != NULL &&
		map->map_grid[player->position.y - 1][player->position.x] != '1')
	{
		player->position.y = player->position.y - 1;
		ft_printf("Moved up to (%d, %d)\n", player->position.x, player->position.y);
	}
	else
	{
		ft_printf("Move up blocked or out of bounds\n");
	}
}

static void	move_down(t_player *player, t_map *map)
{
	if (!player || !map || !map->map_grid) 
	{
		ft_printf("Error: Null pointer detected in move_down\n");
		return;
	}
	ft_printf("Attempting to move down from (%d, %d)\n", player->position.x, player->position.y);

	// Check map bounds and grid access
	if (player->position.y < map->rows - 1 && map->map_grid[player->position.y + 1] != NULL &&
		map->map_grid[player->position.y + 1][player->position.x] != '1')
	{
		player->position.y = player->position.y + 1;
		ft_printf("Moved down to (%d, %d)\n", player->position.x, player->position.y);
	}
	else
	{
		ft_printf("Move down blocked or out of bounds\n");
	}
}

static void	move_left(t_player *player, t_map *map)
{
	if (!player || !map || !map->map_grid) 
	{
		ft_printf("Error: Null pointer detected in move_left\n");
		return;
	}
	ft_printf("Attempting to move left from (%d, %d)\n", player->position.x, player->position.y);

	// Check map bounds and grid access
	ft_printf("Checking map bounds and grid access\n");
	ft_printf("Player position: (%d, %d)\n", player->position.x, player->position.y);
	if (player->position.x > 0 && map->map_grid[player->position.y] != NULL &&
		map->map_grid[player->position.y][player->position.x - 1] != '1')
	{
		player->position.x -= 1;
		ft_printf("Moved left to (%d, %d)\n", player->position.x, player->position.y);
	}
	else
	{
		ft_printf("Move left blocked or out of bounds\n");
	}
}

static void	move_right(t_player *player, t_map *map)
{
	if (!player || !map || !map->map_grid) 
	{
		ft_printf("Error: Null pointer detected in move_right\n");
		return;
	}
	ft_printf("Attempting to move right from (%d, %d)\n", player->position.x, player->position.y);

	// Check map bounds and grid access
	if (player->position.x < map->cols - 1 && map->map_grid[player->position.y] != NULL &&
		map->map_grid[player->position.y][player->position.x + 1] != '1')
	{
		player->position.x = player->position.x + 1;
		ft_printf("Moved right to (%d, %d)\n", player->position.x, player->position.y);
	}
	else
	{
		ft_printf("Move right blocked or out of bounds\n");
	}
}

int	movement(int keycode, t_game *game, t_textures *textures)
{
	if (!game || !game->player || !game->map) 
	{
		ft_printf("Error: Null pointer detected in movement\n");
		return (-1);
	}
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_W)
	{
		ft_printf("W key pressed\n");
		move_up(game->player, game->map);
	}
	else if (keycode == KEY_A)
	{
		ft_printf("A key pressed\n");
		move_left(game->player, game->map);
	}
	else if (keycode == KEY_S)
	{
		ft_printf("S key pressed\n");
		move_down(game->player, game->map);
	}
	else if (keycode == KEY_D)
	{
		ft_printf("D key pressed\n");
		move_right(game->player, game->map);
	}
	else
	{
		ft_printf("Invalid key pressed\n");
		return (-1);
	}
	// Debugging: Check pointers before redrawing

	ft_printf("Attempting to redraw everything\n");
	ft_printf("Player position after movement: (%d, %d)\n", game->player->position.x, game->player->position.y);
	if (collect_collectible(game, game->player))
	{
		redraw_everything(game);
		open_exit(game->map, game->player, game, textures);
	}
	else
	{
		ft_printf("Not enough collectibles to open the exit\n");
		redraw_everything(game);
		open_exit(game->map, game->player, game, textures);
	}
	return (0);
}
