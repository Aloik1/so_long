/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:51:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_collectible_animation(t_game *game)
{
	if (game->textures->collectible_animation_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_1);
		game->textures->collectible_animation_1 = NULL;
	}
	if (game->textures->collectible_animation_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_2);
		game->textures->collectible_animation_2 = NULL;
	}
	if (game->textures->collectible_animation_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_3);
		game->textures->collectible_animation_3 = NULL;
	}
	if (game->textures->collectible_animation_4)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_4);
		game->textures->collectible_animation_4 = NULL;
	}
	if (game->textures->collectible_animation_5)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_animation_5);
		game->textures->collectible_animation_5 = NULL;
	}
	if (game->textures->collectible_destroyed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->collectible_destroyed);
		game->textures->collectible_destroyed = NULL;
	}
}

static void	free_floors(t_game *game)
{
	if (game->textures->floor_all_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_all_open);
		game->textures->floor_all_open = NULL;
	}
	if (game->textures->floor_top_bot)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_bot);
		game->textures->floor_top_bot = NULL;
	}
	if (game->textures->floor_left_right)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_right);
		game->textures->floor_left_right = NULL;
	}
	if (game->textures->floor_top_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_open);
		game->textures->floor_top_open = NULL;
	}
	if (game->textures->floor_bot_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_open);
		game->textures->floor_bot_open = NULL;
	}
	if (game->textures->floor_left_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_open);
		game->textures->floor_left_open = NULL;
	}
	if (game->textures->floor_right_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_open);
		game->textures->floor_right_open = NULL;
	}
	if (game->textures->floor_top_right_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_right_corner);
		game->textures->floor_top_right_corner = NULL;
	}
	if (game->textures->floor_top_left_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_left_corner);
		game->textures->floor_top_left_corner = NULL;
	}
	if (game->textures->floor_bot_left_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_left_corner);
		game->textures->floor_bot_left_corner = NULL;
	}
	if (game->textures->floor_bot_right_corner)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_right_corner);
		game->textures->floor_bot_right_corner = NULL;
	}
	if (game->textures->floor_top_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_top_closed);
		game->textures->floor_top_closed = NULL;
	}
	if (game->textures->floor_bot_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_bot_closed);
		game->textures->floor_bot_closed = NULL;
	}
	if (game->textures->floor_left_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_left_closed);
		game->textures->floor_left_closed = NULL;
	}
	if (game->textures->floor_right_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->floor_right_closed);
		game->textures->floor_right_closed = NULL;
	}

}

static void	free_exit(t_game *game)
{
	if (game->textures->exit_closed)
	{
		mlx_destroy_image(game->window->mlx, game->textures->exit_closed);
		game->textures->exit_closed = NULL;
	}
	if (game->textures->exit_open)
	{
		mlx_destroy_image(game->window->mlx, game->textures->exit_open);
		game->textures->exit_open = NULL;
	}
}

static void	free_player(t_game *game)
{
	if (game->textures->player_up_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_1);
		game->textures->player_up_1 = NULL;
	}
	if (game->textures->player_up_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_2);
		game->textures->player_up_2 = NULL;
	}
	if (game->textures->player_up_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_up_3);
		game->textures->player_up_3 = NULL;
	}
	if (game->textures->player_down_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_1);
		game->textures->player_down_1 = NULL;
	}
	if (game->textures->player_down_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_2);
		game->textures->player_down_2 = NULL;
	}
	if (game->textures->player_down_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_down_3);
		game->textures->player_down_3 = NULL;
	}
	if (game->textures->player_left_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_1);
		game->textures->player_left_1 = NULL;
	}
	if (game->textures->player_left_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_2);
		game->textures->player_left_2 = NULL;
	}
	if (game->textures->player_left_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_left_3);
		game->textures->player_left_3 = NULL;
	}
	if (game->textures->player_right_1)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_1);
		game->textures->player_right_1 = NULL;
	}
	if (game->textures->player_right_2)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_2);
		game->textures->player_right_2 = NULL;
	}
	if (game->textures->player_right_3)
	{
		mlx_destroy_image(game->window->mlx, game->textures->player_right_3);
		game->textures->player_right_3 = NULL;
	}
	// if (game->player->player_texture)
	// {
	// 	mlx_destroy_image(game->window->mlx, game->player->player_texture);
	// 	game->textures->player_img = NULL;
	// }
}

void	free_textures(t_game *game)
{
	ft_printf("cleaning textures\n");
	//free_collectible_structures(game);
	free_collectible_animation(game);
	free_floors(game);
	free_exit(game);
	if (game->textures->wall_top_img)
	{
		mlx_destroy_image(game->window->mlx, game->textures->wall_top_img);
		game->textures->wall_top_img = NULL;
	}
	free_player(game);
	free(game->textures);
	game->textures = NULL;
}

int clean_exit(t_game *game)
{
	if (!game)
		exit(1);
	if (game->textures)
		free_textures(game);
	if (!game->textures)
		ft_printf("No textures are left\n");
	if (game->map)
		free_map(game->map);
	
	if (game->player)
	{
		free(game->player);
	}
	if (game->movement)
		free(game->movement);
	if (game->camera)
	{
		free(game->camera);
	}
	if (game->window)
	{
		if (game->window->win)
		{
			mlx_destroy_window(game->window->mlx, game->window->win);
			game->window->win = NULL;
		}
		if (game->window->mlx)
		{
			mlx_destroy_display(game->window->mlx);
			free(game->window->mlx);
			game->window->mlx = NULL;
		}
		free(game->window);
		game->window = NULL;
		
	}
	free(game->window);
	game->window = NULL;
	ft_printf("game window pointer: %p\n", game->window);
	free(game);
	game = NULL;
	exit(0);
	return (0);
}