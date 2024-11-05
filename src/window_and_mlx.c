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

int	window_and_mlx(t_window **window)
{
	// allocate memory for the window
	*window = (t_window *)malloc(sizeof(t_window));
	if (!*window)
	{
		ft_printerror("Error: Failed to allocate memory\n");
		return (0);
	}
	// initialize mlx
	(*window)->mlx = mlx_init();
	if (!(*window)->mlx)
	{
		ft_printerror("Error: Failed to initialize mlx\n");
		return (0);
	}
	// create the window
	(*window)->win = mlx_new_window((*window)->mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (!(*window)->win)
	{
		ft_printerror("Error: Failed to create window\n");
		return (0);
	}
	return (1);
}

