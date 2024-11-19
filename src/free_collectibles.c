/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:13:22 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/19 22:02:53 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_collectible_1(t_game *game)
{
	if (game->textures->collectible_1)
	{
		// ft_printf("collectible 1 position pointer is: %p\n", game->textures->collectible_1->position);
		// if (game->textures->collectible_1->position)
		// {
		// 	ft_printf("Freeing collectible 1 position");
		// 	// free(game->textures->collectible_1->position);
		// }
		// ft_printf("collectible 1 position pointer is: %p\n", game->textures->collectible_1->position);
		if (game->textures->collectible_1->collectible_img)
			mlx_destroy_image(game->window->mlx, game->textures->collectible_1->collectible_img);
		free (game->textures->collectible_1);
		game->textures->collectible_1 = NULL;
		
	}
}

void	free_collectible_2(t_game *game)
{
	if (game->textures->collectible_2)
	{
		// if (game->textures->collectible_2->position)
		// 	free(game->textures->collectible_2->position);
		// game->textures->collectible_2->position = '\0';
		ft_printf("collectible 2 position pointer is: %p\n", game->textures->collectible_2->position);
		if (game->textures->collectible_2->collectible_img)
			mlx_destroy_image(game->window->mlx, game->textures->collectible_2->collectible_img);
		free (game->textures->collectible_2);
		game->textures->collectible_2 = NULL;
	}
}

void	free_collectible_3(t_game *game)
{
	if (game->textures->collectible_3)
	{
		// if (game->textures->collectible_3->position)
		// 	free(game->textures->collectible_3->position);
		// game->textures->collectible_3->position = '\0';
		//ft_printf("collectible 3 position pointer is: %p\n", game->textures->collectible_1->position);
		if (game->textures->collectible_3->collectible_img)
			mlx_destroy_image(game->window->mlx, game->textures->collectible_3->collectible_img);
		free (game->textures->collectible_3);
		game->textures->collectible_3 = NULL;
	}
}

void	free_collectible_4(t_game *game)
{
	if (game->textures->collectible_4)
	{
		// if (game->textures->collectible_4->position)
		// 	free(game->textures->collectible_4->position);
		// game->textures->collectible_4->position = '\0';
		// ft_printf("collectible 4 position pointer is: %p\n", game->textures->collectible_4->position);
		if (game->textures->collectible_4->collectible_img)
			mlx_destroy_image(game->window->mlx, game->textures->collectible_4->collectible_img);
		free (game->textures->collectible_4);
		game->textures->collectible_4 = NULL;
	}
}

void	free_collectible_5(t_game *game)
{
	if (game->textures->collectible_5)
	{
		// if (game->textures->collectible_5->position)
		// 	free(game->textures->collectible_5->position);
		// game->textures->collectible_5->position = '\0';
		// ft_printf("collectible 1 position pointer is: %p\n", game->textures->collectible_5->position);
		if (game->textures->collectible_5->collectible_img)
			mlx_destroy_image(game->window->mlx, game->textures->collectible_5->collectible_img);
		free (game->textures->collectible_5);
		game->textures->collectible_5 = NULL;
	}
}
