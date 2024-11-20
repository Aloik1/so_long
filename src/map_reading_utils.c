/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:45:28 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/20 17:52:04 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	memory_check_grid(t_map *map)
{
	if (!map->map_grid)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	return (1);
}

int	memory_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printerror("Error: Failed to open map file\n");
		return (0);
	}
	return (1);
}

int	memory_check_map(t_map *map)
{
	if (!map)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	return (1);
}