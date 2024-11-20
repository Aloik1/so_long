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

static int	memory_check_grid(t_map *map)
{
	if (!map->map_grid)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	return (1);
}

static int	memory_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printerror("Error: Failed to open map file\n");
		return (0);
	}
	return (1);
}

static int	memory_check_map(t_map *map)
{
	if (!map)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	return (1);
}

static int	map_reader(t_map *map, int fd, char *line)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while ((line = get_next_line(fd)) && line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->map_grid[i] = line;
		if (ft_strchr(line, 'C'))
		{
			j = 0;
			while (line[j])
			{
				if (line[j] == 'C')
					map->collectibles++;
				j++;
			}
		}
		if (ft_strchr(line, 'E'))
			map->exits++;
		if (ft_strchr(line, 'P'))
			map->players++;
		i++;
	}
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

int	read_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char		*line;

	i = 0;	
	line = NULL;
	// Allocate memory for the map
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!memory_check_map(game->map))
		return (0);
	// initialize the map
	game->map->rows = 0;
	game->map->cols = 0;
	game->map->collectibles = 0;
	game->map->exits = 0;
	game->map->players = 0;
	game->map->exit_x = 0;
	game->map->exit_y = 0;
	game->map->collectible = (t_collectible_position *)malloc(sizeof(t_collectible_position));
	game->map->map_aux = NULL;
	game->movement = (t_movement *)malloc(sizeof(t_movement));
	game->movement->move_down = 0;
	game->movement->move_up = 0;
	game->movement->move_left = 0;
	game->movement->move_right = 0;
	game->movement->key_pressed = 0;
	
	if (!game->map->collectible)
	{
		ft_printf("Error: Could not allocate memory for exit position.\n");
		return (0);
	}
	// Debug print to check the file path
	ft_printf("Attempting to open file: %s\n", file);

	// Open the map file
	fd = open(file, O_RDONLY);
	if (!memory_check_fd(fd))
		return (0);
	// read the map file
	game->map->map_grid = (char **)malloc(sizeof(char *) * 1000);
	if (!memory_check_grid(game->map))
		return (0);
	if (!map_reader(game->map, fd, line))
		return (0);
	ft_printf("collectibles are: %d\n", game->map->collectibles);
	game->map->collectible->positions = (int **)malloc(sizeof(int *) * (game->map->collectibles + 1));
	if (!game->map->collectible->positions)
		return (0);
	while (i < game->map->collectibles)
	{
		ft_printf("i is %d\n", i);
		game->map->collectible->positions[i] = malloc(sizeof(int) * 2);
		ft_printf("position pointer is %p\n", game->map->collectible->positions[i]);
		i++;
	}
	ft_printf("i is %d\n", i);
	ft_printf("Null terminating\n");
	// game->map->collectible->positions[i] = malloc(sizeof(int) * 2);
	game->map->collectible->positions[i] = NULL;
	//game->map->collectible->positions[i] = NULL;
	close(fd);
	return (1);
}
