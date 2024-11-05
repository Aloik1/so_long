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

static int	memory_check_grid(t_map **map)
{
	if (!(*map)->map_grid)
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

static int	memory_check_map(t_map **map)
{
	if (!*map)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	return (1);
}

static int	map_reader(t_map **map, int fd, char *line)
{
	int		i;
	size_t	len;

	i = 0;
	while ((line = get_next_line(fd)) && line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		(*map)->map_grid[i] = line;
		if (ft_strchr(line, 'C'))
			(*map)->collectibles++;
		if (ft_strchr(line, 'E'))
			(*map)->exits++;
		if (ft_strchr(line, 'P'))
			(*map)->players++;
		i++;
	}
	(*map)->map_grid[i] = NULL;
	(*map)->rows = i;
	(*map)->cols = ft_strlen((*map)->map_grid[0]);
	if (!map_checks(*map))
		return (0);
	return (1);
}

int	read_map(char *file, t_map **map)
{
	int		fd;
	char		*line;

	line = NULL;
	// Allocate memory for the map
	*map = (t_map *)malloc(sizeof(t_map));
	if (!memory_check_map(map))
		return (0);
	// initialize the map
	(*map)->rows = 0;
	(*map)->cols = 0;
	(*map)->collectibles = 0;
	(*map)->exits = 0;
	(*map)->players = 0;
	
	// Debug print to check the file path
	ft_printf("Attempting to open file: %s\n", file);

	// Open the map file
	fd = open(file, O_RDONLY);
	if (!memory_check_fd(fd))
		return (0);
	// read the map file
	(*map)->map_grid = (char **)malloc(sizeof(char *) * 1000);
	if (!memory_check_grid(map))
		return (0);
	if (!map_reader(map, fd, line))
		return (0);
	close(fd);
	return (1);
}
