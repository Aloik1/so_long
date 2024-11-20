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
	if (map->cols <= camera->width) {
		camera->x = 0;
	}
	if (map->rows <= camera->height) {
		camera->y = 0;
	}
}

void	update_camera(t_camera *camera, t_player *player, t_map *map)
{
	if (!camera || !player || !map) 
		return ;
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
	if (map->cols <= camera->width) 
	{
		camera->x = 0;
	}
	if (map->rows <= camera->height) 
	{
		camera->y = 0;
	}
}
