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

void	aux_map_creation(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	game->map->map_aux = (char **)malloc(sizeof(char *) * (game->map->rows + 1));
	if (!game->map->map_aux)
	{
		ft_printerror("Couldn't allocate memory for map_aux");
		return ;
	}
	while (i < game->map->rows)
	{
		j = 0;
		game->map->map_aux[i] = (char *)malloc(ft_strlen(game->map->map_grid[i]));
		while (j < game->map->cols)
		{
			if (game->map->map_grid[i][j] == '0' || game->map->map_grid[i][j] == 'E'
			|| game->map->map_grid[i][j] == 'P' || game->map->map_grid[i][j] == 'C'
			|| game->map->map_grid[i][j] == 'X')
				game->map->map_aux[i][j] = '0';
			else
				game->map->map_aux[i][j] = game->map->map_grid[i][j];
			j++;
		}
		i++;
	}
	game->map->map_aux[i] = NULL;
	
}