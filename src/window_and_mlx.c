/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:32:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 14:32:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	window_and_mlx(t_game *game, t_window **window)
{
	(*window)->mlx = mlx_init();
	if (!(*window)->mlx)
	{
		ft_printerror("Failed to initialize mlx\n");
		return (0);
	}
	if (game->map->rows < 10 || game->map->cols < 10)
	{
		(*window)->win = mlx_new_window((*window)->mlx, game->map->cols * 96, 
			game->map->rows * 96, "so_long");
		if (!(*window)->win)
		{
			ft_printerror("Failed to create window\n");
			return (0);
		}
		return (1);
	}
	(*window)->win = mlx_new_window((*window)->mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (!(*window)->win)
	{
		ft_printerror("Failed to create window\n");
		return (0);
	}
	return (1);
}

