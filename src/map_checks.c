/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:54:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 15:54:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_checks_rectangle(t_map *map)
{
	size_t	i;
	int	j;

	i = ft_strlen(map->map_grid[0]);
	j = 0;
	while (map->map_grid[j])
	{
		if (ft_strlen(map->map_grid[j]) != i
			&& ft_strlen(map->map_grid[j]) != i - 1)
		{
			ft_printerror("Map is not a rectangle\n");
			return (0);
		}
		j++;
	}
	return (1);
}

static int	map_checks_first_last_line(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map_grid[0][i + 1] != '\0')
	{
		if (map->map_grid[0][i] != '1')
		{
			ft_printerror("First line is not walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (map->map_grid[map->rows - 1][i + 1] != '\0')
	{
		if (map->map_grid[map->rows - 1][i] != '1')
		{
			ft_printerror("Last line is not walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}


static int	map_checks_horizontal_edges(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_grid[i])
	{
		if (map->map_grid[i][0] != '1' || map->map_grid[i][map->cols - 1] != '1')
		{
			ft_printerror("Sides are not walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	map_checks_errors(t_map *map)
{
	if (map->rows == 0 || map->cols == 0 || map->collectibles == 0 
		|| map->exits == 0 || map->players == 0)
	{
		ft_printerror("Cols, rows, collectibles, exits or players is 0\n");
		return (0);
	}
	return (1);
}

int	map_checks(t_map *map)
{
	if (!map_checks_first_last_line(map) || !map_checks_horizontal_edges(map)
		|| !map_checks_errors(map) || !map_checks_rectangle(map))
		return (0);
	return (1);
}
