/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:57:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 13:57:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_initialize(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!memory_check_map(game->map))
		return (0);
	game->map->rows = 0;
	game->map->cols = 0;
	game->map->collectibles = 0;
	game->map->exits = 0;
	game->map->players = 0;
	game->map->exit_x = 0;
	game->map->exit_y = 0;
	game->map->collectible = (t_collectible_position *)malloc
		(sizeof(t_collectible_position));
	if (!game->map->collectible)
		return (0);
	game->map->map_aux = NULL;
	game->movement = (t_movement *)malloc(sizeof(t_movement));
	if (!game->movement)
		return (0);
	game->movement->move_down = 0;
	game->movement->move_up = 0;
	game->movement->move_left = 0;
	game->movement->move_right = 0;
	game->movement->key_pressed = 0;
	game->movement->previous_key_pressed = 0;
	return (1);
}

static int	count_elements(t_map *map, int fd, char *line)
{
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map_grid[i] = line;
		if (ft_strchr(line, 'C'))
			check_collectible_line(map, line);
		if (ft_strchr(line, 'E'))
			map->exits++;
		if (ft_strchr(line, 'P'))
			map->players++;
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

static int	map_reader(t_map *map, int fd, char *line)
{
	int		i;

	i = count_elements(map, fd, line);
	if (i == 0)
		return (0);
	map->map_grid[i] = NULL;
	map->rows = i;
	map->cols = ft_strlen(map->map_grid[0]);
	if (map->rows == 0 || map->cols == 0 || map->collectibles == 0
		|| map->exits == 0 || map->players == 0)
	{
		ft_printerror("Error: Invalid map\n");
		free_map(map);
		return (1);
	}
	if (!map_checks(map))
		return (0);
	return (1);
}

static int	initialize_grid_and_check_fd(t_game *game, int fd)
{
	if (!memory_check_fd(fd))
		return (0);
	game->map->map_grid = (char **)malloc(sizeof(char *) * 1000);
	if (!memory_check_grid(game->map))
		return (0);
	return (1);
}

int	read_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	if (!map_initialize(game))
		return (0);
	fd = open(file, O_RDONLY);
	if (!initialize_grid_and_check_fd(game, fd))
		return (0);
	if (!map_reader(game->map, fd, line))
		return (0);
	game->map->collectible->positions = (int **)malloc(sizeof(int *)
			* (game->map->collectibles + 1));
	if (!game->map->collectible->positions)
		return (0);
	while (i < game->map->collectibles)
	{
		game->map->collectible->positions[i] = malloc(sizeof(int) * 2);
		i++;
	}
	game->map->collectible->positions[i] = NULL;
	close(fd);
	return (1);
}
