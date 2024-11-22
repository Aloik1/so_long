/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:29:18 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/22 17:31:47 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_if_in_camera(t_game *game, int i, int j)
{
	ft_printf("Entering camera check\n");
	ft_printf("i -> camera y + height: %d %d\n", i, game->camera->y + game->camera->height);
	ft_printf("j -> camera x + width: %d %d\n", j, game->camera->x + game->camera->width);
	if (i < game->camera->y + game->camera->height && i < game->map->rows
		&& i > game->camera->y
		&& j < game->camera->x + game->camera->width && j < game->map->cols
		&& j > game->camera->x)
		return (1);
	return (0);
}

int	determine_enemy(t_enemies *enemies, int i, int j)
{
	if (enemies->enemy_1_y == i && enemies->enemy_1_x == j)
		return (1);
	if (enemies->enemy_2_y == i && enemies->enemy_2_x == j)
		return (2);
	if (enemies->enemy_3_y == i && enemies->enemy_3_x == j)
		return (3);
	if (enemies->enemy_4_y == i && enemies->enemy_4_x == j)
		return (4);
	if (enemies->enemy_5_y == i && enemies->enemy_5_x == j)
		return (5);
	return (0);
}

static void	update_enemies_position(t_game *game, t_enemies *enemies, int enemy_number, int i, int j)
{
	ft_printf("Entering update enemies position\n");
	ft_printf("Current camera position: %d %d\n", game->camera->y, game->camera->x);
	//ft_printf("Enemy number is %d\n", enemy_number);
	if (enemy_number == 1)
	{
		ft_printf("Enemy number is 1\n");
		game->textures->direction_1 = generate_direction(game, update_enemy(game, enemies->enemy_1_y, enemies->enemy_1_x), enemies->enemy_1_y, enemies->enemy_1_x, game->textures->direction_1);
		if (check_if_in_camera(game, i, j))
		{
			ft_printf("-------------Found enemy 1 in camera-------------\n");
			draw_enemy(game, game->textures->direction_1, game->textures->animation_1, enemies->enemy_1_y, enemies->enemy_1_x);
		}
		return ;
	}
	if (enemy_number == 2)
	{
		ft_printf("Enemy number is 2\n");
		game->textures->direction_2 = generate_direction(game, update_enemy(game, enemies->enemy_2_y, enemies->enemy_2_x), enemies->enemy_2_y, enemies->enemy_2_x, game->textures->direction_2);
		if (check_if_in_camera(game, i, j))
		{
			ft_printf("-------------Found enemy 2 in camera-------------\n");
			draw_enemy(game, game->textures->direction_2, game->textures->animation_2, enemies->enemy_2_y, enemies->enemy_2_x);
		}
		return ;
	}
	if (enemy_number == 3)
	{
		ft_printf("Enemy number is 3\n");
		game->textures->direction_3 = generate_direction(game, update_enemy(game, enemies->enemy_3_y, enemies->enemy_3_x), enemies->enemy_3_y, enemies->enemy_3_x, game->textures->direction_3);
		if (check_if_in_camera(game, i, j))
		{
			ft_printf("-------------Found enemy 3 in camera-------------\n");
			draw_enemy(game, game->textures->direction_3, game->textures->animation_3, enemies->enemy_3_y, enemies->enemy_3_x);
		}
		return ;
	}
	if (enemy_number == 4)
	{
		ft_printf("Enemy number is 4\n");
		game->textures->direction_4 = generate_direction(game, update_enemy(game, enemies->enemy_4_y, enemies->enemy_4_x), enemies->enemy_4_y, enemies->enemy_4_x, game->textures->direction_4);
		if (check_if_in_camera(game, i, j))
		{
			ft_printf("-------------Found enemy 4 in camera-------------\n");
			draw_enemy(game, game->textures->direction_4, game->textures->animation_4, enemies->enemy_4_y, enemies->enemy_4_x);
		}
		return ;
	}
	if (enemy_number == 5)
	{
		ft_printf("Enemy number is 5\n");
		game->textures->direction_5 = generate_direction(game, update_enemy(game, enemies->enemy_5_y, enemies->enemy_5_x), enemies->enemy_5_y, enemies->enemy_5_x, game->textures->direction_5);
		if (check_if_in_camera(game, i, j))
		{
			ft_printf("-------------Found enemy 5 in camera-------------\n");
			draw_enemy(game, game->textures->direction_5, game->textures->animation_5, enemies->enemy_5_y, enemies->enemy_5_x);
		}
		return ;
	}
	ft_printf("Didn't find enemy number\n");
}

void	enemies_movement(t_game *game, t_enemies *enemies)
{
	int	i;
	int	j;
	int	updated_1;
	int	updated_2;
	int	updated_3;
	int	updated_4;
	int	updated_5;
	
	updated_1 = 0;
	updated_2 = 0;
	updated_3 = 0;
	updated_4 = 0;
	updated_5 = 0;
	i = 0;//game->camera->y;
	while (i < game->map->rows)//game->camera->y + game->camera->height && i < game->map->rows)
	{
		j = 0;//game->camera->x;
		while (j < game->map->cols)//game->camera->x + game->camera->width && j < game->map->cols)
		{	
			//ft_printf("Checking row %d index %d\n", i, j);
			if (enemies->enemy_1_y == i && enemies->enemy_1_x == j 
				&& updated_1 == 0)
			{
				// ft_printf("\nFound enemy 1, updating...\n");
				// ft_printf("i is %d and j is %d\n", i, j);
				// ft_printf("Determine enemy output is %d\n", determine_enemy(enemies, i, j));
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_1++;
			}
			if (enemies->enemy_2_y == i && enemies->enemy_2_x == j 
				&& updated_2 == 0)
			{
				// ft_printf("\nFound enemy 2, updating...\n");
				// ft_printf("i is %d and j is %d\n", i, j);
				// ft_printf("Determine enemy output is %d\n", determine_enemy(enemies, i, j));
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_2++;
			}
			if (enemies->enemy_3_y == i && enemies->enemy_3_x == j
				&& updated_3 == 0)
			{
				// ft_printf("\nFound enemy 3, updating...\n");
				// ft_printf("i is %d and j is %d\n", i, j);
				// ft_printf("Determine enemy output is %d\n", determine_enemy(enemies, i, j));
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_3++;
			}
			if (enemies->enemy_4_y == i && enemies->enemy_4_x == j
				&& updated_4 == 0)
			{
				// ft_printf("\nFound enemy 4, updating...\n");
				// ft_printf("i is %d and j is %d\n", i, j);
				// ft_printf("pos y is %d and pos x is %d\n", game->enemies->enemy_4_y, game->enemies->enemy_4_x);
				// ft_printf("Determine enemy output is %d\n", determine_enemy(enemies, i, j));
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_4++;
			}
			if (enemies->enemy_5_y == i && enemies->enemy_5_x == j
				&& updated_5 == 0)
			{
				// ft_printf("\nFound enemy 5, updating...\n");
				// ft_printf("i is %d and j is %d\n", i, j);
				// ft_printf("pos y is %d and pos x is %d\n", game->enemies->enemy_5_y, game->enemies->enemy_5_x);
				// ft_printf("Determine enemy output is %d\n", determine_enemy(enemies, i, j));
				update_enemies_position(game, enemies, determine_enemy(enemies, i, j), i, j);
				updated_5++;
			}
			j++;
		}
		i++;
	}
	return ;
}
