/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:25:22 by marvin            #+#    #+#             */
/*   Updated: 2024/11/04 19:25:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_window	*window;
	t_map		*map;

	map = NULL;
	window = NULL;
	if (!basic_check(argc, argv))
		return (1);
	if (!read_map(argv[1], &map))
		return (1);
	if (map->rows == 0 || map->cols == 0 || map->collectibles == 0 
		|| map->exits == 0 || map->players == 0)
	{
		ft_printerror("Error: Invalid map\n");
		free_map(map);
		return (1);
	}
	if (!path_checks(map))
	{
		ft_printerror("Error: Invalid path, can't reach all collectibles or exit\n");
		free_map(map);
		return (1);
	}
	if (!window_and_mlx(&window))
		return (1);
	// start the loop
	mlx_loop(window->mlx);
	return (0);
}

