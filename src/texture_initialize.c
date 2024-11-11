/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:37:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/11 19:37:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	texture_initialize(t_textures *textures, void *mlx)
{
	textures->floor_img = mlx_xpm_file_to_image(mlx, "assets/textures/floors/floor.xpm", &textures->floor_width, &textures->floor_height);
	if (!textures->floor_img)
	{
		ft_printf("Error: Could not load floor texture.\n");
		return (0);
	}
	textures->wall_top_img = mlx_xpm_file_to_image(mlx, "assets/textures/walls/wall_general.xpm", &textures->wall_top_width, &textures->wall_top_height);
	if (!textures->wall_top_img)
	{
		ft_printf("Error: Could not load wall top texture.\n");
		return (0);
	}
	textures->collectible_1_img = mlx_xpm_file_to_image(mlx, "assets/textures/collectibles/collectible_1.xpm", &textures->collectible_1_width, &textures->collectible_1_height);
	if (!textures->collectible_1_img)
	{
		ft_printf("Error: Could not load collectible 1 texture.\n");
		return (0);
	}
	return (1);
}

