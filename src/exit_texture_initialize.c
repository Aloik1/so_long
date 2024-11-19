/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_texture_initialize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:40 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 17:22:02 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_initialize(t_game *game, void *mlx)
{
	game->textures->exit_open = mlx_xpm_file_to_image(mlx, "assets/textures/exit/exit_open.xpm", &game->textures->exit_width, &game->textures->exit_height);
	if (!game->textures->exit_open)
	{
		ft_printf("Error: Could not load exit open texture.\n");
		return (0);
	}
	game->textures->exit_closed = mlx_xpm_file_to_image(mlx, "assets/textures/exit/exit_closed.xpm", &game->textures->exit_width, &game->textures->exit_height);
	if (!game->textures->exit_closed)
	{
		ft_printf("Error: Could not load exit closed texture.\n");
		return (0);
	}
	return (1);
}
