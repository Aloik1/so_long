/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:56:16 by marvin            #+#    #+#             */
/*   Updated: 2024/11/08 15:56:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

extern t_textures	textures;

void	camera_init(t_camera *camera, t_player *player, t_map *map)
{
	camera->width = WIN_WIDTH / TILE_SIZE;
	camera->height = WIN_HEIGHT / TILE_SIZE;
	camera->x = player->position.x - camera->width / 2;
	camera->y = player->position.y - camera->height / 2;

	// Ensure the camera doesn't go out of bounds
	if (camera->x < 0) {
		camera->x = 0;
	}
	if (camera->y < 0) {
		camera->y = 0;
	}
	if (camera->x + camera->width > map->cols) {
		camera->x = map->cols - camera->width;
	}
	if (camera->y + camera->height > map->rows) {
		camera->y = map->rows - camera->height;
	}

	// Handle small maps
	if (map->cols <= camera->width) {
		camera->x = 0;
	}
	if (map->rows <= camera->height) {
		camera->y = 0;
	}

	ft_printf("Camera initialized at (%d, %d) with size (%d, %d)\n", camera->x, camera->y, camera->width, camera->height);
	ft_printf("Player position: (%d, %d)\n", player->position.x, player->position.y);
}

void	update_camera(t_camera *camera, t_player *player, t_map *map)
{
	if (!camera || !player || !map) 
	{
		ft_printf("Error: Null pointer detected in update_camera\n");
		return;
	}

	// Center the camera on the player
	camera->x = player->position.x - camera->width / 2;
	camera->y = player->position.y - camera->height / 2;

	if (camera->x < 0)
		camera->x = 0;
	if (camera->y < 0)
		camera->y = 0;
	if (camera->x + camera->width > map->cols)
		camera->x = map->cols - camera->width;
	if (camera->y + camera->height > map->rows)
		camera->y = map->rows - camera->height;
	// Handle small maps
	if (map->cols <= camera->width) 
	{
		camera->x = 0;
	}
	if (map->rows <= camera->height) 
	{
		camera->y = 0;
	}
	ft_printf("Camera updated to (%d, %d)\n", camera->x, camera->y);
}
