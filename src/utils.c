/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:02:47 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/21 02:18:46 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	many_ifs(t_game *game, int i, int j)
{
	if (game->map->map_grid[i][j] == '0'
		|| game->map->map_grid[i][j] == 'E'
		|| game->map->map_grid[i][j] == 'P'
		|| game->map->map_grid[i][j] == 'C'
		|| game->map->map_grid[i][j] == 'X')
		return (1);
	return (0);
}

static int	memory_reservation(t_game *game)
{
	int	rows;

	rows = game->map->rows;
	game->map->map_aux = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!game->map->map_aux)
	{
		ft_printerror("Couldn't allocate memory for map_aux");
		return (0);
	}
	return (1);
}

void	aux_map_creation(t_game *game)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_strlen(game->map->map_grid[i]);
	if (!memory_reservation(game))
		return ;
	while (i < game->map->rows)
	{
		j = 0;
		game->map->map_aux[i] = (char *)malloc(length);
		while (j < game->map->cols)
		{
			if (many_ifs(game, i, j))
				game->map->map_aux[i][j] = '0';
			else
				game->map->map_aux[i][j] = game->map->map_grid[i][j];
			j++;
		}
		i++;
	}
	game->map->map_aux[i] = NULL;
}
