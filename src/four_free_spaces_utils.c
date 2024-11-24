/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_free_spaces_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 15:15:16 by ikondrat          #+#    #+#             */
/*   Updated: 2024-11-24 15:15:16 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	one_free_space_3(int pos_x, int pos_y, int direction)
{
	if (i == 3)
	{
		pos_x--;
		direction = direction - direction + 3;
	}
	else
	{
		pos_x++;
		direction = direction - direction + 4;
	}
	return (direction);
}
